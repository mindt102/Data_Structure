#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

bool IsEmpty()
{
    if (front == NULL && rear == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Enqueue(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if (IsEmpty())
    {
        front = rear = temp;
        return;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void Dequeue()
{
    struct Node *temp = front;
    if (IsEmpty())
    {
        printf("Queue is empty, nothing to dequeue. \n");
        return;
    }
    else if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
    }
    free(temp);
}

void PrintQueue()
{
    if (!IsEmpty())
    {
        struct Node *temp = front;
        printf("Queue is: ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    Enqueue(2);
    PrintQueue();
    Enqueue(4);
    PrintQueue();
    Dequeue();
    PrintQueue();
    Dequeue();
    PrintQueue();
    Dequeue();
    PrintQueue();
    return 0;
}