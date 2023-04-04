//Elijah Turany
//CS244-002

/*
I used a stack for this implementation. I used a stack because the user said that 
they are frequently putting down and picking up the same tool. With a stack,
that tool can be placed on top, and picked up right away. If a queue was used 
instead, the tool would have to be placed at the bottom of the pile. Then
when the user looks for the tool they would have to go through the entire pile. 
*/
#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Inventory {
private:
	vector<string> toolStack;
	string heldTool{""};
public:
	Inventory() {}

	//Puts a string representing the tool at the back of the toolStack vector
	void push(string tool) {
		toolStack.push_back(tool);
	}

	//Returns the string at the back of the vector, and throws an exception if the vector is empty
	string top() {
		if (!isEmpty()) {
			return toolStack[toolStack.size() - 1];
		}
		else {
			throw "List is empty";
		}
	}

	//Removes the string at the back of the vector
	void pop() {
		if (!this->isEmpty()) {
			toolStack.pop_back();
		}
	}

	bool isEmpty() {
		return toolStack.empty();
	}

	int size() {
		return toolStack.size();
	}

	void findTool(string toolName) {
		//Initiates a second inventory object that will be used later
		Inventory secondStack;
		//Drops heldTool
		dropTool();
		//A for loop that will loop over the toolStack vector, starting from the back.
		//The back of the vector is considered the top of the stack.
		for (int i = toolStack.size()-1; i >= 0; i--) {
			//If the tool is found at a given index, heldTool is updated, and the tool is removed from the stack
			if (toolStack[i] == toolName) {
				heldTool = toolStack[i];
				pop();
				break;
			}
			//If the tool isn't at the given index, the tool at the index is pushed into a secondary stack
			//and removed from the toolStack
			else {
				secondStack.push(toolStack[i]);
				pop();
			}
		}
		//This for loop clears out the secondStack and pushes each item back into the itemStack
		for (int i = secondStack.size() - 1; i >= 0; i--) {
			push(secondStack.top());
			secondStack.pop();
		}
		
	}

	//Puts held tool at the top of the pile if there is a tool held,
	//and sets heldTool to a blank string
	void dropTool() {
		if (heldTool != "") {
			push(heldTool);
		}
		heldTool = "";
	}

	//Print method used for debugging
	void printStack() {
		for (int i = toolStack.size()-1; i >= 0 ; i--) {
			cout << toolStack[i] << endl;
		}
		cout << endl;
	}
};