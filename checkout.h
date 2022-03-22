// ----------------------------------------------------------------------------
// CHECKOUT_H_
// ----------------------------------------------------------------------------
// The class CheckOut is used to perform a checkout to a patron and store in 
// its profile. CheckOut is a subclass of Transaction
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

#ifndef CHECKOUT_H_
#define CHECKOUT_H_

#include "transaction.h"
#include "media.h"
#include "mediafactory.h"
#include "manager.h"
#include <iomanip>

using namespace std;
class CheckOut: public Transaction
{
public:
	CheckOut();
	~CheckOut();
	// make the check out using the book and the patron
	virtual bool execute(Manager* manager, char type, istream& infile);
	virtual void display() const; // display the transaction
	virtual Transaction* create(); // return a pointer of the object
private:
	int patronID;
	Media* tempBook;
	Media* targetBook;
	Patron* patronPtr;
	string transType = "CheckOut";
	char bookType, hardCopy, charType;
};
#endif
