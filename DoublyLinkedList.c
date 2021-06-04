#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head;

struct Node *GetNewNode(int x)
{
    /*Create new node using struct node => Using memory in stack
    => local node will be deleted => Wrong*/
    // struct Node newNode;
    // newNode.data = x;
    // newNode.next = NULL;
    // newNode.prev = NULL;
    // return &newNode

    // Create new node using pointer => Using memory in head
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void Print()
{
    struct Node *temp = head;
    printf("Forward: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return;
}

void ReversePrint()
{
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Backward: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
    return;
}

void InsertAtHead(int x)
{
    struct Node *newNode = GetNewNode(x);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    return;
}

void InsertAtTail(int x)
{
    struct Node *newNode = GetNewNode(x), *tail = head;
    if (tail == NULL)
    {
        head = newNode;
        return;
    }
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->prev = tail;
    return;
}

int main()
{
    head = NULL;
    InsertAtTail(2);
    Print();
    ReversePrint();
    InsertAtHead(4);
    Print();
    ReversePrint();
    InsertAtTail(6);
    Print();
    ReversePrint();
    return 0;
}