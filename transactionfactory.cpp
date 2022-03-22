#include "transactionfactory.h"

// ----------------------------------------------------------------------------
// Constructor:
// create a new transaction object at each index that is given with the 
// hash of a char 
// ----------------------------------------------------------------------------
TransactionFactory::TransactionFactory()
{
	for (int i = 0; i < MAXTYPE; i++) {
		factory[i] = nullptr;
	}
	factory[hash('H')] = new DisplayHistory();
	factory[hash('C')] = new CheckOut();
	factory[hash('R')] = new ReturnBook();

}

// ----------------------------------------------------------------------------
// Destructor:
// delete each pointers in the array
// ----------------------------------------------------------------------------
TransactionFactory::~TransactionFactory()
{
	for (int i = 0; i < MAXTYPE; i++) {
		if (factory[i] != nullptr) {
			delete factory[i];
			factory[i] = nullptr;
		}
	}
}

// ----------------------------------------------------------------------------
// hash:
// return an int based on the given char
// ----------------------------------------------------------------------------
int TransactionFactory::hash(char bookType)
{
	int index = (int)bookType - 65;
	return index;
}

// ----------------------------------------------------------------------------
// createTransaction:
// If the hash gives to a non nullptr then call execute() and return a pointer
// else get the remaining string in the line and return nullptr
// ----------------------------------------------------------------------------
Transaction* TransactionFactory::createTransaction(istream& infile, char transType, Manager* manager)
{
	if (factory[hash(transType)] != nullptr) {
		factory[hash(transType)]->execute(manager, transType, infile);
		return factory[hash(transType)]->create();
	}
	else {
		string line;
		getline(infile, line);
		cout << "Error: '" << transType << "' is not a valid transaction type." << endl;
		return nullptr;
	}
}
