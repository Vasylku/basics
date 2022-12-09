

using namespace std;


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

	int l = str.length();

	int i = 0;
	while (i < l) {

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
	cout<< ev.pop();
}


