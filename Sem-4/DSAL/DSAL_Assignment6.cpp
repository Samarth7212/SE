/*
    Samarth Kamble
    21142 (F1-Batch)
    Date of start: 18/04/22
    Date of completion: 21/04/22

    Problem Statement:
    Represent a given graph using adjacency list to perform DFS and BFS. Use the map
    of the area around the college as the graph. Identify the prominent landmarks as
    nodes and perform DFS and BFS on that.
*/

#include <iostream>
#define sp " "
using namespace std;

class Node
{

public:
    int data;
    string name;
    Node *next;
    Node()
    {
        data = -1;
        name = "";
        next = nullptr;
    }
    Node(int x)
    {
        data = x;
        name = "";
        next = nullptr;
    }
    Node(int x, string str)
    {
        data = x;
        name = str;
        next = nullptr;
    }
};

class Stack
{
public:
    class stackNode
    {
        int data;
        stackNode *next;

    public:
        friend class Stack;
        stackNode() { next = nullptr; }
        stackNode(int x)
        {
            data = x;
            next = nullptr;
        }
    };

private:
    stackNode *top;

public:
    Stack() { top = nullptr; }
    void push(int x)
    {
        stackNode *temp = new stackNode(x);
        if (top == nullptr)
        {
            top = temp;
            return;
        }
        temp->next = top;
        top = temp;
    }

    void pop()
    {
        stackNode *temp = top;
        top = top->next;
        delete temp;
        temp = nullptr;
    }

    int stackTop() { return ((top != nullptr) ? top->data : -1); }

    bool isEmpty() { return (top == nullptr ? 1 : 0); }
};

class Queue
{
public:
    class qNode
    {
    private:
        int data;
        qNode *next;

    public:
        friend class Queue;
        qNode()
        {
            data = -1;
            next = nullptr;
        }
        qNode(int x)
        {
            data = x;
            next = nullptr;
        }
    };
    Queue() { front = back = nullptr; }

private:
    qNode *front;
    qNode *back;

public:
    bool isEmpty() { return (front == nullptr && back == nullptr ? 1 : 0); }

    void enqueue(int x)
    {
        qNode *temp;
        temp = new qNode(x);
        if (front == nullptr && back == nullptr)
        {
            front = back = temp;
            return;
        }
        back->next = temp;
        back = temp;
    }

    int dequeue()
    {
        qNode *temp = front;
        front = front->next;
        int x = temp->data;
        if (front == nullptr)
            back = nullptr;
        delete temp;
        return x;
    }

    int frontElement()
    {
        if (front != nullptr)
            return front->data;
        return -1;
    }
};

class Graph
{
private:
    int vertices;
    int edges;
    Node **arr;

public:
    Graph() { vertices = edges = -1; };
    ~Graph(){};
    void takeInput();
    void BFS();
    void DFS();
} G;

void Graph::BFS()
{
    cout << "BFS for given graph: ";
    bool isVisited[vertices];
    for (int i = 0; i < vertices; i++)
        isVisited[i] = false;
    Node *curr = arr[0];
    Queue q;
    q.enqueue(curr->data);
    isVisited[curr->data] = true;
    while (!q.isEmpty())
    {
        int x = q.frontElement();
        if (x != -1)
            cout << x << ", ";
        q.dequeue();
        curr = arr[x];
        while (curr != nullptr)
        {
            if (!isVisited[curr->data])
            {
                isVisited[curr->data] = true;
                q.enqueue(curr->data);
            }
            curr = curr->next;
        }
    }
    cout << endl;
}

void Graph::DFS()
{
    cout << "DFS for given graph: ";
    bool isVisited[vertices];
    Node *first = arr[0];
    Node *curr = nullptr;
    for (int i = 0; i < vertices; i++)
        isVisited[i] = false;
    Stack st;

    st.push(first->data);
    isVisited[first->data] = true;
    while (!st.isEmpty())
    {
        int x = st.stackTop();
        if (x != -1)
            cout << x << ", ";
        st.pop();
        curr = arr[x];
        while (curr != nullptr)
        {
            if (!isVisited[curr->data])
            {
                isVisited[curr->data] = true;
                st.push(curr->data);
            }
            curr = curr->next;
        }
    }
    cout << endl;
}

void Graph::takeInput()
{
    int x;
    string s;
    cout << "\nEnter number of vertices: ";
    cin >> vertices;
    cout << "\nEnter number of edges: ";
    cin >> edges;

    arr = new Node *[vertices];
    Node *temp = nullptr;
    Node *curr = nullptr;
    for (int i = 0; i < vertices; i++)
    {
        do
        {
            x = 0;
            if (arr[i] == nullptr)
            {
                cout << "\nEnter data for " << i << endl;
                cout << "\nLandmark for node-" << i << ": ";
                cin >> s;
                arr[i] = new Node(i, s);
                continue;
            }
            else
            {
                cout << "\nEnter adjacent landmarks for " << i << endl;
                cout << "Data(-1 to go to next landmark): ";
                cin >> x;
                if (x == -1)
                    continue;
                cout << "Landmark for node " << x << ": ";
                cin >> s;
                curr = *(arr + i);
                while (curr->next != nullptr)
                    curr = curr->next;
                temp = new Node(x, s);
                curr->next = temp;
                curr = curr->next;
            }
        } while (x != -1);
    }
}

int main()
{
    bool menu = 1;
    while (menu)
    {
        int ch;
        cout << "\n\nMENU\n1.Enter graph\n2.BFS\n3.DFS\nEnter your choice(-1 to exit): ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            G.takeInput();
            break;

        case 2:
            G.BFS();
            break;

        case 3:
            G.DFS();
            break;

        case -1:
            menu = 0;
            break;

        default:
            break;
        }
    }

    return 0;
}
/*

MENU
1.Enter graph
2.BFS
3.DFS
Enter your choice(-1 to exit): 1

Enter number of vertices: 5

Enter number of edges: 7

Enter data for 0

Landmark for node-0: 0

Enter adjacent landmarks for 0
Data(-1 to go to next landmark): 1
Landmark for node 1: 1

Enter adjacent landmarks for 0
Data(-1 to go to next landmark): 2
Landmark for node 2: 2

Enter adjacent landmarks for 0
Data(-1 to go to next landmark): -1

Enter data for 1

Landmark for node-1: 2

Enter adjacent landmarks for 1
Data(-1 to go to next landmark): 0
Landmark for node 0: 0

Enter adjacent landmarks for 1
Data(-1 to go to next landmark): 2
Landmark for node 2: 2

Enter adjacent landmarks for 1
Data(-1 to go to next landmark): 3
Landmark for node 3: 3

Enter adjacent landmarks for 1
Data(-1 to go to next landmark): 4
Landmark for node 4: 4

Enter adjacent landmarks for 1
Data(-1 to go to next landmark): -1

Enter data for 2

Landmark for node-2: 2

Enter adjacent landmarks for 2
Data(-1 to go to next landmark): 0
Landmark for node 0: 0

Enter adjacent landmarks for 2
Data(-1 to go to next landmark): 1
Landmark for node 1: 1

Enter adjacent landmarks for 2
Data(-1 to go to next landmark): 4
Landmark for node 4: 4

Enter adjacent landmarks for 2
Data(-1 to go to next landmark): -1

Enter data for 3

Landmark for node-3: 3

Enter adjacent landmarks for 3
Data(-1 to go to next landmark): 1
Landmark for node 1: 1

Enter adjacent landmarks for 3
Data(-1 to go to next landmark): 4
Landmark for node 4: 4

Enter adjacent landmarks for 3
Data(-1 to go to next landmark): -1

Enter data for 4

Landmark for node-4: 4

Enter adjacent landmarks for 4
Data(-1 to go to next landmark): 1
Landmark for node 1: 1

Enter adjacent landmarks for 4
Data(-1 to go to next landmark): 2
Landmark for node 2: 2

Enter adjacent landmarks for 4
Data(-1 to go to next landmark): 3
Landmark for node 3: 3

Enter adjacent landmarks for 4
Data(-1 to go to next landmark): -1


MENU
1.Enter graph
2.BFS
3.DFS
Enter your choice(-1 to exit): 2
BFS for given graph: 0, 1, 2, 3, 4, 


MENU
1.Enter graph
2.BFS
3.DFS
Enter your choice(-1 to exit): 3
DFS for given graph: 0, 2, 4, 3, 1, 


MENU
1.Enter graph
2.BFS
3.DFS
Enter your choice(-1 to exit): -1
*/