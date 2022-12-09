#include<iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
#define capacity 100


bool validate(const string& str);
string convert(const string& str);
float evaluation(const string& str);
int prior(char ch)
{
	switch (ch) {
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}
string write_back(string txt, string b,  string converted) {
	string text = " ";
	text += txt + " " + b + " " + converted+ "\n";

	return text;
}
void f1(string t) {
	//string txt = t;
	string tr = convert(t);
    float ev = evaluation(tr);
	
	cout << t << " " << "true " << "Postfix:" << tr << " Evaluation: " <<ev << endl;
	
}
void f(string t) { cout << t << " " << "false" << endl; }

template <class T> class Stack {
	int top;
	T arr[capacity];
public:
	Stack() {
		top = -1;
	}

	bool isFull() { return top >= (capacity - 1); }
	bool isEmpty() { return (top == -1); }

	void push(T x) {

		if (!isFull()) {
			arr[++top] = x;
		}
	}


	T pop() {
		if (!isEmpty()) {
			return arr[top--];

		}
	return -1;
	}
	T peek() { return arr[top]; }
	string state() {
		string r = " ";
		for (int i = 0; i <= top; i++) {
			r += arr[i];
		}
		return r;
	}
	~Stack()
	{

	}
};

int main() {

	string line;
	fstream myfile("example.txt");
	string p[10];
	if (myfile.is_open())
	{
		int i = 0;
		while (getline(myfile, line))
		{
			p[i] = line;
			i++;
		
		}
		myfile.close();
	}

	else cout << "Unable to open file";

	for (int j = 0; j < 8; j++) {
	
		validate(p[j]) ? f1(p[j]) : f(p[j]);
	}
	fstream f;


	f.open("gg.txt", ios::out);
	if (!f) {
		cout << "Error!";
		return -1;
	}
	for (int i = 0; i < 8; i++) {

		string t;
		f << p[i]<< (validate(p[i])? (t= convert(p[i])): "false" )<< " " << evaluation(t) << " \n";
	}f.close();
}

bool validate(const string& str) {
	Stack<char>s;

	int i = 0;
	while (str[i] != '\0') {

		if (str[i] == '(') {
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			if (s.isEmpty()) {				
				return false;

			}
			else {
				s.pop();
			}
		}
		i++;
	}
	return (s.isEmpty()) ? true : false;

}
string convert(const string& str) {
	Stack<char> post;
	Stack<char> op;
	int i = 0;
	while (str[i] != '\0') {
		if (isdigit(str[i])) {
			post.push(str[i]);
		}
		else if (str[i] == '(') {
			op.push(str[i]);
		}
		else if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') ||
			(str[i] == '/')) {
			if (!op.isEmpty() && prior(op.peek()) > prior(str[i])) {
				post.push(op.pop());
				op.push(str[i]);
			}
			else {
				op.push(str[i]);
			}
		}
		else if (str[i] == ')') {
			if (!op.isEmpty()) {
				while (op.peek() != '(') {
					post.push(op.pop());
				}
				op.pop();
				if (op.peek() != '(') post.push(op.pop());
			}
			else if (op.peek() != '(') post.push(op.pop());	
		}
		i++;
	}
	while (!op.isEmpty()) {
	
		post.push(op.pop());
	}
	return post.state();
}
float evaluation(const string& str) {
	Stack <float> ev;
	int i = 0;
	float x = 0.;
	float  y = 0;
	float z = 0;
	while (str[i] != '\0') {
		if (isdigit(str[i])) {
			ev.push(str[i] - '0');

		}
		else if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/')) {
			y = ev.pop();
			x = ev.pop();
			if (str[i] == '+') {
				z = x + y;
			}
			else if (str[i] == '-') {
				z = x - y;
			}
			else if (str[i] == '*') {
				z = x * y;
			}
			else {
				z = x / y;
			}
			ev.push(z);
		}
		i++;
	}
	return ev.pop();
}
