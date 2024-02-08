#include <stdio.h>
#include <stdlib.h>
struct Node
{
    char data;
    struct Node *next;
};
void printBoard(struct Node *head);
int checkWin(struct Node *head);
struct Node *createNode(char data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int main()

{
    int player = 1, input, status = -1;
    struct Node *head = NULL;
    struct Node *t = NULL;
    // Initialize the linked list with empty cells
    for (int i = 0; i < 9; i++)
    {
        if (head == NULL)
        {
            head = createNode('0' + i + 1);
            t = head;
        }
        else
        {
            t->next = createNode('0' + i + 1);
            t = t->next;
        }
    }
    printBoard(head);
    while (status == -1)
    {
        player = (player % 2 == 0) ? 2 : 1;
        char mark = (player == 1) ? 'X' : 'O';
        printf("Please enter Number For Player %d\n", player);
        scanf("%d", &input);
        if (input < 1 || input > 9)
        {
            printf("Invalid input\n");
            continue;
        }
        // Find and update the corresponding node in the linked list
        t = head;
        while (t != NULL)
        {
            if (t->data == ('0' + input))
            {
                t->data = mark;
                break;
            }
            t = t->next;
        }
        printBoard(head);
        int result = checkWin(head);
        if (result == 1)
        {
            printf("Player %d is the Winner\n", player);
            return 0;
        }
        else if (result == 0)
        {
            printf("Draw\n");
            return 0;
        }
        player++;
    }
    return 0;
}
void printBoard(struct Node *head)
{
    printf("\n\n");
    printf("=== TIC TAC TOE ===\n\n");
    struct Node *t = head;
    for (int i = 0; i < 3; i++)
    {
        printf(" | | |\n");
        printf(" %c | %c | %c | \n", t->data, t->next->data, t->next->next->data);
        printf("_____ _____ _____\n");
        t = t->next->next->next;
    }
    printf("\n\n");
}
int checkWin(struct Node *head)
{
    char board[10];
    struct Node *t = head;
    // Copy the linked list data into an array for easier checking
    for (int j = 1; j <= 9; j++)
    {
        board[j] = t->data;
        t = t->next;
    }
    // Check rows, columns, and diagonals for a win
    int i;
    if (board[1] == board[2] && board[2] == board[3])
    {
        return 1;
    }
    if (board[1] == board[4] && board[4] == board[7])
    {
        return 1;
    }
    if (board[7] == board[8] && board[8] == board[9])
    {
        return 1;
    }
    if (board[3] == board[6] && board[6] == board[9])
    {
        return 1;
    }
    if (board[1] == board[5] && board[5] == board[9])
    {
        return 1;
    }
    if (board[3] == board[5] && board[5] == board[7])
    {
        return 1;
    }
    if (board[2] == board[5] && board[5] == board[8])
    {
        return 1;
    }
    if (board[4] == board[5] && board[5] == board[6])
    {
        return 1;
    }
    int count = 0;
    for (i = 1; i <= 9; i++)
    {
        if (board[i] == 'X' || board[i] == 'O')
        {
            count++;
        }
    }
    if (count == 9)
    {
        return 0;
    }
    return -1;
}