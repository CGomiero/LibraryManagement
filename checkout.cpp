#include "checkout.h"

// ----------------------------------------------------------------------------
// Constructor:
// Set tempBook to nullptr
// ----------------------------------------------------------------------------
CheckOut::CheckOut()
{
	tempBook = nullptr;
}

// ----------------------------------------------------------------------------
// Destructor:
// Delete all pointers
// ----------------------------------------------------------------------------
CheckOut::~CheckOut()
{
	delete targetBook;
	delete tempBook;
	delete patronPtr;
}

// ----------------------------------------------------------------------------
// Execute:
// Read from the file and create a Media book from it 
// Find the corresponding patron using the ID
// Find the actual book from the book ptr
// Make the checkout using the patron and Media objects
// ----------------------------------------------------------------------------
bool CheckOut::execute(Manager* manager, char type, istream& infile)
{
	charType = type;

	infile >> patronID >> bookType >> hardCopy;

	MediaFactory media;//media factory will create the right type of book
	targetBook = media.transactionBook(bookType, infile);

	if (targetBook == nullptr) {
		return false;
	}

	patronPtr = manager->getPatron(patronID); //get patron

	if (patronPtr == nullptr) {
		cout << "ID " << patronID << " is not valid. " << endl;
		return false;
	}
	if (manager->getBook(targetBook, tempBook, bookType)) {//get book from libary
		if (!tempBook->checkOut()) {
			return false;
		}
	}
	else {
		return false;
	}
	patronPtr->performTransaction(this, tempBook, charType);//do the transaction
	return true;
}

// ----------------------------------------------------------------------------
// display:
// output the type of transaction and the book
// ----------------------------------------------------------------------------
void CheckOut::display() const
{
	if (tempBook != nullptr) {
		cout << setw(10) << transType;
		tempBook->displayBook();
	}
}

// ----------------------------------------------------------------------------
// create:
// create a pointer of a transaction
// ----------------------------------------------------------------------------
Transaction* CheckOut::create()
{
	return this;
}
