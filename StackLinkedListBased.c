#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *top = NULL;

void Push(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->link = top;
    top = newNode;
    return;
}

void Pop()
{
    if (top == NULL)
    {
        printf("Error: No element to pop");
        return;
    }
    struct Node *temp = top;
    top = top->link;
    free(temp);
    return;
}

void Print()
{
    struct Node *temp = top;
    printf("Stack: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main()
{
    Push(2);
    Print();
    Push(5);
    Print();
    Push(10);
    Print();
    Pop();
    Print();
    Push(12);
    Print();
    return 0;
}