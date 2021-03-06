// BinarySearchClass.cpp : Defines the entry point for the console application.
// Code adapted from: https://www.geeksforgeeks.org/insertion-binary-tree/
// Code adapted from: https://www.cprogramming.com/tutorial/lesson18.html
// Adam Tucker
// 08/09/18

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

/* A binary tree node has key, pointer to left child
and a pointer to right child */
struct Node {
	double key;
	struct Node* left, *right;
};

class BinaryTree
{
public:
	Node * root;
	vector <Node*>* vectorBTree = new vector <Node *> ();

	BinaryTree();

	void insert(double key);
	bool search(double key);
	void inorder(vector <Node*>* temp);
	struct Node* newNode(int);

private:
	bool search(int key, Node *leaf);
	void inorder(vector <Node*>*, Node*);
};

int main()
{
	BinaryTree btree = BinaryTree();
	btree.root = btree.newNode(10.0);
	Node* root = btree.root;
	root->left = btree.newNode(11.0);
	root->left->left = btree.newNode(7.0);
	root->right = btree.newNode(9.0);
	root->right->left = btree.newNode(15.0);
	root->right->right = btree.newNode(8.0);

	cout << "Tree before inorder traversal: " << root->key << endl;
	cout << setw(29) << root->left->key << setw(7) << root->right->key << endl;
	cout << setw(26) << root->left->left->key << setw(8) << root->right->left->key << setw(4) << root->right->right->key << endl;

	cout << "Inorder traversal: ";
	btree.inorder(btree.vectorBTree);

	for (vector<Node*>::const_iterator i = btree.vectorBTree->begin(); i != btree.vectorBTree->end(); ++i) {
		Node* temp = *i;
		cout << temp->key << " ";
	}
	cout << endl;

	double key = 12.0;
	btree.insert(key);

	cout << "Searching for: " << key << endl;
	if (btree.search(key)) {
		cout << key << " was found in the tree." << endl;
	}
	else {
		cout << key << " was not found in the tree." << endl;
	}

	key = 13.0;
	cout << "Searching for: " << key << endl;
	if (btree.search(key)) {
		cout << key << " was found in the tree." << endl;
	}
	else {
		cout << key << " was not found in the tree." << endl;
	}

	return 0;
}

BinaryTree::BinaryTree()
{
	root = NULL;
}

void BinaryTree::insert(double key)
{

	Node* temp = this->root;
	Node* parent = temp;

	if (this->root == NULL) {
		this->root = this->newNode(key);
	}
	else {
		temp = root;

		while (temp != NULL) {
			if (key <= temp->key) {
				parent = temp;
				temp = temp->left;
			}
			else {
				parent = temp;
				temp = temp->right;
			}
		}
		Node* newNode = this->newNode(key);
		if (key <= parent->key) {
			parent->left = newNode;
		}
		else {
			parent->right = newNode;
		}
	}
}

bool BinaryTree::search(double key)
{
	return search(key, root);
}

bool BinaryTree::search(int key, Node *leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->key)
			return leaf;
		if (key<leaf->key)
			return search(key, leaf->left);
		else
			return search(key, leaf->right);
	}
	else return NULL;
}

void BinaryTree::inorder(vector<Node*>* temp, Node * root)
{
	if (root == NULL)
		return;

	inorder(temp,root->left);
	temp->push_back(root);
	inorder(temp, root->right);
}

void BinaryTree::inorder(vector<Node*>* temp)
{
	inorder(temp, root);
}


struct Node* BinaryTree::newNode(int key)
{
	struct Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
};
