#include <iostream>
#include <string>
#include "stack.cpp"
#include <fstream>
using namespace std;


bool validation(string str);
void convertion(string str);
void evaluation(string str);

void f2() {
	cout<< " NOT valid ";
}
void f(string l) {
	
	



}
int main()
{
	//string r = "(5+3)+(3+2)";
	//convertion(r);
string c = "53+32+";
     evaluation(c);
	
	//int size = 0;
	string line;
	//string p[10];
	string file_name = "decode_text.txt";
	fstream my_file;
	my_file.open(file_name, ios::in);
	if (!my_file) {
		cout << "No such file";
	}
	else {


		int i = 0;
		while(!my_file.eof())
		{
			getline(my_file, line);
		 convertion(line);
		//	validation(line) ? f(line) : f2();
			cout << endl;
		/*	p[i] = line;
			i++;
			size++;*/
			//	

		}
		
	}
	my_file.close();
	//int j = 0;
	//while (j<size) {
	//	cout << p[j] << " ";
	//	//validation(p[j]) ? convertion(p[j]) : f2();
	//    cout<< endl;
	//	j++;
	//}

}

bool validation(string str) {
	Stack s;

	int i = 0;
	while (str[i] != '\0') {

		if (str[i] == '(') {
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			if (s.isEmpty()) {
				//cout << " Too many ')'";
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

/*if (s.isEmpty())
	{cout << "Valid equation!";
}
else {
	cout << "Error: Too many '('";
}*/

void convertion(string str) {
	Stack post;
	Stack op;

	int i = 0;
	while (str[i] != '\0') {

		if (isdigit(str[i])) {
			post.push(str[i]);
		}
		else if ((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/')) {
			op.push(str[i]);
		}
		else if (str[i] == ')') {
			//	myOp = op.pop();
			post.push(op.pop());
		}
		i++;
	}
	while (!op.isEmpty()) {
		//myOp = op.pop();
		post.push(op.pop());
	}
	post.showStack();
}
void evaluation(string str) {
	Stack ev;
	int i = 0;
	int x = 0;
	int y = 0;
	int z = 0;
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
	cout << ev.pop();
}

