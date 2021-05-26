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

void Reverse()
{
    struct Node *prevNode = NULL;
    struct Node *currentNode = head;
    struct Node *nextNode;
    while (currentNode != NULL)
    {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    };
    head = prevNode;
}

void PrintRecursive(struct Node *p)
{
    if (p == NULL)
    {
        printf("\n");
        return;
    }
    printf("%d ", p->data);
    PrintRecursive(p->next);
}

void PrintReverseRecursive(struct Node *p)
{
    // DIY
    // if (p == head)
    //     return;
    // struct Node *preTail = head;
    // while (preTail->next != p)
    // {
    //     preTail = preTail->next;
    // }
    // printf("%d ", preTail->data);
    // ReversePrint(preTail);

    if (p == NULL)
    {
        return;
    }
    PrintReverseRecursive(p->next);
    printf("%d ", p->data);
}

int main()
{
    head = NULL;

    Insert(2, 1); // List: 2
    Insert(3, 2); // List: 2 3
    Insert(4, 1); // List: 4 2 3
    Insert(5, 2); // List: 4 5 2 3
    Print();
    printf("Print list using recursive function: ");
    PrintRecursive(head);
    printf("Print reverse list using recursive function: ");
    PrintReverseRecursive(head);
    Print();
    return 0;
}