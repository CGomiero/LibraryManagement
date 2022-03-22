// ----------------------------------------------------------------------------
// RETURNBOOK_H_
// ----------------------------------------------------------------------------
// The class Return is used to perform a return to a libary and store the
// transaction in the patron profile. Return is a subclass of Transaction
// The class: 
// -- Allows to display the transaction object
// -- Create a transaction object
// -- Allows to execute a transaction, meaning it check out the book to the 
// patron
// -- Allows to read from a file
// Implementation and Assumptions:
// -- The manager is not a nullptr
// -- The class create a pointer to a Media book
// -- Find the patron from the ID
// -- Make the transaction
// ----------------------------------------------------------------------------
#ifndef RETURNBOOK_H_
#define RETURNBOOK_H_

#include "transaction.h"
#include "mediafactory.h"
#include "manager.h"
#include <iomanip>

using namespace std;
class ReturnBook: public Transaction
{
public:
	ReturnBook();
	~ReturnBook();
	// make the return using the book and the patron
	virtual bool execute(Manager* manager, char type, istream& infile);
	//output the type of transaction and the book
	virtual void display() const;
	//return a pointer of a transaction
	virtual Transaction* create();
private:
	int patronID;
	Media* tempBook;
	Media* targetBook;
	Patron* patronPtr;
	string transType = "Return";
	char bookType, hardCopy, charType;
};

#endif