#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *next;
    union Value
    {
        int data;
        Node *link;
    } value;
    Node(){}
} *head = NULL, *tail = NULL, *tmp = NULL;

int main()
{
    int menuChoice = 0;
    bool menu = 1;
    int data;

    while (menu)
    {
        int ch;
        cout
            << "\nPress 1 to enter data\nPress 2 to enter a linked list\nCHOICE: ";
        cin >> ch;

        if (head == NULL)
        {
            head = new Node;

            head->next = NULL;
            tail = head;
            tmp = head;
        }
        else
        {
            tmp = new Node;

            tail->next = tmp;
            tail = tmp;
        }

        if (ch == 1)
        {
            cout << "ENTER DATA; ";
            cin >> data;
            tmp->value.data = data;
        }
        else if (ch == 2)
        {
            Node *localhead = NULL, *localTmp = NULL, *localTail = NULL;
            int localData = 0;

            cout << "KEEP ENTERING DATA(-1 to exit): ";

            while (localData != -1)
            {
                cin >> localData;

                if (localData == -1)
                    continue;

                if (localhead == NULL)
                {
                    localhead = new Node;
                    localhead->value.data = localData;
                    localTail = localhead;
                }
                else
                {
                    localTmp = new Node;
                    localTmp->value.data = localData;
                    localTail->next = localTmp;
                    localTail = localTmp;
                }
            }
            tmp->value.link = localhead;
        }
        else if (ch == 3)
        {
            Node *p = head;
            while (p != tail)
            {

                p = p->next;
            }
        }
        else if (ch == 4)
        {
            Node *currentHead, *current, *currentTail;
            char c;
            cout << "\nDO you want to start subList? (y/n)";
            cin >> c;
            if (c == 'y')
            {
                
            }
            else
            {
            }
        }
        else if (ch == -1)
            menu = 0;
    }

    return 0;
}