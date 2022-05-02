/*
    Samarth Kamble
    21142 (F1-Batch)
    Date of start: 18/04/22
    Date of completion: /04/22

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

template <typename T>
class Stack
{
private:
    Node *top;

public:
    Stack() { top = NULL; }
    void push(T x)
    {
        Node *tmp = new Node(x->data, x->name);
        tmp->next = top;
        top = tmp;
    };

    int pop()
    {
        Node *tmp;
        tmp = top;
        auto x = tmp->data;
        top = top->next;
        delete tmp;
        return x;
    };

    bool isEmpty() { return top == NULL ? 1 : 0; };
};

class Graph
{
private:
    int vertices;
    int edges;
    Node **arr;
    // Node *arr;

public:
    Graph() { vertices = edges = -1; };
    ~Graph(){};
    void takeInput();
    void BFS();
    void DFS();
} G;

void Graph::BFS()
{
    Stack<Node *> st;
    cout << "BFS for given graph: ";
    bool isVisited[vertices];
    for (int i = 0; i < vertices; i++)
        isVisited[i] = false;
    for (int i = 0; i < vertices; i++)
    {
        Node *curr = arr[i];
        // curr = curr->link;
        while (curr != nullptr)
        {
            if (curr != nullptr)
            {
                if (!isVisited[curr->data])
                {
                    cout << curr->data << ',' << sp;
                    isVisited[curr->data] = true;
                }
                curr = curr->next;
            }
        }
    }
}

void Graph::DFS()
{
    cout << "DFS for given graph: ";
    Stack<Node *> st;
    bool isVisited[vertices];
    for (int i = 0; i < vertices; i++)
        isVisited[i] = false;

    Node *curr = arr[0];
    if (!isVisited[curr->data])
    {
        cout << curr->data << ',' << sp;
        isVisited[curr->data] = true;
    }
    curr = curr->next;
    while (curr != nullptr || !st.isEmpty())
    {
        if (!isVisited[curr->data])
        {
            cout << curr->data << ',' << sp;
            isVisited[curr->data] = true;
            st.push(curr);
            curr = arr[curr->data];
            curr = curr->next;
        }
        // else
        //     curr =st.top;
    }

    // while (curr != nullptr || !st.isEmpty())
    // {
    //     if (curr != nullptr)
    //     {
    //         if (!isVisited[curr->data])
    //         {
    //             cout << curr->data << ',' << sp;
    //             isVisited[curr->data] = true;
    //             st.push(curr);
    //             curr = arr[curr->data];
    //             curr = curr->next;
    //         }
    //         else
    //             curr = curr->next;
    //     }
    //     else
    // curr = st.pop();
    // }
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
                cout << "\nLandmark for node" << i << ": ";
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
                cout << "Landmark for node " << i << ": ";
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
