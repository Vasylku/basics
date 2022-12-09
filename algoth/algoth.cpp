// algoth.cpp : This file contains heaps, searches, sortes
//
/*

void findMe(treeNode* x, int me)
treeNode t;
bool search =true;
t=root;
while(search){
if(me == t->data){search =false; cout<<"found!;
}else if(me<t_.data){
t=t->left;
}elase if (me<t->data){
t=t->right;
}
}
reccursive find the lowest one
void find(treeNode t){
if(t->left == null){
cout<<"t->data;}
elase{
find(t->left);
}
}
heap sort based on heaps
heap tree(complete binary tree) like structure in nwhich the root is greater than the child, this carried alwaays through every subtree of heap

 left Child = 2 *parent;
 right child = 2*parent +1;
 parent = int(child/2);
 heap is good for, root is the biggest.
 arr start at 1 which is a index of root heap
 */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//   int arr[8];
   //void buildHeap();
  // void heapify();

//
//void buildHeap(int array[], int n) {
//    int len = 1;
//   
//    int arr[n+1];
//   while (items in arrr) {
//        int  num = array[i]; //i++;
//        arr[len] = num;//array to declare as class variable of?( heap class)
//        heapify(1, len);
//        len = len + 1;
//
//   }
//}
////call over and over to bubble items to root
//
//void heapify(int root, int leaf)
//{
//    int parent;
//    if (leaf > 1) {
//       int parent = leaf / 2;
//    }if (arr[leaf] > arr[parent]) {
//        exchange(leaf, parent);
//        heapify(root, parent);
//
//    }
//}
//
//void heapSort()
//{
//    int len, last;
//    len = buildHeap(..);
//    last = len - 1;
//
//    for (int i = 1; i < len; i++) {
//        exchange(1, last);
//        last = last - 1;
//        reheapify(1, last);
//    }
//
//}
//     
//void reheapify(int j, int last)
//{
//    int lChild, rChild;
//    int k;
//    lChild = 2 * j;
//    rChild = 2 * j + 1;
//    if ((lChild < last) && (rChild <= last)) {
//        if ((arr[j] < arr[lChild]) || (arr[j] < arr[rChild])) {
//            k = lChild;
//            if (arr[lChild] < arr[rChild]) {
//                k = rChild;
//            }
//            exchange(j, k);
//            reheapify(k, last);
//        }
//    }
//    else if (lChild <= last) {
//        if (arr[j] < arr[lChild]) {
//            exchange(j, lChild);
//        }
//    }
//}
//


/*
quick sort n log n on avarge
select pivot numbeer
arrange array so that numbers left of pivot are less than pivot, numbers right of pivot a greater
do quick sort on arrayParts left and right of pivot

*/
int g = 0;
int co(int x) {
	g +=x;
	return g;
}
void cot() {
	cout << g;
}
void exch(int* x, int* y) {
	int t = *x;
	*x = *y;
	*y = t;
}

void print(int ar[], int n) {
	int p = 1;
	for (int i = 0; i < n;i++) {
	
		cout << left << setw(10) << ar[i] << " ";
		
		if (p == 10) {
			cout << endl; p = 0;
		}
		p++;
	}
}

int rear(int arrays[], int left, int right, int p) {
	//while (left <= right) {
	//	while (arrays[right] > pivotVal) {

	//		right=right-1;
	//	}
	//	if (right!=left) {
	//		exch(&arrays[right], &arrays[left]);
	//	}
	//	while (arrays[left] < pivotVal) {
	//		left=left+1;
	//	}
	//	if (right != left) {
	//		exch(&arrays[right],&arrays[left]);
	//	}
	//}
	int x = 0;
	
	while (left <= right) {
	
		
		while (arrays[left] < p) {
			left++;
			
			x++;
		}
		while (arrays[right] > p) {
			right--;
		
			x++;
		}
		if (left<=right) {
			x++;
			
			exch(&arrays[left], &arrays[right]);
			left++;
			right--;
		}
		
	}
	co(x);
	return left;
}
void quicks(int arrays[],int lb, int ub) {//lower bound upper bound
	if (lb < ub) {
		int x = 0;
		int pivot =arrays[(lb + ub) / 2];
		
		int  index = rear(arrays , lb, ub, pivot);
		
		quicks(arrays, lb, index - 1);
		
		quicks(arrays, index , ub);
		

	}
}

//selection
void  selectionS(int list[], int n) {
	int j, k;
	int min;
	int x = 0; 
	int s = 0;
	for (j = 0; j < n; j++) {
		min = j;
		for (k = j + 1; k < n; k++) {
			x++;
			if (list[k] < list[min]) {
				min = k;
				s++;
			}
		}
		
		exch(&list[j], &list[min]);
		/*int t = j;
		j = min;
		min = t;*/
	}
	cout << "\n" << x << "____:" << s << "\n";
}
void bubl(int arr[], int n) {
	int j;
	bool swap = true;
	int x=0, s = 0;
	while (swap) {
		swap = false;
		for (j = 1; j < n; j++) {
			x++;
			if (arr[j - 1] > arr[j]) {
				swap = true;
				s++;
				exch(&arr[j - 1], &arr[j]);
			}
		}
	}
	cout << "\n" << x << "____:" << s << "\n";
}
//bubble 2
void bb(int arr[], int n) {
	int swap = 0;
	int x = 0;
	int s = 0;
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n -i-1; j++) {
			x++;
			if (arr[j] > arr[j+1]) {
				s++;
				exch(&arr[j], &arr[j+1]);
				swap = 1;
			}
		}
		if (swap == 0) break;
	}
	cout << "\n" << x << "____:"<< s << "\n";
}
// uses a  property of a data, sort radix, 390, 411, 280, 161, 431, 415, 479, 339, 391, 285, 102
//bucket sort; no compares done  just pick a number a nd put in bucket O(n +m ), keep tail and user linkelist?
/*
class Wend

1000 numbers find 5 smallest numbers?


*/
/*
SEARCHEs, Binary search//




*/
int bin(int arr[], int len, int x) {
	int left = 0;
	int right = len - 1;
	bool found = false;
	int mid;
	while (!found) {
		 mid = left + (right - left) / 2;
		if (arr[mid] == x) {
			found = true;
		}
		else if (arr[mid] < x) {
			left = mid;
		}
		else right = mid;



	}

	return mid;
}
int findIt(int arr[], int len, int x) {
	int j = 0;
	bool found = false;
	while ((!found) && (j < len)) {
		if (arr[j] == x) {
			found = true;
		}
		else {
			j++;
		}

	}
	if (!found) j = -1;

	return j;
}
int main()
{
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
	//int arrays[8] = { 25,57,48,37,12,92,86,33};
	//print(arr, 1000);
	cout << endl;
	//quicks(arr, 0,999);
	//bb(arr, 1000);
	//bubl(arr, 1000);
	selectionS(arr, 1000);
	print(arr, 1000);
	// cot();
	// int arr[] = { 3,8,6,4,9,7,1 };
   //  buildHeap(arr, 7);
	cout << "\n" << findIt(arr, 1000, 7);
}



