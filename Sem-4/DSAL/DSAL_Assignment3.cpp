/*
	Samarth (21142 F1-Batch)
	Date of starting: 17/02/2022
	Date of completion: /02/2022
	Problem Statement:
	Create an inorder threaded binary tree and perform inorder and preorder traversals.
	Analyze time and space complexities of the algorithms.
 */
#include <iostream>
using namespace std;

class Threaded_BT;
class Node
{
	int data;
	Node *left;
	Node *right;
	bool lbit, rbit;

public:
	friend class Threaded_BT;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
		lbit = rbit = 1; // Normal Node
	}
	Node()
	{
		this->data = 0;
		left = right = NULL;
		lbit = rbit = 1; // Normal Node
	}

} *head = NULL, *root = NULL;

class Threaded_BT
{
public:
	Node *insert(Node *);
	void inOrder(Node *);
	void preOrder(Node *);
	void createHead()
	{
		head = new Node;
		head->data = -1;
		head->left = head;
		head->right = head;
	}
	Node *inPred(Node *tmp)
	{
		if (tmp == NULL)
			return NULL;
		while (tmp->right != NULL)
			tmp = tmp->right;
		return tmp;
	}
	Node *inSucc(Node *tmp)
	{
		if (tmp == NULL)
			return NULL;
		while (tmp->left != NULL)
			tmp = tmp->left;
		return tmp;
	}

	void lastLinks(Node *root)
	{
		Node *tmp = root;
		while (tmp->left != NULL)
			tmp = tmp->left;
		tmp->left = head;
		tmp->lbit = 0;
		tmp = root;
		while (tmp->right != NULL)
			tmp = tmp->right;
		tmp->right = head;
		tmp->rbit = 0;
	}
} TBT;

Node *Threaded_BT::insert(Node *rt)
{
	Node *temp = NULL;
	cout << "\nEnter the value: ";
	int x;
	cin >> x;
	if (x == -1)
		return NULL;

	temp = new Node(x);

	if (root == NULL)
	{
		root = temp;
		head->left = root;
		root->left = head;
		root->right = head;
	}
	cout << "\nEnter value of left side of " << x;
	temp->left = insert(temp->left);
	cout << "\nEnter value of right side of " << x;
	temp->right = insert(temp->right);

	Node *ip = inPred(temp->left);
	Node *is = inSucc(temp->right);
	if (ip != NULL)
	{
		if (ip->right == NULL)
		{
			ip->right = temp;
			ip->rbit = 0;
		}
	}

	if (is != NULL)
	{
		if (is->left == NULL)
		{
			is->left = temp;
			is->lbit = 0;
		}
	}
	return temp;
}

void Threaded_BT::inOrder(Node *rt)
{
	if (rt == NULL)
	{
		cout << "\nTree does not exist!!!";
		return;
	}
	while (rt->lbit)
		rt = rt->left;
	while (rt->right != rt)
	{
		if (!rt->lbit)
		{
			cout << rt->data << " ";
			while (!rt->rbit)
			{
				rt = rt->right;
				if (rt != head)
					cout << rt->data << " ";
			}
			rt = rt->right;
		}
		else
			rt = rt->left;
	}
}

void Threaded_BT::preOrder(Node *rt)
{
	if (rt == NULL)
	{
		cout << "\nTree does not exist!!!";
		return;
	}
	while (rt->right != rt)
	{
		while (rt->lbit)
		{
			cout << rt->data << " ";
			rt = rt->left;
		}
		cout << rt->data << " ";
		while (!rt->rbit)
		{
			rt = rt->right;
			if (rt == head)
				return;
		}
		rt = rt->right;
	}
}

int main()
{
	bool menu = 1;
	int ch;
	while (menu)
	{
		cout << "\n\nMENU\n1.Insert\n2.Inorder\n3.preOrder\nEnter your choice(-1 to exit): ";
		cin >> ch;

		switch (ch)
		{
		case 1:
			TBT.createHead();
			root = TBT.insert(root);
			TBT.lastLinks(root);
			break;

		case 2:
			TBT.inOrder(root);
			break;

		case 3:
			TBT.preOrder(root);
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
