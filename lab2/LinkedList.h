#pragma once

class LinkedList
{
public:
	class Node {
	public:
		int value;
		Node *next;
		Node(const int value);
		~Node();
	};
	LinkedList();
	~LinkedList();
	Node* first;
	Node* last;
	int count;
	void addNode(const int value);
	void printAllList();
	void removeDuplicates();
	bool contains(int* arr, int size, Node* node);
	Node* getElementOnPosFromEnd(const int k);
};

