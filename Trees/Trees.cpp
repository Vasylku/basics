
/*

 Binary trees:
 O(log2n)huge efficiency gains
 verythimng to right greater than root, to left smaller then root
O(n logn) tree order
bubble sort is O(n^2)
if 1000 numbers log n is 10 (== 10000)
1000^2 is millbest correct count is 921000 or 425000

*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#define capacity 100
//ugly stack
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
		//return -1;
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
		//destructor
	}
};
class treeNode {
public: int data;
	    int f;
	    treeNode* left, * right;
};
treeNode* root;

class tree {
public:
	void init() {
		root = NULL;
	}
	treeNode* makeTree(int n) {
		treeNode* t = new treeNode;
		t->data = n;
		t->f = 1;
		t->left = NULL;
		t->right = NULL;
		return t;
	}
	void setLeft(treeNode* t, int n) {
		if (t->left != NULL) {
			cout << "Error: Left node is already exist";
		}
		else {
			t->left = makeTree(n);
		}

	}
	void setRight(treeNode* t, int n) {
		if (t->right != NULL) {
			cout << "Error: Right node already exists.";
		}
		else {
			t->right = makeTree(n);
		}


	}
	int build(int list[], int n) {
		int j, num;
		int loops = 0;//count # of comparisons done while building a tree O(logn)
		bool search;
		treeNode* curr;
		init();
		for (j = 0; j < n; j++) {
			num = list[j];
			if (j == 0) {
				root = makeTree(num);
			}
			else {
				search = true;
				curr = root;
				while (search) {
					if (num == curr->data) {
						// cout << "duplicate";// increment frequency of some number but store olny one
						curr->f++;
						loops = loops + 1;
						search = false;
					}
					else if (num < curr->data) {
						loops = loops + 2;
						if (curr->left == NULL) {
							curr->left = makeTree(num);
							search = false;
						}
						else {
							curr = curr->left;
						}
					}
					else if (num > curr->data) {
						loops = loops + 3;
						if (curr->right == NULL) {
							curr->right = makeTree(num);
							search = false;
						}
						else {
							curr = curr->right;
						}
					}
				}
			}
		}
  return loops;
}
	//in order
	void inO(treeNode* t) {
		if (t->left != NULL) {
			inO(t->left);
		}
		while (t->f != 0) {//with duplicates
			cout << left << setw(7) << t->data;
			t->f--;
		}
		//cout << (t->data) << " "; cout no duplicates

		if (t->right != NULL) {
			inO(t->right);
		}
	}
	//pre order
	void preO(treeNode* t) {
		cout << (t->data) << " ";
		if (t->left != NULL) {
			inO(t->left);

		}
		if (t->right != NULL) {
			inO(t->right);
		}
	}
	//post order
	void postO(treeNode* t) {
		if (t->left != NULL) {
			postO(t->left);

		}
		if (t->right != NULL) {
			postO(t->right);
		}
		cout << (t->data) << " ";
	}
	//iterative solution of in order
	void inO_it(treeNode* root) {
		Stack <treeNode*> s;
		treeNode* p = new treeNode();
		init();
		p = root;
		s.push(root);
		do {
			while (p != NULL) {
				s.push(p);
				p = p->left;
			}
			if (!s.isEmpty()) {
				p = s.pop();
				//include duplicates
				while (p->f != 0) {
					cout << left << setw(7) << p->data;
					p->f--;
					
				}	
				p = p->right;
			}
		} while (!(s.isEmpty()) || (p != NULL));
	}
};
//swap for bubble
void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
//sort bubble
int bubl(int arr[], int n) {
	bool swapping = true;
	int j;
	int count = 0;//count numberof compares
	while (swapping) {
		swapping = false;
		for (j = 1;j < n;j++) {
			//put here compares count
			count++;
			if (arr[j - 1] > arr[j]) {
				swap(arr[j - 1], arr[j]);
				swapping = true;
			}
		}
	}
 return count;
}
void printArray(int arr[], int size)
{
	int i;	int k = 0;
	for (i = 0; i < size; i++) {
	
		cout << left<< setw(7) << arr[i];
		k++;
		if (k == 20) { cout << endl;k = 0; }
	}
}
int main()
{
	tree* x = new tree();
	// int arr[12] = { 12,19,3,7,20,22,10,6,12,13,17,10 };
	// int n = sizeof(arr) / sizeof(arr[0]);
	// cout<< x->build(arr, n);
	//x->inO(root);
	//cout << endl;
	//x->preO(root);
	//cout << endl;
	// x->inO_it(root); cout << endl;
	//bubl(arr, n);
	// printArray(arr, n);
	fstream f;
	f.open("nums.txt");
	int arr[1000];
	int n = sizeof(arr) / sizeof(arr[0]);
	if (f.is_open()) { 
		for (int i = 0; i < 1000; i++) {
			f >> arr[i];

		}
		f.close();
	}

	else {

		cout << "\nUnable to popen file!\n";
	}
	int k = 0;
	for (int j = 0; j < 1000; j++) {
		if (arr[j] == 100) { k++; }
		
	}
	cout << k;
	/*cout << "Bubble sort: " << left << setw(15) << " Binary Tree\n";
	cout << left << setw(15) << (bubl(arr, n)) << x->build(arr, n) << endl;*/
	//cout << " ----------BUBBLE SORT---------- " <<"\n"<< endl;
	//cout << "Number of compares: "<< bubl(arr, n) << "\n"<<endl;
	//printArray(arr, n);


	cout << " ----------BINARY TREE---------- " <<"\n"<< endl;
	cout << "Number of compares: "<< x->build(arr, n) << "\n"<<endl;
	x->inO_it(root);
	//x->inO(root);

}