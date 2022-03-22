#include "hashtable.h"

// ----------------------------------------------------------------------------
// Constructor:
// create the list of patron
// ----------------------------------------------------------------------------
HashTable::HashTable()
{

}

// ----------------------------------------------------------------------------
// Destructor:
// delete the table for potential memory leaks
// ----------------------------------------------------------------------------
HashTable::~HashTable()
{
	while (!table->empty()) {
		for (int i = 0; i < kMaxSize; i++) {
			if (table[getHash(i)].back() != nullptr) {
				delete table[getHash(i)].front();
				table->pop_front();
			}
		}
	}

}

// ----------------------------------------------------------------------------
// insertItem:
// add an item in the table using  the hash function to find the correct place
// ----------------------------------------------------------------------------
bool HashTable::insertItem(Patron* input)
{
	if (input->getID() > 9999 || input->getID() < 1000) {
		cout << "ID is invalid. Must be higher than 1000 and lower than 9999." << endl;
		return false;
	}
	int index = getHash(input->getID());
	table[index].push_back(input);
	return true;
}

// ----------------------------------------------------------------------------
// deleteItem:
// get the index and use an iterator to go over the list 
// erase the patron when it is find
// ----------------------------------------------------------------------------
bool HashTable::deleteItem(Patron* patron)
{
	int index = getHash(patron->getID());
	list<Patron*>::iterator i;
	for (i = table[index].begin(); i != table[index].end(); i++) {
		if (**i == *patron) {
			break;
		}
	}
	if (i != table[index].end()) {
		table[index].erase(i);
		return true;
	}
	return false;
}

// ----------------------------------------------------------------------------
// getPatron:
// return the patron from the table
// ----------------------------------------------------------------------------
Patron* HashTable::getPatron(int id)
{
	int index = getHash(id);
	for (list<Patron*>::iterator it = table[index].begin(); it != table[index].end(); it++) {
		if ((*it)->getID() == id) {
			return *it;
		}
	}
	return nullptr;
}

// ----------------------------------------------------------------------------
// displayHash:
// display every patron in the list
// ----------------------------------------------------------------------------
void HashTable::displayHash()
{
	for (int i = 0; i < kMaxSize; i++) {
		for (auto x : table[i]) {
			(*x).displayPatron();
		}
	}
}

// ----------------------------------------------------------------------------
// getHash:
// return the remaining of index modulus MAXSIZE
// ----------------------------------------------------------------------------
int HashTable::getHash(int index)
{
	return index % kMaxSize;
}
