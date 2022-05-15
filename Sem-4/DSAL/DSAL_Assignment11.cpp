/*
    Samamrth Kamble
    21142 (F1-Batch)
    Date of completion: 12/05/22

    Problem Statement:
    Implement the Heap sort algorithm implemented in CPP/Java demonstrating heap
    data structure with modularity of programming language
*/

#include <iostream>
#define sp " "
using namespace std;

class Heap
{
    int *heap;
    int last;

public:
    Heap(int x)
    {
        heap = new int[x + 1];
        last = 0;
    }
    void insert(int x)
    {
        int i = ++last;
        heap[i] = x;
        while (i != 0)
        {
            if (i == 0)
                continue;
            if (heap[i] > heap[i / 2] && i != 1)
                swap(heap[i], heap[i / 2]);
            i /= 2;
        }
        for (int i = 1; i <= last; i++)
            cout << heap[i] << sp;
    }
    void deleteLast()
    {
        swap(heap[last], heap[1]);
        int size = last;
        last--;
        for (int i = 1; i <= size; i++)
        {
            int rt = 1, ch = 2;
            while (ch < last)
            {
                if (heap[ch + 1] > heap[ch])
                    ch++;
                if (heap[rt] < heap[ch])
                {
                    swap(heap[rt], heap[ch]);
                    rt = ch;
                    ch *= 2;
                }
                else
                    break;
            }
            if (last > 2)
                swap(heap[last--], heap[1]);
            else if (heap[1] > heap[2])
                swap(heap[1], heap[2]);
        }
        cout << "\nHeap sort: ";
        for (int i = 1; i <= size; i++)
            cout << heap[i] << sp;
        cout << endl;
    }
} * HP;

int main()
{
    bool menu = 1;
    int x;
    HP = new Heap(100);
    while (menu)
    {
        int ch;
        cout << "\n\nMENU\n1.Insert\n2.Heap-Sort\nENTER: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter element: ";
            cin >> x;
            HP->insert(x);
            break;

        case 2:
            HP->deleteLast();
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
*/