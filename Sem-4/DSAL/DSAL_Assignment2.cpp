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

class BinarySearchTree;
class Node
{
    string keyword;
    string meaning;
    Node *left;
    Node *right;

public:
    friend class BinarySearchTree;
    Node() {}
    Node(string key, string meaning)
    {
        this->keyword = key;
        this->meaning = meaning;
        left = right = NULL;
    }
};

class BinarySearchTree
{
    Node *root;
    static unsigned int comparisons;

public:
    BinarySearchTree() { root = NULL; }
    void insert(string, string);
    void insertRecursive(Node *);
    void update();
    void deleteKey();
    void showDataAsc();
    void showDataDes();
    static void showComparisons();
} bst;

unsigned int BinarySearchTree::comparisons = 0;

int main()
{
    bool menu = 1;
    int ch;
    while (menu)
    {
        cout << "\n\nMENU\n1.ADD KEYWORD\n2.UPDATE KEYWORD\n3.DELETE KEYWORD\n4.SEARCH FOR A KEYWORD\nENTER YOUR CHOICE(-1 to exit): ";
        cin >> ch;
        string keyword, meaning;
        switch (ch)
        {
        case 1:
            cout << "\nEnter keyword: ";
            cin >> keyword;
            cout << "\nEnter meaning: ";
            cin >> meaning;
            // getline(cin, meaning);
            bst.insert(keyword, meaning);
            break;

        case 2:

            break;

        case 3:

            break;

        case 4:

            break;

        case -1:
            menu = 0;
            break;

        default:
            cout << "\nInvalid choice!!!";
            break;
        }
    }

    return 0;
}

void BinarySearchTree::insert(string key, string meaning)
{
    Node *rt = root;
    Node *tail = NULL, *tmp;
    if (root == NULL)
    {
        root = new Node(key, meaning);
        cout << "\nRoot created";
        return;
    }
    while (rt != NULL)
    {
        tail = rt;
        if (key == rt->keyword)
            return;
        if (key > rt->keyword)
            rt = rt->right;
        else
            rt = rt->left;
    }
    tmp = new Node(key, meaning);
    if (tmp->keyword < tail->keyword)
        tail->left = tmp;
    else
        tail->right = tmp;
}
