#include <stdio.h>
#include <stdbool.h>
#define SIZE 10
// const int SIZE = 10;
int A[SIZE];
int front = -1;
int rear = -1;

bool IsEmpty()
{
    if (front == -1 && rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsFull()
{
    if ((rear + 1) % SIZE == front)
    {
        printf("Queue if full!\n");
        return true;
    }
    else
    {
        return false;
    }
}

void Enqueue(int x)
{
    if (IsFull())
    {
        return;
    }
    else if (IsEmpty())
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % SIZE;
    }
    A[rear] = x;
}

void Dequeue()
{
    if (IsEmpty())
    {
        printf("Queue is empty");
        return;
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

int Front()
{
    return A[front];
}

void PrintQueue()
{
    if (!IsEmpty())
    {
        printf("Queue is: ");
        int i = front;
        while (i != rear)
        {
            printf("%d ", A[i]);
            i = (i + 1) % SIZE;
        }
        printf("%d \n", A[rear]);
    }
}

int main()
{
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);

    PrintQueue();
    Dequeue();
    PrintQueue();
    return 0;
}
