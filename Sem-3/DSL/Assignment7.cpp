/*
    Samarth (21142 F1-batch)
    DSL Assignment-7

    Problem Statement:
    Write C++ program for storing binary number using doubly linked lists. Write functions- 
    a) To compute 1‘s and 2‘s complement  
    b) Add two binary numbers 
*/

#include <bits/stdc++.h>
using namespace std;

class BinaryOperations;

class Node //Each object of this class is a Node, carrying data and pointers of its own type.
{
    int data;
    Node *next, *prev;
    friend class BinaryOperations;

public:
    Node() { next = prev = NULL; } //Setting default values.
};

class BinaryOperations
{
    bool isFirst1 = 1, isFirst2 = 1;
    string add;
    Node *lsb1, *msb1, *lsb2, *msb2, *tmp;
    long long num1, num2;

public:
    void deleteNodes(); //Delete all nodes before exiting.
    void takeInput();   //Take input and form a linked list.
    void addition();    //Add two numbers
    void onesComp();    //Perform one's complement.
    void twosComp();    //Perform one's complement.
};

void BinaryOperations::takeInput()
{
    cout << "Enter num-1: ";
    cin >> num1;
    cout << "Enter num-2: ";
    cin >> num2;
    long long n1 = num1;
    long long n2 = num2;

    while (n1 != 0)
    {
        if (isFirst1)
        {
            isFirst1 = 0;
            lsb1 = new Node;
            lsb1->data = n1 % 10;
            lsb1->next = msb1;
            lsb1->prev = lsb1;
            msb1 = lsb1;
            if (n1 == 0)
                break;
            else
                n1 /= 10;
        }
        else
        {
            tmp = new Node;
            tmp->data = n1 % 10;
            tmp->next = msb1;
            msb1->prev = tmp;
            tmp->prev = lsb1;
            lsb1->next = tmp;
            msb1 = tmp;
            if (n1 == 0)
                break;
            else
                n1 /= 10;
        }
    }
    while (n2 != 0)
    {
        if (isFirst2)
        {
            isFirst2 = 0;
            lsb2 = new Node;
            lsb2->data = n2 % 10;
            lsb2->next = msb2;
            lsb2->prev = lsb2;
            msb2 = lsb2;
            n2 /= 10;
        }
        else
        {
            tmp = new Node;
            tmp->data = n2 % 10;
            tmp->next = msb2;
            msb2->prev = tmp;
            tmp->prev = lsb2;
            lsb2->next = tmp;
            msb2 = tmp;
            n2 /= 10;
        }
    }
}

void BinaryOperations::onesComp()
{
    tmp = msb1;
    bool c = 1;
    cout << "The ones complement of num1 is: ";
    while (tmp->next != msb1->next || c)
    {
        c = 0;
        cout << !(tmp->data);
        tmp->data = !(tmp->data);
        tmp = tmp->next;
    }

    cout << endl;
    c = 1;
    tmp = msb2;
    cout << "The ones complement of num2 is: ";
    while (tmp->next != msb2->next || c)
    {
        c = 0;
        cout << !(tmp->data);
        tmp->data = !(tmp->data);
        tmp = tmp->next;
    }
    cout << endl;
}

void BinaryOperations::addition()
{
    Node *p = lsb1;
    Node *q = lsb2;
    bool carry = 0;
    do
    {
        if (p->data && q->data) //p=1 q=1
        {
            if (carry) //carry=1
            {
                add += '1';
                carry = 1;
            }
            else //carry=0
            {
                add += '0';
                carry = 1;
            }
        }
        else if (p->data || q->data) //p=0 OR q=0
        {
            if (carry) //carry=1
            {
                add += '0';
                carry = 1;
            }
            else //carry=0
            {
                add += '1';
            }
        }
        else if (!(p->data || q->data)) //p=q=0;
        {
            if (carry) //carry=1
            {
                add += '1';
                carry = 0;
            }
            else //carry=0
            {
                add += '0';
            }
        }
        //Moving ahead.
        p = p->prev;
        q = q->prev;
    } while (p != lsb1 && q != lsb1);

    if (carry) //if carry is present on last iteration.
        add += '1';
    reverse(add.begin(), add.end()); //Reversing the string.
    cout << "The addition is: " << add << endl;
}

void BinaryOperations::twosComp()
{

    onesComp();     //Performing one's complement first.
    bool carry = 1; //This '1' will be added to number.
    tmp = lsb1;
    bool c = 1;
    while (tmp != lsb1 || c)
    {
        c = 0;
        if (tmp->data == 1 && carry == 1)
        {
            tmp->data = 0;
            carry = 1;
        }
        else if (tmp->data == 0 && carry == 1)
        {
            tmp->data = 1;
            carry = 0;
        }
        else if (carry == 0)
            break;

        tmp = tmp->prev;
    }

    c = 1;
    carry = 1;
    tmp = lsb2;
    while (tmp != lsb2 || c)
    {
        c = 0;
        if (tmp->data == 1 && carry == 1)
        {
            tmp->data = 0;
            carry = 1;
        }
        else if (tmp->data == 0 && carry == 1)
        {
            tmp->data = 1;
            carry = 0;
        }
        else if (carry == 0)
            break;

        tmp = tmp->prev;
    }

    //Outputting the numbers.
    cout << "\nTwo's complement of num-1 is: ";
    tmp = msb1;
    do
    {
        cout << tmp->data;
        tmp = tmp->next;
    } while (tmp != msb1);
    cout << endl;

    cout << "\nTwo's complement of num-2 is: ";
    tmp = msb2;
    do
    {
        cout << tmp->data;
        tmp = tmp->next;
    } while (tmp != msb2);
    cout << endl;
}

void BinaryOperations::deleteNodes()
{
    Node *p = msb1;
    Node *q = p->next;
    if (p == NULL && q == NULL)
        return;

    while (q != msb1)
    {
        delete p;
        p = q;
        q = q->next;
    }
    delete p;

    p = msb2;
    q = p->next;
    while (q != msb2)
    {
        delete p;
        p = q;
        q = q->next;
    }
    delete p;
}

int main()
{
    int ch;
    BinaryOperations *obj;
    while (1)
    {
        cout << "\nMENU\n1.Ones complement\n2.Two's complement.\n3.Addition\n4.EXIT.\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {

        case 1:
            obj = new BinaryOperations();
            obj->takeInput();
            obj->onesComp();
            obj->deleteNodes();
            delete obj;
            break;

        case 2:
            obj = new BinaryOperations();
            obj->takeInput();
            obj->twosComp();
            obj->deleteNodes();
            delete obj;
            break;

        case 3:
            obj = new BinaryOperations();
            obj->takeInput();
            obj->addition();
            obj->deleteNodes();
            delete obj;
            break;

        case 4:
            cout << "\n\nThank you!!!";
            abort();
            break;

        default:
            cout << "\nInavalid choice!!! Please enter correct choice.";
            break;
        }
    }
    return 0;
}
