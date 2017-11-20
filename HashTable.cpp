//============================================================================
// Name        : Lab8.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstddef> //for NULL
#include <assert.h>
#include <string>
#include "HashTable.h"
#include "Book.h"
#include "BST.h"

using namespace std;

int HashTable::hash(string key) const
{

	int index;
	int sum = 0;
	for(unsigned int i = 0; i < key.length(); i++)
	{
		sum += (int)key[i];
	}
	index = sum % SIZE;

	return index;
}

int HashTable::countBucket(int index) const
{
	assert(0 <= index && index < SIZE);
	return Table[index].getSize();
}

int HashTable::search(Book b) const
{
	string key = b.get_title() + b.get_author();
	int index = hash(key);
	if (Table[index].isEmpty()) return -1;
	else if (!Table[index].search(b)) return -1;
	else return index;
}

void HashTable::insert(Book b)
{
	string key = b.get_title() + b.get_author();
	int index = hash(key);
	Table[index].insert(b);
}

void HashTable::remove(Book b)
{
	string key = b.get_title() + b.get_author();
	int index = hash(key);
	Table[index].remove(b);
}

void HashTable::printBucket(ostream& out, int index) const
{
	assert(0 <= index && index <= SIZE);
	Table[index].inOrderPrint(out);

}

//Prints all the books at index according to inOrderPrint
 //pre: 0<= index < SIZE
 //Should print according to the following formula:
 //Prints each book at that index in the format:
 //<title> by <author>
 //$<X.XX>
 //ISBN#: <isbn>
 //followed by a blank line

void HashTable::printTable(ostream& out) const
{

}
//Prints the first book at each index
//along with a count of the total books
//at each index by calling count_bucket
//as a helper function
//Prints in the format:
//Books in the Catalogue:
//<new line>
//Group <bucket>
//<title> by <author>
//$<X.XX>
//ISBN: <isbn>
//+<number of elements at this index> -1 more similar book(s)
//<new line><new line><new line>
