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



//counts the number of Books at this index
//returns the count
//pre: 0<= index < SIZE
