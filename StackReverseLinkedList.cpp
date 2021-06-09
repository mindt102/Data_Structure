#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void Insert(int x)
{
    struct Node *temp = new Node;
    temp->data = x;
    temp->next = head;
    head = temp;
}

void Print()
{
    struct Node *temp = head;
    cout << "Linked List: ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void ReverseUsingStack()
{
    stack<struct Node *> S;
    if (head == nullptr)
    {
        return;
    }
    struct Node *temp = head;

    while (temp != nullptr)
    {
        S.push(temp);
        temp = temp->next;
    }

    temp = S.top();
    head = temp;
    S.pop();
    while (!S.empty())
    {
        temp->next = S.top();
        temp = temp->next;
        S.pop();
    }
    temp->next = nullptr;
}

int main()
{
    head = nullptr;

    Insert(1);
    Insert(5);
    Insert(7);
    Insert(2);
    Insert(4);
    Print();
    ReverseUsingStack();
    Print();
    return 0;
}