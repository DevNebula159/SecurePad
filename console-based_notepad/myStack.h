#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Node {
private:
	T data;
	Node* nextNode, * prevNode;
public:
	T& get() {
		return data;
	}
	void set(const T& val) {
		data = val;
	}
	Node<T>* getNext() {
		return nextNode;
	}
	Node<T>* getPrev() {
		return this->prevNode;
	}
	void setNext(Node<T>* nextNode) {
		this->nextNode = nextNode;
	}
	void setPrev(Node<T>* prev) {
		this->prevNode = prev;
	}
	Node(const T& val = T(), Node<T>* next = nullptr, Node<T>* prev = nullptr) {
		data = val;
		this->nextNode = next;
		this->prevNode = prev;
	}
};

template <typename T>
class myStack {
	Node<T>* head, * tail;
	int size;

public:
	myStack() {
		head = tail = new Node<T>();
		size = 0;
	}
	~myStack() {
		Node<T>* current = head;
		while (current) {
			Node<T>* next = current->getNext();
			delete current;
			current = next;
		}
		head = tail = nullptr;
	}

	void push_back(const T& data) {
		Node<T>* newnode = new Node<T>(data, nullptr, tail);

		tail->setNext(newnode);
		tail = newnode;
		size++;
	}
	void pop() {
		if (!size) return;

		Node<T>* prev = tail->getPrev();
		prev->setNext(nullptr);
		delete tail;
		tail = prev;
		size--;
	}
	T top() {
		return tail->get();
	}

	bool isEmpty() {
		return !size;
	}
};