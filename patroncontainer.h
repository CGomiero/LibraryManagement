//----------------------------------------------------------------------------
// PATRONCONTAINER_H_
//----------------------------------------------------------------------------
// PatronContainer class is a class that is used to store all patrons
// in a hashtable
// The class:
// -- allows to add a patron  in the hashtable
// -- allows to remove a patron from the hashtable
// -- allows to display one patron information
// -- allows to display all patron information stored
// 
// Implementation and Assumptions:
// -- Every patrons will have a name and an id
// -- There will not be any duplicates
//----------------------------------------------------------------------------
#ifndef PATRONCONTAINER_H_
#define PATRONCONTAINER_H_

#include "patron.h"
const int kMaxSize = 10000;
class PatronContainer
{
public:
	PatronContainer();
	~PatronContainer();
	bool remove(Patron*);
	bool insert(Patron*);

	void displayPatron(int id);
	void displayAll();
	Patron* getPatron(int id);
	int getHash(int index);
private:
	Patron** allPatrons[kMaxSize];
};

#endif