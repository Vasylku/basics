#include <iostream>
using namespace std;

#define MAX 10

class Queue {
	int arr[MAX];
	int front;
	int rear;
	int size;
public:

	Queue() {
		size = 0;
		front = -1;
		rear = -1;
	}
	bool isFull() {

		return (rear + 1) % MAX == front ? true : false;
	}
	bool isEmpty() {
		return ((rear == -1) && (front == -1));

	}
	void push(int x) {
		if (isFull()) {
			cout << "\nQ is full" << endl;
			return;
		}
		if (isEmpty()) {
			rear = front = 0;
		}
		else {
			rear = (rear + 1) % MAX;
		}
		size++;
		arr[rear] = x;


	}
	int pop() {
		int x;
		if (isEmpty()) {
			cout << "\nQ is empty" << endl;
		}
		if (front == rear) {
			rear = front = -1;
		}
		else {
			x = arr[front];
			front = (front + 1) % MAX;

		}
		size--;
		
		return x;
	}
	int peek_front() {
	
		if (isEmpty()) {
			cout << "\nQ is empty" << endl;
			return -1;
		}
		return arr[front];
	}
	int peek_rear() {
		return arr[rear];
	}
	int qsize() {
		int x = size;
		return x;
	}


	void Print()
	{
		// Finding number of elements in queue  
		//int count = (rear + MAX- front) % MAX + 1;
		cout << "\nQueue : ";
		for (int i = 0; i < qsize(); i++)
		{
			int index = (front + i) % MAX; 
			cout << arr[index] << " ";
		}
		cout << "\n\n";
	}

};