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
    string capitalise(string &s)
    {
        for (auto &ch : s)
            ch = (char)(ch & (~(1 << 5)));
        return s;
    }
    Node()
    {
        keyword = meaning = "";
        left = right = NULL;
    }
    Node(string key, string meaning)
    {
        this->keyword = capitalise(key);
        this->meaning = meaning;
        left = right = NULL;
    }
    int count(Node *);
    int height(Node *);
} *root = NULL;

class BinarySearchTree
{
    int comparisons;

public:
    BinarySearchTree() { comparisons = 0; }
    void insert(string, string);
    void insertRecursive(Node *);
    void update(string, string);
    void search(string);
    Node *deleteKey(Node *, string);
    void showDataAsc();
    void showDataDes();
    static void showComparisons();
} bst;

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
            cin.ignore();
            getline(cin, meaning);
            bst.insert(keyword, meaning);
            cout << "\nHeight: " << root->height(root) << endl;
            break;

        case 2:
            cout << "\nEnter the keyword: ";
            cin >> keyword;
            cout << "\nEnter new meaning: ";
            cin.ignore();
            getline(cin, meaning);
            bst.update(keyword, meaning);
            break;

        case 3:
            cout << "\nEnter the keyword you want to delete: ";
            cin >> keyword;
            // bst.deleteKey(keyword);
            break;

        case 4:
            cout << "\nEnter the keyword: ";
            cin >> keyword;
            bst.search(keyword);
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

void BinarySearchTree::search(string key)
{
    comparisons = 0;
    string k = key;
    key = root->capitalise(key);
    Node *tmp = root;
    while (tmp != NULL)
    {
        if (key < tmp->keyword)
            tmp = tmp->left;
        else if (key > tmp->keyword)
            tmp = tmp->right;
        else
        {
            cout << "\nThe meaning of " << k << " is given as " << tmp->meaning << endl;
            cout << "Comarisons: " << BinarySearchTree::comparisons << endl;
            return;
        }
        comparisons++;
    }
    cout << "\nThe meaning for " << k << " is not present in dictionary.";
}

int Node::count(Node *p)
{
    int x;
    int y;
    if (p != nullptr)
    {
        x = count(p->left);
        y = count(p->right);
        return x + y + 1;
    }
    return 0;
}

int Node::height(Node *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = height(p->left);
    y = height(p->right);
    return (x > y) ? x + 1 : y + 1;
}



Node *BinarySearchTree::deleteKey(Node *p, string key)
{
    Node *q;
    if (p == NULL)
        return NULL;
    if (p->left == NULL && p->right == NULL)
    {
        if (p == root)
            root = NULL;
        delete p;
        p = NULL;
        return NULL;
    }

    if (key < p->keyword)
        deleteKey(p->left, key);
    else if (key > p->keyword)
        deleteKey(p->right, key);
    else
    {
        if (root->height(p->left) > root->height(p->right))
        {

        }
    }

    return p;
}

void BinarySearchTree::update(string key, string newMeaning)
{
    Node *tmp = root;
    key = root->capitalise(key);
    while (tmp != NULL)
    {
        if (tmp->keyword < key)
            tmp = tmp->right;
        else if (tmp->keyword > key)
            tmp = tmp->left;
        else
        {
            tmp->meaning = newMeaning;
            cout << "\nMeaning updated";
            return;
        }
    }
    cout << "\nThe keyword " << key << " is not present in the dictionary!!!";
}

void BinarySearchTree::insert(string key, string meaning)
{
    Node *rt = root;
    Node *tail = NULL, *tmp;
    key = root->capitalise(key);
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
        {
            cout << "\nKeyword already exists!!!";
            return;
        }
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
