#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Node {
public:
	string name;
	int data;
	int len;
	Node* next;
	Node* firstName;
	char ch;

};
Node* head;
class link {
public:

	void init() { head = NULL; }
//build indexed list
	Node* makeIndex() {
		Node* spot = new Node;
		char currChar = 'a';
		Node* arr = new Node[26];
		for (int i = 0; i < 26; i++) {
			arr[i].ch = currChar;
			spot = find_spot(currChar);

			if (spot->ch != currChar) {
				arr[i].firstName = NULL;
			}
			else {
				arr[i].firstName = spot;
			}
			currChar++;
		}
		return arr;
	}	//	}
		/*for (int j = 0; j < 26; j++) {
			if (arr[j].firstName != NULL) {
				cout << (arr[j].firstName->name) << endl;

			}
			else cout << "Null" <<endl;
		}*/
		/*int i = 0;
		Node* s = new Node;
		s = arr[1].firstName;
		cout << s->next->next->next->name;*/
	void showNodeArr() {
		Node* arr = makeIndex();
		for (int j = 0; j < 26; j++) {
			if (arr[j].firstName != NULL) {
				cout << (arr[j].firstName->name) << endl;
			}
			else cout << "Null" << endl;
		}
	}

	Node* make_node(int n, string s) {
		Node* temp = new Node();
		temp->data = n;
		temp->name = s;
		temp->ch = temp->name[0];
		temp->next = NULL;
		return temp;


	}
	Node* find_tail() {
		Node* temp = new Node;
		temp = head;
		while (temp->next != NULL) {
			temp = temp->next;

		}
		return temp;
	}
	/*void buildNode(int len) {

		int j;
		Node* tail;

		init();
		for (j = 0; j < len; j++) {
			if (j == 0) {
				head = make_node(j);
			}
			else {
				tail = find_tail();
				tail->next = make_node(j);
			}
		}
	}*/
	void showList() {
		Node* temp = head;
		int k = 1;
		while (temp != NULL) {

			cout << left << setw(15) << temp->name;
			if (k == 10) {
				cout << "\n"; k = 0;
			}
			temp = temp->next;
			k++;
		}
		cout << endl;
	}
	/*Node* find_spot(int n) {
		Node* curr; Node* prev;
		curr = head;
		prev = curr;

		while (curr->data < n) {
			prev = curr;
			curr = curr->next;
		}
		return prev;
	}*/
	//find spot by a checking character
	Node* find_spot(char t) {
		Node* curr, * prev;
		curr = head;
		prev = curr;                  //- 'a' < t - 'a'
		while (curr != NULL && curr->name[0] <t) {
			prev = curr;
			curr = curr->next;

		}
		return curr;

	}
	/*int showd(Node* d) {

		return d->name;
	}*/

	/*Node* insert_after(Node* spot, int n_data) {
		Node* t = make_node(n_data);
		t->next = spot->next;
		spot->next = t;

	}*/
	void del_front() {
		Node* t = head;
		head = t->next;
		delete t;
	}
	void del_spot(Node* spot) {
		if (spot == head) { del_front(); }
		//not deleting second node after head.
		else {

			Node* del = new Node;
			del = spot->next;
			spot->next = del->next;
			delete del;
		}
	}
	//general delete
	void general_del(string n) {
		Node* t = head;
		Node* prev;
		Node* curr;
		if (head->name == n) {
			head = t->next;
			delete t;
			return;
		}
		else {
			curr = head;
			prev = curr;
			while (curr != NULL) {
				prev = curr;
				curr = curr->next;
				if (curr == NULL) cout << "Name not found";
				else if (curr->name == n) {
					t = curr;
					prev->next = curr->next;
					delete t;
					return;
				}
				
			}
		}
	}
	void addBeg(int n) {
		Node* t = new Node;
		t->data = n;
		t->next = head;
		head = t;

	}
	//delete by given spot
	void del_n(int n) {
		Node* t = new Node;
		t = head;
		if (n == 1) { head = t->next;delete t; }
		else {

			for (int i = 0; i < n - 2; i++) {
				t = t->next;
			}
			Node* d = new Node;
			d = t->next;
			t->next = d->next;
			delete d;
		}

	}

//all 3 cases of insert, general insert
	void insert(int n, string s) {

		Node* curr;
		Node* prev;
		Node* temp;
		bool search;
		if (head == NULL) {
			head = make_node(n, s);

		}
		else if (n < head->data) {
			temp = make_node(n, s);
			temp->next = head;
			head = temp;
		}
		else {
			prev = head;
			curr = head;
			search = true;
			//int count help to check at node class if u have second name Bill
			while (search) {
				//while searching
				if (curr->data == n) {
					//cout << " duplicate\n"; 
					Node* t = make_node(n, s);
					t->next = curr->next;
					curr->next = t;

					search = false;
				}
				else if (curr->data < n) {
					//check if at the end of the list
					if (curr->next == NULL) {
						curr->next = make_node(n, s);
						search = false;
					}
					else {
						prev = curr;
						curr = curr->next;
					}
				}
				else if (curr->data > n) {
					temp = make_node(n, s);
					temp->next = curr;
					prev->next = temp;
					search = false;
				}
			}
		}
	}
	//find out length of whole list
	int length() {
		Node* u = head;
		int c = 0;
		while (u != NULL) {
			u = u->next;
			c++;
		}
		return c;
	}
	//print section length
	int sectionLen(char ch) {
		int length = 0;
		Node* s = makeIndex();
		Node* p;
		for (int i = 0; i < 26; i++) {
			if (s[i].firstName != NULL && s[i].firstName->name[0] == ch) {
				p = s[i].firstName;
				while (p != NULL && p->ch == ch) {
					length++;
					//cout << p->name;
					p = p->next;
				}
				//cout << s[i].firstName->name;
			}
			//else  cout << "N"			
		}
		return length;
	}
//print section of a list, starting with given character
	void printSec(char x) {
		Node* s = makeIndex();
		Node* p;
		for (int i = 0; i < 26; i++) {
			if (s[i].firstName && s[i].firstName->ch == x) {
				p = s[i].firstName;

				while (p != NULL && p->ch == x) {

					cout << p->name << " " << endl;
					p = p->next;
				}
				return;
				//cout << s[i].firstName->ch << " ";
			}

		}
		cout << "\nProvided character is not present in List\n\n";
	}

			/*for (int i = 0; i < 26; i++) {
				if (s[i].ch == ch) {
					p = s[i].firstName;
					while (p != NULL && p->ch == ch) {

						cout << p->name << " " << endl;
						p = p->next;
					}


				}*/

				/*if (s[i].firstName && s[i].firstName->name[0] == ch) {
					p = s[i].firstName;
					while (p != NULL && p->ch == ch) {

						cout << p->name << " " << endl;
						p = p->next;
					}
				}*/


	void menu() {

		char ch;
		char s;
		string n = "";
		for (;;) {
			do {
				cout << "1.Display the list " << endl;
				cout << "2.Request the length of the list" << endl;
				cout << "3.Delete name " << endl;
				cout << "4.Request the length of a section of the list" << endl;
				cout << "5.Print section " << endl;
				cout << "Press q to exit" << endl;
				cout << "Choose one option: ";
				cin >> ch;

			} while ((ch < '1' || ch > '5') && (ch != 'q'));

			if (ch == 'q') break;
			cout << "\n\n";

			switch (ch) {
			case '1':
				cout << "List of names: \n";
				showList();
				cout << endl;
				break;
			case '2':
				cout << "The length of the list is " << length() << "\n\n";
				break;
			case '3':

				cout << "Enter name to delete: ";
				cin >> n;
				general_del(n);

				cout << "\nName " << n << " succesfully deleted\n" << endl;
				showList();
				cout << endl;
				break;
			case '4':

				cout << "\n Enter section character: ";
				cin >> s;
				cout << "\nSection length of names starting with  '" << s << "'  is " << sectionLen(s) << endl;
				cout << endl;
				break;
			case '5':
				cout << "\nEnter section character to print: ";
				cin >> s;
				printSec(s);
				cout << endl;
				break;
			}
		}

	}
};/*
class Noded : Node{
public:
	char firstChar;
	Node* firstOne;
	//char arr[26];
	int len;
	void makeIndexList()
	{
		Node* spot = new Node;
		link* f = new link;
		char currChar;
		char arr[26];

		for (int i = 0; i < 26; i++) {
			currChar = 'a';
			arr[i]->firstChar = currChar;
			spot = f->find_spot(currChar);

			if ((spot == head) && (spot->name[0] > currChar)) {
				arr[i]->firstOne = NULL;
			}
			else {

				arr[i]->firstOne = spot;
			}
			currChar++;
		}
	}*/
	/*	spot = find_spot(currChar);
		if (spot==head) &&(spot.weight > (currChar)) {
			arr[i].firstOne = null;
		}
		else {
			arr[i].firstOne = spot;
		}
	}
}*/

int get_val(char v) {
	int val = (v - 'a');
	//cout << val << endl;
	return val;
}

/// <summary>

/// </summary>
/*void converttoDoubly() {
	Node* curr;
	head->next = head;
	curr = head;
	while (curr->next != NULL) {
		(curr->next)->prev = curr;
		curr = curr->next;

	}

}
void converttoDoublyBB() {

	Node* curr;
	Node* prev;
	curr = head;
	prev = head;
	while (curr != NULL) {
		curr->prev = prev;
		prev = curr;
		curr = curr->next;
	}
}

/*
eddy
(d -'a')*26^0
+
(d- 'a')*26^1
+
(e- 'a')*26^2
Index points to a first word in each section
array of indexes
class arrNodes{
char firstletter;
Node* findword;
int sectionLength; all the words that start with 'a' as example

}
indexNOde myIndex[26];
go in loop after you build list and fill array?

*/

//convert singlelinklist to dodublylinklist
//find the node in the middle of circulatr link list?
//delete nodes at front , back , middle


int main()
{
	
	//l->showList();
	//l->addBeg(8);
	//l->addBeg(10);
	//l->del_front();
	//l->del_spot(l->find_spot(1));l->showList();
	//l->insert(2);
	//l->insert(10);
	///l->showList();

	//read file
	link* l = new link;
	l->init();
	string line, in;
	
	cout << "Enter file name:  //exaxmple mytext.txt\n\n";
	cin >> in;
	
	int c = 0;
	fstream f(in);

	if (!f.is_open()) {

		cout << "Unable to open file!";
	}
	else {
		while (getline(f, line))
		{
			int nameCode = (get_val(line[0]) * (26 * 26)) + (get_val(line[1]) * (26)) + (get_val(line[2]) * (1));
			l->insert(nameCode, line);
			c++;
		}
		f.close();
		cout << endl;
		l->menu();
		
	}

}












//	int n = 9;cout << "\nData at spot: " << n << " is -> " << l->showd(l->find_spot(n)) << endl;