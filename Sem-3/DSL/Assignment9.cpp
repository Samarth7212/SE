/*
    Samarth (21142 F1-batch)
    DSL Assignment-9

    Problem Statement:
    In any language program mostly syntax error occurs due to unbalancing delimiter such as
    (),{},[]. Write C++ program using stack to check whether given expression is well
    parenthesized or not.

*/

#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    char *arr;
    int sz = 0;
    int top = -1;
    char opRound = '(', clRound = ')', opSqr = '[', clSqr = ']', opCurl = '{', clCurl = '}';

public:
    Stack();                                     // Default constructor.
    Stack(string &);                             // Parameterized constructor to inititlize operation.
    ~Stack() { delete[] arr; }                   // De-allocating given memory.
    void push(char x) { arr[++top] = x; }        // To push an element into stack.
    void pop() { arr[top--] = ' '; }             // To remove topmost element.
    bool isEmpty() { return top == -1 ? 1 : 0; } // To check if stack is empty.
    char stackTop() { return arr[top]; }         // To get top most element of stack.
    bool validateString(string &);               // Check if string contains only delimiters.
} * obj;

bool Stack::validateString(string &s)
{
    for (auto &ch : s)
    {
        if (ch != opRound && ch != opRound && ch != clRound && ch != opCurl && ch != clCurl && ch != opSqr && ch != clSqr)
        {
            cout << "\nString is invalid.";
            return 0;
        }
    }
    return 1;
}

Stack::Stack(string &s)
{
    if (!validateString(s))
        return;
    sz = s.size();
    arr = new char[sz];
    for (int i = 0; i < sz; i++)
    {
        if (s[i] == opRound || s[i] == opCurl || s[i] == opSqr)
        {
            cout << "Pushed " << s[i] << endl;
            push(s[i]);
        }
        else if (s[i] == clRound)
        {
            char tp = stackTop();
            if (stackTop() == opRound)
            {
                cout << "popped " << stackTop() << endl;
                pop();
            }
            else
            {
                cout << "Could not find matching opening bracket for " << s[i] << endl;
                cout << "\nThis is invalid expression!!!";
                return;
            }
        }
        else if (s[i] == clCurl)
        {
            if (stackTop() == opCurl)
            {
                cout << "popped " << stackTop() << endl;
                pop();
            }
            else
            {
                cout << "Could not find matching opening bracket for " << s[i] << endl;
                cout << "\nThis is invalid expression!!!";
                return;
            }
        }
        else if (s[i] == clSqr)
        {
            if (stackTop() == opSqr)
            {
                cout << "popped " << stackTop() << endl;
                pop();
            }
               
            else
            {
                cout << "Could not find matching opening bracket for " << s[i] << endl;
                cout << "\nThis is invalid expression!!!";
                return;
            }
        }
    }
    if (isEmpty())
        cout << "\nExpression is correct!!!\n"
             << s << " is well parenthesized.\n";
    else
        cout << "\nInvalid expression.\n";
}

int main()
{
    while (1)
    {
        string s;
        cout << "\nEnter the string (Enter -1 to exit): ";
        cin >> s;
        if (s == "-1")
            break;
        obj = new Stack(s);
        delete obj;
    }
    cout << "\nTHANK YOU!!!";
    return 0;
}
