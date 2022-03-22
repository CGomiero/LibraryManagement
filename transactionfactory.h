// ----------------------------------------------------------------------------
// TRANSACTIONFACTORY_H_
// ----------------------------------------------------------------------------
// The class TransactionFactory determines which transaction object will be 
// created (return, checout, or displayHistory
// The class:
// -- Allows to find the correct transaction using a hash function and an array
// -- Allows to the transaction by taking in a file, transtype, and a manager
// Implementation and Assumptions:
// -- The array max size is 26
// -- The constructor create an object of each type at the index returned 
// by the hash function
// ----------------------------------------------------------------------------

#ifndef TRANSACTIONFACTORY_H_
#define TRANSACTIONFACTORY_H_

#include <istream>
#include "checkout.h"
#include "returnbook.h"
#include "displayhistory.h"
#include "transaction.h"
#define MAXTYPE 26
class TransactionFactory
{
public:
	TransactionFactory();
	~TransactionFactory();
	int hash(char bookType);
	// give a file, char, and manager to the correct type of transaction
	Transaction* createTransaction(istream& infile, char transType, Manager* manager);
private:
	Transaction* factory[MAXTYPE];
};
#endif
