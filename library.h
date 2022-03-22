// --------------------------------------------------------------------------
// LIBRARY_H_
// --------------------------------------------------------------------------
// Library class is used to store all the different type of books in a BST
// designated for the specific type of book. 
// It will also handle the checkout, and the return of any books too
// The class:
// -- Allows to store a a book in its own type tree
// -- Allows to add up to 26 trees
// -- Allows to retrieve a book for checkOut or return
// -- Allows to insert and remove a book from a tree
// -- Allows to insert a book in the right tree using the char type 
// assign to it
// Implementation and Assumptions:
// -- The maximum amount of trees is 26 
// -- The char type will not repeat
// -- If a new type is added then a container needs to be created 
// in constructor
// --------------------------------------------------------------------------
#ifndef LIBRARY_H_
#define LIBRARY_H_

#include "bstree.h"
#include "media.h"
#include <array>
#include <iomanip>

#define MAXITEMS 26 //the amount can increase
using namespace std;
class Library
{
public:
	Library();
	~Library();
	bool insert(Media*, char);
	bool remove(Media*, char);
	bool retrieveBook(Media* target, Media*& data, char type);
	bool checkOut(Media*, char);
	bool returnBook(Media*, char);
	void displayOneType(char) const;
	void displayAllLibrary() const;
	int hash(char) const;
private:
	BSTree* container[MAXITEMS]; //an array that will hold all the different type of books
				  //allows to easily add a new type of media too
};
#endif

