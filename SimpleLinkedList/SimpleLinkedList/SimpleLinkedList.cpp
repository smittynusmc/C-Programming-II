// SimpleLinkedList.cpp : Simple linked list class with only two member functions and a default constructor
// Adds various numbers to the list and then tests for membership.
// Adapted from https://gist.github.com/charlierm/5691020
// Adam Tucker
// 07/28/18

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
using namespace std;

/*
Class the represents a linked list node
*/
class ListNode
{
public:
	ListNode * next; // the next node in the list
	int value; // the value in the node
};

/*
class that represents a Linked List (a list of nodes which points to the next node
*/
class LinkedList
{
public:
	int length; // length of the list
	ListNode* head; // beginning of the list

	LinkedList(); // default constructor
	void add(int data); // add a member at the front of the list
	bool ismember(ListNode* head, int value); // check if the value is a part of the list
	void print(); // prints the list
};

/*
LinkedList()
Default constructor
Initializes the length and the beginning of the list
*/
LinkedList::LinkedList() {
	this->length = 0;
	this->head = NULL;
}

/*
add(int value)
Adds a value to the beginning of the list
Param - the value to be added
*/
void LinkedList::add(int value) {
	ListNode* node = new ListNode();
	node->value = value;
	node->next = this->head;
	this->head = node;
	this->length++;
}

/*
ismember()
Checks whether the value x is present in linked list
adapted fromhttps://www.geeksforgeeks.org/search-an-element-in-a-linked-list-iterative-and-recursive/
Param - head - the pointer to the head of the linked list
		value - the value being searched for
*/
bool LinkedList::ismember(ListNode* head, int value)
{
	ListNode* current = head;  // Initialize current
	while (current != NULL)
	{
		if (current->value == value)
			return true;
		current = current->next;
	}
	return false;
}

/*
print()
Prints the values in the Linked List
*/
void LinkedList::print() {
	ListNode* head = this->head;
	int i = 1;
	cout << "Linked List contains : ";
	while (head) {
		cout << head->value << " ";
		head = head->next;
		i++;
	}
	cout << endl;
}

/*
Main Function
*/
int main()
{
	LinkedList* list = new LinkedList(); // init linked list
	for (int i = 0; i < 10; ++i)
	{
		list->add(i * 2); // add even number to the linked list
	}
	list->print(); // print the linked list
	if (list->ismember(list->head,4)) { // check if 4 is in the list
		cout << "4 is part of the Linked List" << endl;
	}
	else {
		cout << "4 is not part of the Linked List" << endl;
	}
	if (list->ismember(list->head, 5)) { // check if 5 is in the list
		cout << "5 is part of the Linked List" << endl;
	}
	else {
		cout << "5 is not part of the Linked List" << endl;
	}
	delete list; // delete list from memory
	return 0;
}