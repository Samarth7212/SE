/*
    Samarth (21142 F1-Batch)
    DSAL Assignment-2

    Problem Statement:
    A Dictionary stores keywords and its meanings. Provide facility for adding new keywords, deleting keywords,
    updating values of any entry. Provide facility to display whole data sorted in ascending/ Descending order.
    Also find how many maximum comparisons may require for finding any keyword. Use Binary Search Tree for
    implementation.

    Date of completion: 10/02/2022

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
    static unsigned int nodeCount;
    static void decrement() { nodeCount--; }
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
} *root = NULL;

class BinarySearchTree
{
    int comparisons;
    string arr[50];
    int ind = 0;

public:
    BinarySearchTree() { comparisons = 0; }
    int height(Node *);
    void insert(string, string);
    void update(string, string);
    void search(string);
    Node *getKey(Node *, string);
    Node *deleteKey(Node *&, string);
    void showData(Node *, bool);
    void inOrder(Node *);
    Node *inPred(Node *);
    Node *inSucc(Node *);

    static void showComparisons();
} bst;

unsigned int Node::nodeCount = 0;
int main()
{
    bool menu = 1;
    int ch;
    while (menu)
    {
        cout << "\n\nMENU\n1.ADD KEYWORD\n2.UPDATE KEYWORD\n3.DELETE KEYWORD\n4.SEARCH FOR A KEYWORD\n5.KEYWORDS IN ASCENDING AND DESCENDING ORDER\nENTER YOUR CHOICE(-1 to exit): ";
        cin >> ch;
        string keyword, meaning;
        Node *temp;
        switch (ch)
        {
        case 1:
            cout << "\nEnter keyword: ";
            cin >> keyword;
            cout << "\nEnter meaning: ";
            cin.ignore();
            getline(cin, meaning);
            bst.insert(keyword, meaning);
            cout << "\nHeight: " << bst.height(root) << endl;
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
            temp = root;
            temp = bst.getKey(temp, keyword);
            bst.deleteKey(temp, keyword);
            Node::decrement();
            break;

        case 4:
            cout << "\nEnter the keyword: ";
            cin >> keyword;
            bst.search(keyword);
            break;

        case 5:
            cout << "\nKeywords in ascending order: \n";
            bst.showData(root, 1);
            cout << "\nKeywords in descending order: \n";
            bst.showData(root, 0);
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

void BinarySearchTree::showData(Node *root, bool a)
{
    // arr = new string[Node::nodeCount];
    ind = 0;
    inOrder(root);
    if (a)
    {
        for (int i = 0; i <= Node::nodeCount; i++)
            cout << arr[i] << " ";
    }
    else
    {
        for (int i = Node::nodeCount; i >= 0; i--)
            cout << arr[i] << " ";
    }
    cout << endl;
    ind = 0;
}

void BinarySearchTree::inOrder(Node *root)
{
    if (root)
    {
        inOrder(root->left);
        if (ind <= Node::nodeCount)
            arr[ind++] = root->keyword;
        inOrder(root->right);
    }
}

void BinarySearchTree::search(string key)
{
    comparisons = 0;
    string k = key;
    key = root->capitalise(key);
    Node *tmp = root;
    while (tmp != NULL)
    {
        comparisons++;
        if (key < tmp->keyword)
            tmp = tmp->left;
        else if (key > tmp->keyword)
            tmp = tmp->right;
        else
        {
            cout << "\nThe meaning of " << k << " is given as " << tmp->meaning << endl;
            cout << "Comparisons: " << BinarySearchTree::comparisons << endl;
            return;
        }
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

int BinarySearchTree::height(Node *p)
{
    int x, y;
    if (p == NULL)
        return 0;
    x = height(p->left);
    y = height(p->right);
    return (x > y) ? x + 1 : y + 1;
}

Node *BinarySearchTree::inPred(Node *p)
{
    while (p && p->right != NULL)
        p = p->right;
    return p;
}
Node *BinarySearchTree::inSucc(Node *p)
{
    while (p && p->left != NULL)
        p = p->left;
    return p;
}

Node *BinarySearchTree::getKey(Node *p, string key)
{
    key = root->capitalise(key);
    Node *tail = NULL;
    while (p != NULL)
    {
        if (key > p->keyword)
        {
            tail = p;
            p = p->right;
        }
        else if (key < p->keyword)
        {
            tail = p;
            p = p->left;
        }
        else
        {
            if (p->left == NULL && p->right == NULL)
            {
                if (tail->left == p)
                    tail->left = NULL;
                else
                    tail->right = NULL;
            }
            return p;
        }
    }
    return NULL;
}

Node *BinarySearchTree::deleteKey(Node *&p, string key)
{
    Node *q;
    key = root->capitalise(key);
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
        if (height(p->left) > height(p->right))
        {
            q = inPred(p->left);
            p->keyword = q->keyword;
            p->meaning = q->meaning;
            p->left = deleteKey(p->left, q->keyword);
        }
        else
        {
            q = inSucc(p->right);
            p->keyword = q->keyword;
            p->meaning = q->meaning;
            p->right = deleteKey(p->right, q->keyword);
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
    Node::nodeCount++;
    if (tmp->keyword < tail->keyword)
        tail->left = tmp;
    else
        tail->right = tmp;
}
