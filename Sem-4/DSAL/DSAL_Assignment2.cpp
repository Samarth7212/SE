/*
    Samarth (21142 F1-Batch)
    DSAL Assignment-2

    Problem Statement:
    A Dictionary stores keywords and its meanings. Provide facility for adding new keywords, deleting keywords,
    updating values of any entry. Provide facility to display whole data sorted in ascending/ Descending order.
    Also find how many maximum comparisons may require for finding any keyword. Use Binary Search Tree for
    implementation.

*/

#include <iostream>
using namespace std;

class Node
{
    string keyword;
    string meaning;
    Node *left;
    Node *right;

public:
    Node() {}
};

class BinarySearchTree
{
    static unsigned int comparisons;

public:
    void insert();
    void update();
    void deleteKey();
    void showDataAsc();
    void showDataDes();
    static void showComparisons();
};

unsigned int BinarySearchTree::comparisons = 0;

int main()
{
    return 0;
}
