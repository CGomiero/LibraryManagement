// ----------------------------------------------------------------------------
// MEDIAHASHTABLE_H_
// ----------------------------------------------------------------------------
// MediaHashTable class stores all books in categories.
// The class:
// -- Allows to insert a Media/books
// -- Allows to retrieve one Media object
// -- Allows to remove a Media
// Implementation and Assumptions
// -- The size of the hashTable will not exceed 10000
// ----------------------------------------------------------------------------

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <list>
#include "patron.h"
using namespace std;

const int kMaxSize = 10000;
class HashTable
{
public:
	HashTable();
	~HashTable();
	bool insertItem(Patron*);
	bool deleteItem(Patron*);
	Patron* getPatron(int index);
	void displayHash();

private:
	list<Patron*> table[kMaxSize];
	int getHash(int index);
};
#endif
