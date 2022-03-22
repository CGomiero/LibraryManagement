// ----------------------------------------------------------------------------
// MANAGER_H_
// ----------------------------------------------------------------------------
// The class Manager is the main class that takes in all the needed files for
// the library(Media), patrons and transactions. Read the transactions and 
// execute them.
// The class:
// -- Allows to read Media and store them in the library object
// -- Allows to read Patrons and store them in the patron container
// -- Allows to read Transactions that will be stored in the patron object
// -- Allows to return a book, get a book from the library and get a patron
// Implementation and Assumptions:
// -- Manager will be the first class to take in the text file 
// -- The library and patron container needs to be initiliaze before the 
// transaction file is added. 
// -- Type of transaction 'D' is the only type outside the transaction class
// as it needs to output all the library.
// ----------------------------------------------------------------------------
#ifndef MANAGER_H_
#define MANAGER_H_

#include <istream>
#include <iostream>

#include "media.h"
#include "mediafactory.h"
#include "library.h"
#include "patroncontainer.h"
#include "transactionfactory.h"
using namespace std;
class Manager
{
public:
	Manager();
	Manager(istream& infile);
	~Manager();
	//input file methods
	void inputMediaFile(istream&);
	void inputPatronFile(istream&);
	void inputTransactionFile(istream&);

	//display methods
	void displayLibrary() const;
	void displayOneType(char) const;

	// get book or patron methods
	bool getBook(Media* target, Media*& data, char bookType);
	Patron* getPatron(int targetID);
private:
	Library allBooks;
	PatronContainer allPatrons;
};
#endif
