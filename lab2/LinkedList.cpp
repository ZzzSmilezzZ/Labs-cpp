#pragma once
#include <iostream>
#include "LinkedList.h"
#include <vector>
#include <cassert>

LinkedList::LinkedList()
{
	LinkedList::first == nullptr;
	LinkedList::last == nullptr;
}

LinkedList::~LinkedList()
{

}

void LinkedList::addNode(const int value)
{
	if (this->last == nullptr) {
		this->first = new Node(value);
		this->last = this->first;
		++count;
	}
	else {
		this->last->next = new Node(value);
		this->last = last->next;
		++count;
	}
}

void LinkedList::printAllList()
{
	auto step = this->first;
	while (step->next != nullptr) {
		std::cout << step->value << " -> ";
		step = step->next;
	}
	std::cout << step->value;
}

void LinkedList::removeDuplicates()
{
	const int size = count;
	int counter = 1;
	int* hash = new int[size];
	hash[0] = this->first->value;
	auto step = this->first;
	Node* temp;
	while (step->next != nullptr) {
		if (contains(hash, counter, step->next))
			if (step->next->next == nullptr) {
				step->next = nullptr;
				this->last = step;
			}
			else {
				step->next = step->next->next;
				--(this->count);
			}
		else {
			step = step->next;
			hash[counter] = step->value;
			++counter;
		}
			
	}
}

LinkedList::Node::Node(const int value)
{
	this->value = value;
}

LinkedList::Node::~Node()
{
	
}

bool LinkedList::contains(int* arr, int size, Node* node) {
	auto step = arr;
	for (int i = 0; i < size; ++i) 
		if (step[i] == node->value) return true;
	return false;
}

LinkedList::Node* LinkedList::getElementOnPosFromEnd(const int k)
{
	assert(!(k > this->count) && "index k is out of range");
	Node* step = this->first;
	for (int i = 2; i < (count - k + 2); ++i)
		step = step->next;
	return step;
}


