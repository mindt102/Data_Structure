#include <iostream>
#include <stack> // Stack from standard template library (STL)
#include <cstring>
using namespace std;

/* Example of Stack implementation in cpp. This program will use
stack from standard template library fron cpp*/
// class Stack
// {
//     private:
//         char A[101];length
//         int top;
//     public:
//         void Push(int x);
//         void Pop();
//         int Top();
//         bool IsEmpty();
// }

void Reverse(char *C, int n)
{
    stack<char> S;

    // Loop for push
    for (int i = 0; i < n; i++)
    {
        S.push(C[i]);
    }

    // Loop for pop
    for (int i = 0; i < n; i++)
    {
        C[i] = S.top(); // Overwrite character at index i
        S.pop();        // Perform pop
    }
}

int main()
{
    char C[51];
    cout << "Enter a string: ";
    cin >> C;
    Reverse(C, strlen(C));
    cout << "Output: " << C;
    return 0;
}