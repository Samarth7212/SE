/*
    Samarth Kamble
    21142 (F1)
    Date of completion: 12/05/22

    Problem Statement:
    Write a C++/Java program to implement topological sorting on graph using objectoriented
    programming features Design necessary class ( Use of graph)

*/

#include <iostream>
using namespace std;

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
    int adjMatrix[20][20];
    int isVisited[20];
    int B[20];
    int size;

public:
    Graph(int x)
    {
        size = x;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
                adjMatrix[i][j] = 0;
        }
    }

    void insert(int, int, int &);

    int indegree(int);

    void showAdjMatrix();

    void topoSort();
};

void Graph::insert(int x, int y, int &cnt)
{
    if (adjMatrix[y][x] == 0)
        adjMatrix[x][y] = 1;
    else
    {
        cout << "\nShould be acyclic connected graph" << endl;
        cnt--;
    }
    cnt++;
}

int Graph::indegree(int x)
{
    int in_cnt = 0;
    for (int i = 0; i < size; i++)
    {
        if (adjMatrix[i][x] == 1)
            in_cnt++;
    }
    return in_cnt++;
}

void Graph::showAdjMatrix()
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            cout << adjMatrix[i][j] << "   ";
        cout << endl;
    }
}

void Graph::topoSort()
{
    Queue q;
    int j = 0;
    for (int i = 0; i < size; i++)
    {
        isVisited[i] = indegree(i);
        if (isVisited[i] == 0)
            q.enqueue(i);
    }
    while (!q.isEmpty())
    {
        int k = q.frontElement();
        q.dequeue();
        B[j++] = k;

        for (int i = 0; i < size; i++)
        {
            if (adjMatrix[k][i] == 1)
            {
                adjMatrix[k][i] = 0;
                isVisited[i] = isVisited[i] - 1;
                if (isVisited[i] == 0)
                    q.enqueue(i);
            }
        }
    }

    for (int i = 0; i < size; i++)
        cout << B[i] << " ,  ";
    cout << endl;
}

int main()
{
    bool menu = 1;
    int size;
    cout << "\nEnter total vertex in Graph: ";
    cin >> size;
    Graph g(size);
    int ch;
    int cnt = 0;
    while (menu)
    {
        cout << "\n1.Add edges \n2.Show matrix .\n3.Topological Sort" << endl;
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int edges;
            cout << "\nHow many edges you want to add: ";
            cin >> edges;
            while (edges--)
            {
                int x, y;
                cout << "\nFrom: ";
                cin >> x;
                cout << "To: ";
                cin >> y;
                g.insert(x, y, cnt);
            }
            break;

        case 2:
            g.showAdjMatrix();
            break;

        case 3:
            g.topoSort();
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
1.Insert
2.Heap-Sort
ENTER: 1

Enter element: 98
98

MENU
1.Insert
2.Heap-Sort
ENTER: 1

Enter element: 23
98 23

MENU
1.Insert
2.Heap-Sort
ENTER: 1

Enter element: 78
98 23 78

MENU
1.Insert
2.Heap-Sort
ENTER: 1

Enter element: 25
98 25 78 23

MENU
1.Insert
2.Heap-Sort
ENTER: 1

Enter element: 99
99 98 78 23 25

MENU
1.Insert
2.Heap-Sort
ENTER: 1

Enter element: 69
99 98 78 23 25 69

MENU
1.Insert
2.Heap-Sort
ENTER: 1

Enter element: 21
99 98 78 23 25 69 21

MENU
1.Insert
2.Heap-Sort
ENTER: 1

Enter element: 28
99 98 78 28 25 69 21 23

MENU
1.Insert
2.Heap-Sort
ENTER: 1

Enter element: 79
99 98 78 79 25 69 21 23 28

MENU
1.Insert
2.Heap-Sort
ENTER: 1

Enter element: 77
99 98 78 79 77 69 21 23 28 25

MENU
1.Insert
2.Heap-Sort
ENTER: 1

Enter element: 22
99 98 78 79 77 69 21 23 28 25 22

MENU
1.Insert
2.Heap-Sort
ENTER: 1

Enter element: 1
99 98 78 79 77 69 21 23 28 25 22 1

MENU
1.Insert
2.Heap-Sort
ENTER: 2

Heap sort: 1 21 22 23 25 28 69 77 78 79 98 99


MENU
1.Insert
2.Heap-Sort
ENTER: -1
❯ cd "/media/samarth/Data/SE_Assignments/Sem-4/DSAL/" && g++ DSAL_Assignment8.cpp -o DSAL_Assignment8 && "/media/samarth/Data/SE_Assignments/Sem-4/DSAL/"DSAL_Assignment8

Enter total vertex in Graph: 6

1.Add edges
2.Show matrix .
3.Topological Sort
Enter choice: 1

How many edges you want to add: 6

From: 5
To: 0

From: 4
To: 0

From: 5
To: 2

From: 4
To: 1

From: 2
To: 3

From: 3
To: 1

1.Add edges
2.Show matrix .
3.Topological Sort
Enter choice: 2

0   0   0   0   0   0
0   0   0   0   0   0
0   0   0   1   0   0
0   1   0   0   0   0
1   1   0   0   0   0
1   0   1   0   0   0

1.Add edges
2.Show matrix .
3.Topological Sort
Enter choice: 3
4 ,  5 ,  0 ,  2 ,  3 ,  1 ,

1.Add edges
2.Show matrix .
3.Topological Sort
Enter choice: -1
*/