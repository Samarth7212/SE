/*
    Samarth (21142 F1-batch)
    DSL Assignment-10

    Problem Statement:
    Implement  C++  program  for  expression  conversion  as  infix  to  postfix  and  its  evaluation
    using stack based on given conditions:
    1. Operands and operator, both must be single character.
    2. Input Postfix expression must be in a desired format.
    3. Only '+', '-', '*' and '/ ' operators are expected.
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack
{
public:
    T *arr;
    int top = -1;
    char stackTop() { return arr[top]; }         // To get top most element of stack.
    void push(T x) { arr[++top] = x; }           // To push an element into stack.
    T pop() { return arr[top--]; }               // To remove topmost element.
    bool isEmpty() { return top == -1 ? 1 : 0; } // To check if stack is empty.
};

int checkPre(char c)
{
    if (c == '/' || c == '*')
        return 3;
    else if (c == '+' || c == '-')
        return 2;
    else
        return 1;
}

float evaluate(float num1, float num2, char x)
{
    switch (x)
    {
    case '+':
        return num1 + num2;
        break;

    case '-':
        return num1 - num2;
        break;

    case '/':
        return num1 / num2;
        break;

    case '*':
        return num1 * num2;
        break;

    default:
        break;
    }
    return 0;
}

int main()
{
    while (1)
    {
        string exp, tmp;
        cout << "\nENTER EXPRESSION(press -1 to exit): ";
        getline(cin, exp);
        if (exp == "-1")
            break;
        Stack<char> operatorStack; // Stack to store operators.
        Stack<float> operandStack; // Stack to store operands.
        float result = 0;

        // Stack array inititalized
        operatorStack.arr = new char[exp.length()];
        operandStack.arr = new float[exp.length()];
        tmp = exp;
        for (auto ch : exp)
        {
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
            {
                cout << ch;
                operandStack.push(ch);
            }
            else
            {
                while (!operatorStack.isEmpty() && checkPre(ch) <= checkPre(operatorStack.stackTop()))
                {
                    float a, b;
                    a = operandStack.pop() - '0';
                    b = operandStack.pop() - '0';
                    float result1 = evaluate(a, b, operatorStack.stackTop());
                    operandStack.push(result1 + '0');
                    cout << operatorStack.stackTop();
                    operatorStack.pop();
                }
                operatorStack.push(ch);
            }
        }
        while (!operatorStack.isEmpty())
        {
            float a, b;
            b = operandStack.pop() - '0';
            a = operandStack.pop() - '0';
            float result1 = evaluate(a, b, operatorStack.stackTop());
            operandStack.push(result1 + '0');
            cout << operatorStack.stackTop();
            operatorStack.pop();
        }
        cout << endl
             << tmp << " = " << operandStack.pop() - '0';
    }
    return 0;
}