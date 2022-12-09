#include <iostream>

using namespace std;
#define capacity 256

class Stack {
	int top;

public:
	char arr[capacity];
	
	Stack() {
		top = -1;
	}

	bool isFull() {

		return top >= capacity;
	}
	bool isEmpty() {
		return (top == -1);

	}

	void push(int x) {
		if (isFull()) { cout << " \nStack is full" << endl;return; }
		
		arr[++top] = x;
	
	}
	
	int pop() {
		if (isEmpty())cout << "\nStack is empty" << endl;
	
		return arr[top--];

	}
	
	int  peek() {
		
		return arr[top];
	}
	
	void showStack() {
		
		for (int i = 0; i <= top; i++){
			cout<<arr[i] << " ";
		}

	

	}
};