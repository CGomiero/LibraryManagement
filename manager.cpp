#include "manager.h"

// ----------------------------------------------------------------------------
// Constructor:
// ----------------------------------------------------------------------------
Manager::Manager()
{
}

// ----------------------------------------------------------------------------
// Constructor:
// a constructor that allows to take directly a file in
// ----------------------------------------------------------------------------
Manager::Manager(istream& infile)
{
}

// ----------------------------------------------------------------------------
// Destructor:
// delete the transactionFactory ptr
// ----------------------------------------------------------------------------
Manager::~Manager()
{
}

// ----------------------------------------------------------------------------
// inputMediaFile:
// Read in a file and create a book based on the type that is given
// Then insert the book in the library
// ----------------------------------------------------------------------------
void Manager::inputMediaFile(istream& infile)
{
	if (!infile) {//check if the file is open
		cout << "File could not be open." << endl;
	}
	MediaFactory createBook;
	char type;

	while (!infile.eof()) {//go over the file
		infile >> type;
		if (infile.eof()) return;

		//create and add the book in the library
		allBooks.insert(createBook.createBook(type, infile), type);
		
	}
}

// ----------------------------------------------------------------------------
// inputPatronFile:
// Read in a file for patron. Each line of the file creates a patron.
// Store then the patronContainer class
// ----------------------------------------------------------------------------
void Manager::inputPatronFile(istream& infile)
{
	if (!infile) {
		cout << "File could not be open." << endl;
	}

	int id;

	while (!infile.eof()) {
		infile >> id;
		if (infile.eof()) return;
		Patron* patron = new Patron();
		allPatrons.insert(patron->create(infile, id));
		delete patron;
	}
}

// ----------------------------------------------------------------------------
// inputTransactionFile:
// Read a file, if the type of transaction is 'D' then display the library
// else create a transaction using the transaction factory object
// ----------------------------------------------------------------------------
void Manager::inputTransactionFile(istream& infile)
{
	if (!infile) {
		cout << "File could not be open." << endl;
	}
	
	char transType;
	TransactionFactory* transaction = new TransactionFactory();
	while (!infile.eof()) {
		infile >> transType;
		if (transType == 'D') {
			displayLibrary();
		}
		else {
			transaction = new TransactionFactory();
			transaction->createTransaction(infile, transType, this);
		}
	}
	delete transaction;
}

// ----------------------------------------------------------------------------
// displayLibrary:
// display all type of Media
// ----------------------------------------------------------------------------
void Manager::displayLibrary() const
{
	displayOneType('C');
	cout << endl;
	displayOneType('P');
	cout << endl;
	displayOneType('F');
	cout << endl;
}

// ----------------------------------------------------------------------------
// displayOneType:
// diplay one type of Media
// ----------------------------------------------------------------------------
void Manager::displayOneType(char type) const
{
	switch (type) {//output the name type
	case'C':
		cout << "Children Books" << endl;
		break;
	case'P':
		cout << "Periodical Books" << endl;
		break;
	case'F':
		cout << "Fictional Books" << endl;
		break;
	default:
		cout << "Error: The wrong type of book was displayed." << endl;
		return;
	}
	allBooks.displayOneType(type);
}

// ----------------------------------------------------------------------------
// getBook:
// get a book from the library 
// ----------------------------------------------------------------------------
bool Manager::getBook(Media* target, Media*& data, char bookType)
{
	return allBooks.retrieveBook(target, data, bookType);
}

// ----------------------------------------------------------------------------
// getPatron:
// find a patron from the patron container
// ----------------------------------------------------------------------------
Patron* Manager::getPatron(int targetID)
{
	return allPatrons.getPatron(targetID);
}
