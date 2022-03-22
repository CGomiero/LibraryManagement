// --------------------------------------------------------------------------
// PERIODICALBOOK_H_
// Author: Clement Gomiero
// --------------------------------------------------------------------------
// PeriodicalBook is a subclass of media that will create a periodical book 
// that will then be stored
// The class:
// -- Allows to create a new periodical book object from a file
// -- Allows to compare two periodical books (the books will be stored in a BST)
// -- Allows to display the book in a specific format
// -- Allows to perform a transaction like return or checkout
// 
// Implementation and Assumptions:
// -- The book must have a month, year, and title
// -- The data can only be set from reading a file
// --------------------------------------------------------------------------
#ifndef PERIODICALBOOK_H_
#define PERIODICALBOOK_H_

#include <string>
#include <iomanip>
#include <iostream>
#include "media.h"
using namespace std;

class PeriodicalBook : public Media
{
public:
	PeriodicalBook();
	~PeriodicalBook();
	// create methods set data to the media object from a file
	virtual Media* create(istream& infile);
	virtual Media* createTransBook(istream& infile);
	virtual string getTitle(); 

	//display output the book in a specific format
	virtual void displayBook() const;
	virtual void displayAllInfo() const;

	//perform transaction
	bool checkOut() override;
	bool returnBook() override;

	//overload operators
	bool operator <(const PeriodicalBook&) const;
	bool operator >(const PeriodicalBook&) const;
	bool operator ==(const PeriodicalBook&) const;
	bool operator !=(const PeriodicalBook&) const;

	bool operator <(const Media&) const override;
	bool operator >(const Media&) const override;
	bool operator ==(const Media&) const override;
	bool operator !=(const Media&) const override;
private:
	string title = " ";
	int year, month;
	int available = 1;
};
#endif
