/*
    Samarth Kamble
    21142 (F1-Batch)
    Assignment-7

    Problem Statement:
    You have a business with several offices; you want to lease phone lines to connect them up with each other; and the phone
    company charges different amounts of money to connect different pairs of cities.
    You want a set of lines that connects all your offices with a minimum total cost.
    Solve the problem by suggesting appropriate data structures.
 */
#include <iostream>
#define mx 2147483647;
using namespace std;

class Graph
{
    int cost[20][20];
    int near[21];
    int ST[2][20];
    int vertices;
    int edges;

public:
    Graph() { vertices = edges = -1; }
    Graph(int x, int y)
    {
        vertices = x;
        edges = y;
    }

    void initialize()
    {
        for (int i = 0; i < 20; i++)
        {
            near[i] = mx;
            near[20] = mx;
            for (int j = 0; j < 20; j++)
                cost[i][j] = mx;
        }

        for (int i = 0; i < 20; i++)
        {
            ST[0][i] = 0;
            ST[1][i] = 0;
        }

        int mini = mx;
        int minj = mx;
        int min = mx;

        for (int i = 1; i <= vertices; i++)
        {
            for (int j = i; j <= vertices; j++)
            {
                if (i == j)
                    continue;
                int x;
                cout << "Enter cost between office-" << i << " and office-" << j << ": ";
                cin >> x;
                if (x == -1)
                    continue;
                cost[i][j] = x;
                cost[j][i] = x;
                if (x < min)
                {
                    min = x;
                    mini = i;
                    minj = j;
                }
            }
        }

        // cost[1][2] = cost[2][1] = 25;
        // cost[2][3] = cost[3][2] = 12;
        // cost[2][7] = cost[7][2] = 10;
        // cost[3][4] = cost[4][3] = 8;
        // cost[4][7] = cost[7][4] = 14;
        // cost[4][5] = cost[5][4] = 16;
        // cost[5][7] = cost[7][5] = 18;
        // cost[5][6] = cost[6][5] = 20;
        // cost[6][1] = cost[1][6] = 5;
        // mini = 1; minj = 6; min = 5;

        near[mini] = 0;
        near[minj] = 0;
        ST[0][0] = mini;
        ST[1][0] = minj;
        int k = ST[1][0];
        int l = ST[0][0];
        for (int i = 1; i <= vertices; i++)
        {
            if (near[i] != 0 && cost[i][mini] < cost[i][minj])
                near[i] = mini;
            else if (near[i] != 0)
                near[i] = minj;
        }
    }

    void prims()
    {
        initialize();
        int k;
        for (int i = 1; i < vertices - 1; i++)
        {
            int min = mx;
            for (int j = 1; j <= vertices; j++)
            {
                if (near[j] != 0 && cost[j][near[j]] < min)
                {
                    min = cost[j][near[j]];
                    k = j;
                }
            }
            ST[0][i] = k;
            ST[1][i] = near[k];
            near[k] = 0;

            for (int j = 1; j <= vertices; j++)
            {
                if (near[j] != 0 && cost[j][k] < cost[j][near[j]])
                    near[j] = k;
            }
        }
    }

    void showPath()
    {
        cout << "Spanning tree: ";
        cout << ST[0][0] << "->" << ST[1][0] << "->";
        for (int i = 1; i < vertices - 1; i++)
        {
            cout << ST[0][i] << "->";
        }
        cout << "end\n";
        cout << "Cost: ";
        int c = 0;
        for (int i = 0; i < vertices - 1; i++)
        {
            c += cost[ST[0][i]][ST[1][i]];
        }
        cout << c << endl;
    }

} * G;

int main()
{
    bool menu = 1;
    int ch;
    int v, e;
    while (menu)
    {
        cout << "\n\n1.Enter graph\n2.Get path\nEnter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter vertices: ";
            cin >> v;
            cout << "Enter edges: ";
            cin >> e;
            G = new Graph(v, e);
            G->prims();
            break;

        case 2:
            G->showPath();
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
