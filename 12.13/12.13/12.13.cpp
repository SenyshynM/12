#include <iostream>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <Windows.h>

#define size 256
using namespace std;

class Route {
public:
	Route* next;
	string start;
	string end;
	int number;

	Route() {
		this->next = NULL;
	}

	Route(string start, string end, int number = 0) {
		this->start = start;
		this->end = end;
		this->number = number;
		this->next = NULL;
	}

	~Route() {
		if (this->next != NULL)
		{
			delete this->next;
		}
	}
};

class HashTable {
	Route* table[size];

	static int hash(int key) {
		key *= key;          
		key >>= 11;        
		return key % 1024;
	}


public:

	HashTable() {
		for (int i = 0; i < size; i++) {
			table[i] = NULL;
		}
	}

	~HashTable() {
		cout << "Deleting table. . .\n";
		for (int i = 0; i < size; i++) {
			delete table[i];
		}
	}

	void push(string start, string end, int number) {
		int hashNumber = hash(number);
		Route* r = new Route(start, end, number);
		Route* p = table[hashNumber];
		if (p == NULL) {
			table[hashNumber] = r;
			return;
		}

		while (p->next != NULL) {
			p = p->next;
		}
		p->next = r;
	}

	Route* find(int number) {
		int hashNumber = hash(number);
		Route* result = table[hashNumber];
		if (!result) {
			cout << "Route not found" << endl;
			return NULL;
		}
		while (result->number != number) {
			if (!result->next) {
				cout << "Route not found" << endl;
				return NULL;
			}
			result = result->next;
		}
		return result;
	}
};

int main() {
	HashTable newTable;

	string start;
	string end;
	int number, i = 0, nomer;

	newTable.push("hh", "jj", 100);
	newTable.push("ff", "aa", 44);
	newTable.push("bn", "add", 232);
	newTable.push("hg", "de", 54);
	newTable.push("jn", "mh", 654);

/*
	do {
		cout << "start: "; cin.sync();
		cin >> start;
		cout << "end: "; cin.sync();
		cin >> end;
		cout << "number: ";
		cin >> number;
		cout << endl;
		newTable.push(start, end, number);
		i++;
	} while (i <= 5);
*/

	cout << "Enter number of route: "; cin >> nomer;

	Route* search = newTable.find(nomer);
	if (search) {
		cout << "Route with number " << search->number << ":" << endl;
		cout << endl;
		cout << "Start: " << search->start << endl;
		cout << "End: " << search->end << endl;
	}

	return 0;
}