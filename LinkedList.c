#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head; // global variable, can be accessed anywhere

void Insert(int data, int n) // Insert a node at n-th position
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    if (n == 1)
    {
        temp->next = head;
        head = temp;
        return;
    }

    struct Node *prevNode = head;
    for (int i = 0; i < n - 2; i++)
    {
        prevNode = prevNode->next;
    }
    temp->next = prevNode->next;
    prevNode->next = temp;
};

void Print() //Print all elements in the list
{
    struct Node *temp = head;
    printf("List is: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
};

void Delete(int n) // Delete note at the n-th position
{
    struct Node *temp = head;
    if (n == 1)
    {
        head = head->next;
    }
    else
    {
        struct Node *prevNode = (struct Node *)malloc(sizeof(struct Node));
        prevNode = head;
        for (int i = 0; i < n - 2; i++)
        {
            prevNode = prevNode->next;
        }
        temp = prevNode->next;
        prevNode->next = prevNode->next->next;
    }
    free(temp);
}

int main()
{
    head = NULL; // empty list
    // printf("How many numbers do you want to insert: ");
    // int n;
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++)
    // {
    //     printf("Enter the number: ");
    //     int x;
    //     scanf("%d", &x);
    //     Insert(x);
    //     Print();
    // }

    Insert(2, 1); // List: 2
    Insert(3, 2); // List: 2 3
    Insert(4, 1); // List: 4 2 3
    Insert(5, 2); // List: 4 5 2 3
    Print();
    int n;
    printf("Enter a position: ");
    scanf("%d", &n);
    Delete(n);
    Print();
    return 0;
}