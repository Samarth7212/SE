/*
    Samarth (21142 F1-batch)
    DSL Assignment-11

    Queues  are  frequently  used  in  computer  programming,  and  a  typical  example  is
    the creation  of  a  job  queue  by  an  operating  system.  If  the  operating  system
    does  not  use priorities,  then  the  jobs  are  processed  in  the  order  they  enter
    the  system.  Write  C++ program for simulating job queue. Write functions to add job
    and delete job from queue.
*/
#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    string *arr;
    int front = -1, back = -1, len = 0;

public:
    ~Queue() { delete[] arr; }
    Queue(int sz)
    {
        arr = new string[sz];
        this->len = sz;
    }
    void addJob();
    void deleteJob();
    void display();
    bool checkDuplicate(string &s);
} * q;

bool Queue::checkDuplicate(string &s)
{
    for (int i = 0; i <= back; i++)
    {
        if (arr[i] == s)
            return 1;
    }
    return 0;
}

void Queue::addJob()
{
    string s;
    cout << "Enter Job ID (Integer Only): ";
    cin >> s;
    if (checkDuplicate(s))
    {
        cout << "\nJOB IDs CANNOT BE REPETITIVE.";
        return;
    }
    if (back + 1 == len)
    {
        cout << "\nQUEUE IS FULL!!!";
        return;
    }
    arr[++back] = s;
    if (front == -1)
        front++;
    cout << "\nJOB ADDED TO QUEUE.";
}

void Queue::deleteJob()
{
    for (int j = 0; j < back; j++)
        arr[j] = arr[j + 1];
    back--;
    cout << "\nJOB DELETED.";
    return;
}

void Queue::display()
{
    cout << endl;
    for (int i = 0; i <= back; i++)
        cout << i + 1 << ") " << arr[i] << endl;
}

int main()
{
    int sz, ch;
    cout << "\nEnter the size of queue: ";
    cin >> sz;
    q = new Queue(sz);
    while (1)
    {
        cout << "\n\nMENU\n1.Add a new job in queue.\n2.Delete job from que\n3.Display queue of job.\nEnter your choice(Enter -1 to exit): ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            q->addJob();
            break;

        case 2:
            q->deleteJob();
            break;

        case 3:
            q->display();
            break;

        case -1:
            abort();
            break;

        default:
            break;
        }
    }

    return 0;
}