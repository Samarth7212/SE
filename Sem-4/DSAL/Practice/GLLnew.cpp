#include <bits/stdc++.h>
using namespace std;

// int returnNumber(string s)
int returnNumber(char s)
{
    // int p = 0, res = 0;
    // for (int i = s.length() - 1; i >= 0; i--, p++)
    // {
    //     res += (s[i] - '0') * pow(10, p);
    // }
    // return res;
    return s - '0';
}

class Node
{
public:
    Node *next;
    union Value
    {
        int data;
        Node *link;
    } value;
    Node() {}
};

class Gll
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *tmp = NULL;

public:
    Gll() {}
    Gll(string s);
};

Gll::Gll(string s)
{
    Node *p;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            tmp = new Node;
            tmp->next = NULL;

            while (s[i] != ')')
            {
                if (s[i] == ',')
                    continue;
            }
        }
        else
        {
            // Append to LL
            if (head == NULL)
            {
                head = new Node;
                head->next = tail;
                tmp = head;
            }
            else
            {
                tmp = new Node;
                tail->next = tmp;
                tail = tmp;
            }
            tmp->value.data = returnNumber(s[i]);
        }
    }
}

int main()
{
    Gll *gll;
    string s;
    while (1)
    {
        cout << "Enter list using round brackets(-1 to exit): ";
        cin >> s;
        if (s == "-1")
            break;
        gll = new Gll(s);
    }
    return 0;
}
