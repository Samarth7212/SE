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
using namespace std;

class Graph
{
private:
public:
    Graph(){};
    ~Graph(){};

private:
    class Node
    {
    private:
        int data;
        Node *next;

    public:
        Node()
        {
            data = -1;
            next = nullptr;
        };
        Node(int x)
        {
            data = x;
            next = nullptr;
        }
        ~Node(){};
    };

} G;

int main()
{
    bool menu = 1;
    while (menu)
    {
        int ch;
        cout << "\n\nMENU\n1.\n2.\n3.\nEnter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:

            break;

        case 2:

            break;

        case 3:

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
