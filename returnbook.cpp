#include "returnbook.h"

// ----------------------------------------------------------------------------
// ReturnBook:
// Set tempBook to nullptr
// ----------------------------------------------------------------------------
ReturnBook::ReturnBook()
{
	tempBook = nullptr;
}

// ----------------------------------------------------------------------------
// Destructor:
// Delete all pointers
// ----------------------------------------------------------------------------
ReturnBook::~ReturnBook()
{
	delete tempBook;
	delete targetBook;
	delete patronPtr;
}

// ----------------------------------------------------------------------------
// execute:
// Read from the file and create a Media book from it 
// Find the corresponding patron using the ID
// Find the actual book from the book ptr
// Make the return using the patron and Media objects
// ----------------------------------------------------------------------------
bool ReturnBook::execute(Manager* manager, char type, istream& infile)
{
	charType = type;
	infile >> patronID >> bookType >> hardCopy;

	MediaFactory media;
	targetBook = media.transactionBook(bookType, infile);
	
	patronPtr = manager->getPatron(patronID);

	if (targetBook == nullptr) {
		return false;
	}
	if (patronPtr == nullptr) {
		cout << "ID " << patronID << " is not valid. " << endl;
		return false;
	}
	//get the book from the library
	if (manager->getBook(targetBook, tempBook, bookType)) {
		//check if the patron has the book and if the book can be returned
		if (!patronPtr->hasBook(tempBook)) {
			cout << patronPtr->getID() << " did not have " << tempBook->getTitle() << "." << endl;
			return false;
		}
		if(!tempBook->returnBook()) {
			return false;
		}
	}
	else {
		return false;
	}

	//add the transaction to a patron
	patronPtr->performTransaction(this, tempBook, charType);
	return true;
}

// ----------------------------------------------------------------------------
// display:
// output the type of transaction and the book
// ----------------------------------------------------------------------------
void ReturnBook::display() const
{
	
	if (tempBook != nullptr) {
		cout << setw(10) << transType;
		tempBook->displayBook();
	}
}

// ----------------------------------------------------------------------------
// create:
// return a pointer of this object 
// ----------------------------------------------------------------------------
Transaction* ReturnBook::create()
{
	return this;
}
