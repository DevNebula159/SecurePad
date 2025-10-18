#pragma once

template <typename T>
class Node {
private:
	T data;
	Node* nextNode;
public:
	T& get() {
		return data;
	}
	void set(const T& val) {
		data = val;
	}
	Node* getNext() {
		return nextNode;
	}
	void setNext(Node* nextNode) {
		this->nextNode = nextNode;
	}
	Node(const T& val = T(), Node* next = nullptr) {
		data = val;
		this->nextNode = next;
	}
};

template <typename T>
class myQueue {
	Node<T>* head, * tail;
	int size;

public:
	myQueue() {
		head = tail = new Node<T>();
		size = 0;
	}
	~myQueue() {
		tail = head;
		while (tail) {
			Node<T>* next = tail->getNext();
			delete tail;
			tail = next;
		}
	}

	void push_back(const T& data) {
		Node<T>* newnode = new Node<T>(data, nullptr);

		tail->setNext(newnode);
		tail = newnode;
		size++;
	}
	void pop() {
		if (!size) return;
		Node<T>* temp = head->getNext();
		head->setNext(temp->getNext());

		delete temp;
		size--;
		if (!size) tail = head;
	}
	T top() {
		return head->getNext()->get();
	}

	bool isEmpty() {
		return !size;
	}
};
