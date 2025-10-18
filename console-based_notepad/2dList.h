#pragma once
#include "myStack.h"
#include <type_traits>
#include <fstream>
#include <string>

template <typename T>
class row;

template<typename T>
class twoDNode {
	T data;
	twoDNode* left, * right;
	row<T> *up, * down;
public:
	twoDNode(const T& data =T(), twoDNode* left = nullptr, twoDNode* right = nullptr, row<T>* up = nullptr, row<T>* down = nullptr) {
		this->data = data;
		this->left = left;
		this->right = right;
		this->up = up;
		this->down = down;
	}
	T& get() {
		return this->data;
	}
	twoDNode<T>* getLeft() {
		return this->left;
	}
	twoDNode<T>* getRight() {
		return this->right;
	}
	row<T>* getUp() {
		return this->up;
	}
	row<T>* getDown() {
		return this->down;
	}

	void set(const T& data) {
		this->data = data;
	}
	void setLeft(twoDNode<T>* ptr) {
		this->left = ptr;
	}
	void setRight(twoDNode<T>* ptr) {
		this->right = ptr;
	}
	void setUp(row<T>* ptr) {
		this->up = ptr;
	}
	void setDown(row<T>* ptr) {
		this->down = ptr;
	}

};

//template <typename T>
//class twoDList {
//	twoDNode<T>* head, * tail, * current;
//	int size;
//public:
//	twoDList(){
//		size = 0;
//		head = tail = current = new twoDNode<T>();
//	}
//
//	void insertAtTail(const T& data) {
//		twoDNode<T>* newnode = new twoDNode<T>(data, tail, nullptr);
//		tail->setRight(newnode);
//		twoDNode<T>* top = tail->getUp(), * down = tail->getDown();
//
//		if (top && top->getRight()) {
//			top->getRight()->setDown() newnode;
//			newnode->setUp(top->getRight());
//		}
//
//		if (down && down->getRight()) {
//			down->getRight()->setUp(newnode);
//			newnode->setDown(down->getRight());
//		}
//		tail = newnode;
//		current = newnode;
//		size++;
//	}
//
//	void remove() {
//		if (!size) return;
//
//		if (current->getLeft()) current->getLeft()->setRight(current->getRight());
//		if (current->getRight()) current->getRight()->setLeft(current->getLeft());
//		if (current->getUp()) current->getUp()->setDown(current->getRight());
//		if (current->getDown()) current->getDown()->setUp(current->getRight());
//
//		twoDNode<T>* temp = current->getLeft();
//
//		delete current;
//		current = temp;
//		size--;
//	}
//};

template <typename T>
class row {
	twoDNode<T>* head, * tail, * current;
	int size;

public:
	row() {
		head = tail = new twoDNode<T>();
		current = nullptr;
		size = 0;
	}
	~row() {
		current = head;
		while (current) {
			twoDNode<T>* temp = current->getRight();
			delete current;
			current = temp;
		}
	}

	void insertAtTail(const T& data) {
		twoDNode<T>* newNode = new twoDNode<T>(data, tail);
		tail->setRight(newNode);
		current = newNode;
		tail = newNode;
		size++;
	}
	int getSize() {
		return this->size;
	}

	int getIdx() {
		if (!size) return 0;

		int idx = 0;
		twoDNode<T>* temp = head;
		while (temp != current && temp) {
			temp = temp->getRight();
			idx++;
		}

		return idx;
	}

	void moveTo(int idx) {
		int temp = 0;
		current = head;
		while (current && current->getRight() && temp < idx) {
			current = current->getRight();
			temp++;
		}
	}

	void insertBefore(const T& data) {
		if (!size) return;
		twoDNode<T>* newnode = new twoDNode<T>(data, current->getLeft(), current);

		current->getLeft()->setRight(newnode);
		current->setLeft(newnode);

		size++;
	}

	T remove() {
		if (!size) return T();

		T delVal = current->get();

		twoDNode<T>* prev = current->getLeft(), * next = current->getRight();
		if (prev) prev->setRight(next);
		if (next) next->setLeft(prev);
		else tail = tail->getLeft();

		delete current;
		size--;

		if (size) current = prev;
		else {
			current = nullptr;
			tail = head;
		}

		return delVal;
	}

	T removeBefore() {
		if (size <= 1) return T();

		moveLeft();
		T delVal = remove();
		moveRight();

		return delVal;
	}

	void moveLeft() {
		if (current->getLeft() != head && current->getLeft()) current = current->getLeft();
	}

	void moveRight() {
		if (current->getRight())current = current->getRight();
	}

	twoDNode<T>*& getHead() {
		return this->head;
	}

	void display() {
		twoDNode<T>* temp = head->getRight();
		while (temp) {
			cout << temp->get();
			temp = temp->getRight();
		}
	}
	void copyIntoStack(myStack<T>& s) {
		twoDNode<T>* temp = tail;

		while (temp != current && temp != head && temp) {
			s.push_back(temp->get());
			temp = temp->getLeft();
		}

		tail = current;
		temp = tail->getRight();
		while (temp) {
			twoDNode<T>* next = temp->getRight();
			delete temp;
			temp = next;
			size--;
		}

		if (current) current->setRight(nullptr);
	}
};

template <typename T>
class rowsList {
	row<T>* current, * first;
	int size;
public:
	rowsList() {
		first = current = new row<T>();
		size = 0;
	}
	void addRow() {
		row<T>* newRow = new row<T>(), * tempDown = current->getHead()->getDown();
		newRow->getHead()->setUp(current);
		current->getHead()->setDown(newRow);
		current = newRow;
		if (tempDown) tempDown->getHead()->setUp(newRow);
		newRow->getHead()->setDown(tempDown);

		size++;
	}
	void removeRow() {
		if (!size) return;

		row<T>* temp = current->getHead()->getUp(), * tempDown = current->getHead()->getDown();
		if (temp) temp->getHead()->setDown(tempDown);
		if (tempDown) tempDown->getHead()->setUp(temp);

		delete current;
		size--;

		current = temp;
		if (!temp) first = tempDown;
	}

	void insertAtTail(const T& data) {
		current->insertAtTail(data);
	}
	void insertBefore(const T& data) {
		current->insertBefore(data);
	}
	int getIdx() {
		return current->getIdx();
	}
	void moveTo(int idx) {
		current->moveTo(idx);
	}
	int getRowSize() {
		return current->getSize();
	}
	T remove() {
		return current->remove();
	}
	T removeBefore() {
		return current->removeBefore();
	}
	void copyIntoStack(myStack<T>& s) {
		current->copyIntoStack(s);
	}

	void moveUp() {
		if (!current->getHead()->getUp()) return;

		int idx = current->getIdx();
		current = current->getHead()->getUp();
		moveTo(idx);
	}

	void moveDown() {
		if (!current->getHead()->getDown()) return;

		int idx = current->getIdx();
		current = current->getHead()->getDown();
		moveTo(idx);
	}

	void moveRight() {
		current->moveRight();
	}

	void moveLeft() {
		current->moveLeft();
	}

	void display() {
		row<T>* temp = first;
		while (temp) {
			temp->display();
			temp = temp->getHead()->getDown();

			if (temp) cout << endl;
		}
	}

	bool isLast(){
		return !current->getHead()->getDown();
	}

	bool isFirst() {
		return !current->getHead()->getUp();
	}

	int getRows() {
		return size;
	}

	row<T>* getCurrentRow() {
		return current;
	}

	void save() {
		if constexpr(!is_same<T, char>::value) return;

		string name = "files/";
		row<T>* temp = first;
		twoDNode<T>* node = temp->getHead()->getRight();
		while (node) {
			if (node->get() == 32) break;
			else if (node->get() != '|') name += node->get();
			node = node->getRight();
		}
		name += ".txt";

		ofstream file(name);
		if (!file.is_open()) {
			cout << "Error Opening File!";
			return;
		}

		char ch = 'a';
		while (temp) {
			twoDNode<T>* tempNode = temp->getHead()->getRight();
			while (tempNode) {
				if (tempNode->get() != '|') {
					file << tempNode->get();
					file << ch;
					ch = tempNode->get();
				}
				tempNode = tempNode->getRight();
			}
			file << '|';
			temp = temp->getHead()->getDown();
		}
		file.close();
	}

	void load(string name) {
		if constexpr (!is_same<T, char>::value) return;

		name = "files/" + name;
		ifstream file(name);
		if (!file.is_open()) {
			cout << "Unable to open file" << endl;
			return;
		}

		char a, b;
		while (file.get(a)) {
			if (a == '|') {
				addRow();
				continue;
			}
			if (!file.get(b)) break;
			insertAtTail(a);	
		}
		file.close();
	}
};