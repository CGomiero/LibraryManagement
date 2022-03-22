#include "patron.h"

// ----------------------------------------------------------------------------
// Constructor:
// Initialize the book and patronHistory array
// ----------------------------------------------------------------------------
Patron::Patron()
{
	for (int i = 0; i < MAXSIZE; i++) {
		patronHistory[i] = nullptr;
		allBooks[i] = nullptr;
	}
}

// ----------------------------------------------------------------------------
// Constructor:
// This constructor is used for the data4patron file
// Take an id, and full name
// Initialize the book and patronHistory array
// ----------------------------------------------------------------------------
Patron::Patron(int id, string lastName, string firstName)
{
	ID = id;
	this->lastName = lastName;
	this->firstName = firstName;

	if (ID > 9999 || ID < 1000) {//check if id is correct
		return;
	}

	for (int i = 0; i < MAXSIZE; i++) {
		patronHistory[i] = nullptr;
		allBooks[i] = nullptr;
	}
}

// ----------------------------------------------------------------------------
// Destructor:
// Delete the arrays for potential memory leaks
// ----------------------------------------------------------------------------
Patron::~Patron()
{
	for (int i = 0; i < MAXSIZE; i++) {
			delete allBooks[i];
			delete patronHistory[i];
	}
}

Patron* Patron::create(istream& infile, int id)
{
	Patron* patron = new Patron();
	// get the info for the patron
	patron->ID = id;

	if (patron->ID > 9999 || patron->ID < 1000) {//check if id is correct
		delete patron;
		return nullptr;
	}
	infile >> patron->lastName >> patron->firstName;
	return patron;
}

// ----------------------------------------------------------------------------
// performTransaction:
// Determine which method in the patron needs to be called to handle the 
// transaction
// ----------------------------------------------------------------------------
bool Patron::performTransaction(Transaction* action, Media* book, char type)
{
	switch (type) {
	case'H':
		displayHistory();
		return true;
	case'C':
		checkOut(action, book);
		return true;
	case'R':
		returnBook(action, book);
		return true;
	default:
		cout << "'" << type << "' is not valid. Transaction is canceled." << endl;
		return false;
	}
}

// ----------------------------------------------------------------------------
// checkOut:
// Go over the book array to add the book and add the transaction in the 
// right arary
// ----------------------------------------------------------------------------
bool Patron::checkOut(Transaction* action, Media* book)
{
	for (int i = 0; i < MAXSIZE; i++) {
		if (allBooks[i] == nullptr) {
			allBooks[i] = book;
			addTransaction(action);
			return true;
		}
	}

	return false;
}

// ----------------------------------------------------------------------------
// returnBook:
// Go over the array to find if the book to be returned is in the patron array
// of books. If it is then set the index it is to nullptr and add the 
// transaction 
// ----------------------------------------------------------------------------
bool Patron::returnBook(Transaction* action, Media* book)
{
	if (hasBook(book)) {
		addTransaction(action);
		for (int i = 0; i < MAXSIZE; i++) {
			if (allBooks[i] == book) {
				allBooks[i] = nullptr;
			}
		}
		return true;
	}
	else {
		return false;
	}
}

// ----------------------------------------------------------------------------
// addTransaction:
// add a transaction ptr to the patronHistory array
// ----------------------------------------------------------------------------
void Patron::addTransaction(Transaction* action)
{
	patronHistory[capacity] = action;
	capacity++;
}

// ----------------------------------------------------------------------------
// displayHistory:
// display the patron info and all the transaction the he had
// ----------------------------------------------------------------------------
void Patron::displayHistory() const
{
	bool flag = true;
	displayPatron();

	for (int i = 0; i < capacity; i++) {
		if (patronHistory[i] != nullptr) {
			patronHistory[i]->display();
			flag = false;
		}
	}
	if (flag) {
		cout << "No transaction has been made. " << endl;
	}
}

// ----------------------------------------------------------------------------
// displayAllBooks:
// display the patron name and all its books 
// ----------------------------------------------------------------------------
void Patron::displayAllBooks() const
{
	cout << "All " << firstName << " " << lastName << " books: " << endl;
	int i = 0;

	while (allBooks[i] != nullptr) {
		allBooks[i]->displayBook();
	}
}

// ----------------------------------------------------------------------------
// getID:
// return the id of the patron
// ----------------------------------------------------------------------------
int Patron::getID()
{
	return ID;
}

bool Patron::hasBook(Media* book)
{
	for (int i = 0; i < MAXSIZE; i++) {
		if (allBooks[i] == book) {
			return true;
		}
	}
	return false;
}

// ----------------------------------------------------------------------------
// displayPatron:
// display the patron id, first and last name
// ----------------------------------------------------------------------------
void Patron::displayPatron() const
{
	cout << ID << " " << lastName << ", " << firstName << endl;
}

// ----------------------------------------------------------------------------
// hash:
// return an integer based on the input char
// ----------------------------------------------------------------------------
int Patron::hash(char transType) const
{
	int index = (int)transType - 65;
	return index;
}

// ----------------------------------------------------------------------------
// operator ==:
// return if two patrons are equal with their id, last and first name
// ----------------------------------------------------------------------------
bool Patron::operator==(const Patron& rhs)
{
	return ((ID == rhs.ID) && (lastName == rhs.lastName) && (firstName == rhs.firstName));
}
