// --------------------------------------------------------------------------
// CHILDRENBOOK_H_
// Author: Clement Gomiero
// --------------------------------------------------------------------------
// ChildrenBook is a subclass of media that will create a children book 
// that will then be stored
// The class:
// -- Allows to create a new children book object
// -- Allows to compare two children books (the books will be stored in a BST)
// -- Allows to display the book in a specific format
// -- Allows to perform a transaction like return or checkout
// 
// Implementation and Assumptions:
// -- The book must have a title, an author and a data
// -- The data can only be set from reading a file
// --------------------------------------------------------------------------

#ifndef CHILDRENBOOK_H_
#define CHILDRENBOOK_H_

using namespace std;
#include <string>
#include <iostream>
#include <iomanip>
#include "media.h"

class ChildrenBook : public Media
{
public:
	ChildrenBook();
	~ChildrenBook();
	//create methods assign the data from a file
	virtual Media* create(istream& infile);
	virtual Media* createTransBook(istream& infile);
	virtual string getTitle();

	//display: output the books 
	virtual void displayBook() const;
	virtual void displayAllInfo() const;

	//perform transaction
	bool checkOut() override;
	bool returnBook() override;

	//overload comparator operator
	virtual bool operator <(const ChildrenBook&) const;
	virtual bool operator >(const ChildrenBook&) const;
	virtual bool operator ==(const ChildrenBook&) const;
	virtual bool operator !=(const ChildrenBook&) const;

	bool operator <(const Media&) const override;
	bool operator >(const Media&) const override;
	bool operator ==(const Media&) const override;
	bool operator !=(const Media&) const override;
private:
	string title = " ", author = " ";
	int year;
	int available = 5;
};
#endif
