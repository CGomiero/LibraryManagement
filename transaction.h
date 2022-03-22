// ----------------------------------------------------------------------------
// TRANSACTION_H_
// ----------------------------------------------------------------------------
// The class Transaction is an abstract class where all the different actions
// will take place
// Implementation and Assumptions:
// -- Provide an execute() method
// -- Provide a display and create method
// -- Always take in a file, manager, and the type
// ----------------------------------------------------------------------------
#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include <istream>
#include <iostream>

using namespace std;
class Manager;
class Transaction
{
public:
	Transaction();
	virtual bool execute(Manager* manager, char type, istream& infile) = 0;
	virtual void display() const = 0;
	virtual Transaction* create() = 0;
};
#endif
