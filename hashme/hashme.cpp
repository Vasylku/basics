// hashme.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int get_val(char ch) {

	int n = ch - 'a';

	return n;

}


class hashme {

public:
	int tableLen;
	int numSmashes;
	string* hashTable;
	hashme(int& l) {
		numSmashes = 0;
		tableLen = l;
		hashTable = new string[l];

		for (int i = 0; i < l; i++) {
			hashTable[i] = "#";

		}
	}
	void show() {
		int o = 1;
		for (int i = 0; i < tableLen; i++) {

			cout << setw(15) << left << hashTable[i] << " ";

			if (o == 10) { cout << endl; o = 0; }
			o++;
		}


	}
	int hashFun(string line) {
		int maxNameCode = 17575;
		int nameCode = (get_val(line[0]) * (26 * 26)) + (get_val(line[1]) * (26)) + (get_val(line[2]) * (1));
		int divider = (maxNameCode / (tableLen -8));
		int hashVal = ((nameCode / divider) % tableLen);
		cout << "\n" << divider << " " << hashVal;
		return hashVal;
	}
	/*int getNextOpenPosition(int hash) {
		int position = 1;
		if(hashTable[hash + position] != "#") {
			position++;
		}
		int newIndex = (hash + position)%tableLen;
		return newIndex;
	}*/

	int getNextOpenPosition(int hash) {
		
		for (; ;hash++) {
			if (hashTable[hash] == "#") return hash;
			numSmashes++;
		}
		
		/*while (hashTable[hash] != "#") {
			hash++;
			numSmashes++;
		}
		int position = hash;
		return position;*/
	}
	void insertItem(int hash, string line)
	{

		if (hashTable[hash] == "#") {

			hashTable[hash] = line;

		}
		else {
		 
			int newi = getNextOpenPosition(hash);
			hashTable[newi] = line;

			//numSmashes++;
			   //for (; ;hash++) {
			   // 
			   //	numSmashes++;
			   //while(hashTable[hash] != "#"){
			   //	//if (hashTable[hash] == "#") {
			   //	hash++;
			   //	//	break;
			   //	}	hashTable[hash] = line;
		   //	}
		}
	}
	void read_file() {
		string line, in;
		//code for user input the file name
		//cout << "Enter file name:  //exaxmple mytext.txt\n\n";
		//cin >> in;
		fstream f("textme.txt");

		if (!f.is_open()) {

			cout << "Unable to open file!";
		}
		else {
			while (getline(f, line))
			{

				int hash = hashFun(line);
				insertItem(hash, line);

			}
			f.close();
			cout << endl;
		}
	}
};

int main()
{
	int y = 700;
	hashme* h = new hashme(y);
	h->read_file();
	h->show();
	cout << "\nNumber of clashes: " << h->numSmashes;

};
