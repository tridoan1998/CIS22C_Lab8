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
	if(Table[index].isEmpty())
		insert(b);
	else if()
}

//inserts a new book into the table
//calls the hash function on the key to determine
//the correct bucket
