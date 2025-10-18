#include "2dList.h"
#include "myStack.h"
#include <windows.h>
#include <conio.h>

void editFile(rowsList<char>& text, myStack<char>& deleted, myStack<char>& remaining) {
	while (true) {
		if (GetAsyncKeyState(VK_CONTROL) & 0x8000) {
			if (GetAsyncKeyState('S') & 0x8000) {
				text.save();
			}
		}
		if (_kbhit()) {

			int key = _getch();

			if (key == 224) { // Arrow keys
				key = _getch();
				if (key == 72) { // up
					text.remove();
					int idx = text.getIdx();
					text.moveUp();
					if (idx >= text.getRowSize()) text.insertAtTail('|');
					else {
						text.moveRight();
						text.insertBefore('|');
						text.moveLeft();
					}
				}
				else if (key == 80) { // down
					text.remove();
					int idx = text.getIdx();
					text.moveDown();
					if (idx >= text.getRowSize()) text.insertAtTail('|');
					else {
						text.moveRight();
						text.insertBefore('|');
						text.moveLeft();
					}
				}
				else if (key == 75) { // left
					if (text.getIdx() == 1 && !text.isFirst()) {
						text.remove();
						text.moveUp();
						text.insertAtTail('|');
					}
					else if (text.getIdx() != 1) {
						text.remove();
						text.insertBefore('|');
						text.moveLeft();
					}
				}
				else if (key == 77) { // right
					if (text.getIdx() >= text.getRowSize() && text.isLast()) continue;
					text.remove();
					if (text.getIdx() >= text.getRowSize() && !text.isLast()) {
						text.moveDown();
						text.moveTo(1);
						text.insertBefore('|');
						text.moveLeft();
					}
					else if (text.getIdx() < text.getRowSize()) {
						text.moveRight();
						if (text.getIdx() >= text.getRowSize()) text.insertAtTail('|');
						else {
							text.moveRight();
							text.insertBefore('|');
							text.moveLeft();
						}
					}
				}
			}
			else {
				char ch = key;
				if (ch == 27) { // Escape key
					system("cls");
					break;
				}
				else if (ch == 13) { // Enter Key
					text.copyIntoStack(remaining);

					text.remove();
					text.addRow();
					text.insertAtTail('|');
					while (!remaining.isEmpty()) {
						text.insertBefore(remaining.top());
						remaining.pop();
					}
				}
				else if (ch == 8) { // BackSpace
					if (text.getIdx() <= 1 && !text.isFirst()) {
						text.remove();
						text.moveUp();
						text.insertAtTail('|');
					}
					else {
						deleted.push_back(text.removeBefore());
					}
				}
				else if (ch == 26) { // ctrl + z
					text.insertBefore(deleted.top());
					deleted.pop();
				}
				else { // normal characters
					text.insertBefore(ch);
				}
			}
			system("cls");

			text.display();
		}
	}
}

void validateInput(int& input) {
	do {
		cout << "1. Create New File\n";
		cout << "2. Load Existing file\n";
		cout << "3. Exit!\n";
		cin >> input;

		if (input > 3 || input < 1) {
			system("cls");
			cout << "\nInvalid Input! Try Again!\n";
		}
	} while (input > 3 || input < 1);
}

int main() {
	int input = 0;
	string name;

	while (true) {
		myStack<char> deleted, remaining;

		rowsList<char> text;

		validateInput(input);

		if (input == 3) break;

		if (input == 2) {
			cout << "Enter File Name: ";
			cin >> name;
			text.load(name);
		}
		text.insertAtTail('|');

		system("cls");
		text.display();
		editFile(text, deleted, remaining);
	}
	
	return 0;
}

// Escape 27
// Backspace 8
// Enter 13

// ctrl + z = 26, redo deleted character
// ctrl + s = 19, save file
// ctrl + d = 4, back to menu