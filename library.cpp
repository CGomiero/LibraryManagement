#include "library.h"

// --------------------------------------------------------------------------
// Constructor:
// Create a tree for each type of books/items
// --------------------------------------------------------------------------
Library::Library()
{
	for (int i = 0; i < MAXITEMS; i++) {
		container[i] = new BSTree();
	}
	//container for children books
	container[hash('C')] = new BSTree();

	//container for fiction books
	container[hash('F')] = new BSTree();

	//container for periodical books
	container[hash('P')] = new BSTree();
}

// --------------------------------------------------------------------------
// Destructor:
// Delete all the trees in the array
// --------------------------------------------------------------------------
Library::~Library()
{
	for (int i = 0; i < MAXITEMS; i++) {
		delete container[i];
	}
}

// --------------------------------------------------------------------------
// insert:
// If the book is inserted then return true else false
// --------------------------------------------------------------------------
bool Library::insert(Media* book, char type)
{
	//hash determines which tree to choose
	return container[hash(type)]->insert(book);
}

// --------------------------------------------------------------------------
// remove:
// If the book is removed then return true, else false
// --------------------------------------------------------------------------
bool Library::remove(Media* book, char type)
{
	return container[hash(type)]->remove(book);
}

bool Library::retrieveBook(Media* target, Media*& data, char type)
{
	container[hash(type)]->retrieve(*target, data);
	
	if (data == nullptr) {
		return false;
	}
	else {
		return true;
	}
}

// --------------------------------------------------------------------------
// checkOut:
// Retrieve the Media object from the tree then perform checkOut 
// return true if successfully checkOut
// --------------------------------------------------------------------------
bool Library::checkOut(Media* book, char type)
{
	Media* copy;
	container[hash(type)]->retrieve(*book, copy);
	return copy->checkOut();
}

// --------------------------------------------------------------------------
// returnBook:
// Retrieve the Media object from the tree then perform returnBook 
// return true if successfully return
// --------------------------------------------------------------------------
bool Library::returnBook(Media* book, char type)
{
	Media* copy;
	if (!container[hash(type)]->retrieve(*book, copy)) {
		return false;
	}
	return copy->returnBook();
}

// --------------------------------------------------------------------------
// displayOneType:
// Find the correct type tree and print all the books in it
// --------------------------------------------------------------------------
void Library::displayOneType(char type) const
{
	if (container[hash(type)]->isEmpty()) {
		cout << "Error: '" << type << "' is not a Media type or is empty." << endl;
	}
	else {
		cout << setw(0) << "Available";
		if (type == 'P') {
			cout << setw(10) << "Month";
			cout << setw(10) << "Year";
			cout << setw(25) << "Title";

		}
		else {
			cout << setw(22) << "Author";
			cout << setw(23) << "Title";
			cout << setw(19) << "Year";
		}
		cout << endl;
		container[hash(type)]->displayAll();
	}
}

// --------------------------------------------------------------------------
// displayAllLibrary:
// Go over the container array and print any library it has
// --------------------------------------------------------------------------
void Library::displayAllLibrary() const
{
	for (int i = 0; i < MAXITEMS; i++) {
		if (!container[i]->isEmpty()) {
			cout << setw(0) << "Available";
			if (i == hash('P')) {
				cout << setw(10) << "Year";
				cout << setw(40) << "Title";
				
			}
			else {
				cout << setw(20) << "Author";
				cout << setw(40) << "Title";
				cout << setw(20) << "Year";
			}
			

			cout << endl;
			container[i]->displayAll();
			cout << endl;
		}
	}
}

// --------------------------------------------------------------------------
// hash:
// return an integer based on the char (a = 0, b = 1, etc.)
// --------------------------------------------------------------------------
int Library::hash(char bookType) const
{
	int index = (int)bookType - 65;
	return index;
}
