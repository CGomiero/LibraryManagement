// --------------------------------------------------------------------------
// FICTIONBOOK_H_
// Author: Clement Gomiero
// --------------------------------------------------------------------------
// FictionBook is a subclass of media that will create an object of fiction 
// book
// The class: 
// -- Allows to create a new fiction book object
// -- Allows to compare two fiction books (the books will be stored in a BST)
// -- Allows to display the book in a specific format
// -- Allows to checkout and return a book
// 
// Implementation and Assumptions:
// -- The book must have a title, an author and a data
// -- The data can only be set from reading a file
// --------------------------------------------------------------------------

#ifndef FICTIONBOOK_H_
#define FICTIONBOOK_H_
#include <string>
#include <iomanip>
#include <iostream>
#include "media.h"
using namespace std;

class FictionBook : public Media
{
public:
	FictionBook();
	~FictionBook();

	//create methods set data to the Media by reading a file
	virtual Media* create(istream& infile);
	virtual Media* createTransBook(istream& infile);
	virtual string getTitle();

	//display output the book in a specific format
	virtual void displayBook() const;
	virtual void displayAllInfo() const;

	//perform the transaction
	bool checkOut() override;
	bool returnBook() override;

	//overload the comparator operators
	bool operator <(const FictionBook&) const;
	bool operator >(const FictionBook&) const;
	bool operator ==(const FictionBook&) const;
	bool operator !=(const FictionBook&) const;

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
