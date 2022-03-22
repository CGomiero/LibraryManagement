#include "childrenbook.h"

ChildrenBook::ChildrenBook()
{
}

// --------------------------------------------------------------------------
// Destructor:
// If not created, there is memory leaks
// --------------------------------------------------------------------------
ChildrenBook::~ChildrenBook()
{
}

// --------------------------------------------------------------------------
// create: 
// Create a children book object with a title, author, and date
// return a pointer of the object
// --------------------------------------------------------------------------
Media* ChildrenBook::create(istream& infile)
{
	ChildrenBook* book = new ChildrenBook();
	infile.get();
	getline(infile, book->author, ',');

	infile.get();
	getline(infile, book->title, ',');

	infile >> book->year;
	return book;
}

// --------------------------------------------------------------------------
// createTransBook: 
// Create a fiction book object with title and author
// return a pointer of the object
// (The input order is different from the create function
// --------------------------------------------------------------------------
Media* ChildrenBook::createTransBook(istream& infile)
{
	ChildrenBook* book = new ChildrenBook();
	infile.get();
	getline(infile, book->title, ',');

	infile.get();
	getline(infile, book->author, ',');

	return book;
}

// --------------------------------------------------------------------------
// getTitle:
// return the title as a string
// --------------------------------------------------------------------------
string ChildrenBook::getTitle()
{
	return title;
}

// --------------------------------------------------------------------------
// displayBook:
// Output author, title, and year of a book
// --------------------------------------------------------------------------
void ChildrenBook::displayBook() const
{
	cout << setw(30) << author;
	cout << setw(30) << title.substr(0, 20);
	cout << setw(12) << year;
	cout << endl;
}

// --------------------------------------------------------------------------
// displayAllInfo:
// Output number of books available, and the book
// --------------------------------------------------------------------------
void ChildrenBook::displayAllInfo() const
{
	cout << setw(0) << available;
	displayBook();
}

// --------------------------------------------------------------------------
// checkOut:
// check if the book is avaible to check out by checking the amount of 
// books
// --------------------------------------------------------------------------
bool ChildrenBook::checkOut()
{
	if (available > 0) {
		available--;
		return true;
	}
	else {
		return false;
	}
}

// --------------------------------------------------------------------------
// returnBook:
// when a book is returned, it adds one the amount available
// --------------------------------------------------------------------------
bool ChildrenBook::returnBook()
{
	if (available < 5) {
		available++;
		return true;
	}
	else {
		
		return false;
	}
}

// --------------------------------------------------------------------------
// Overload operator <
// Compare the title, then the author to determine if this->children book is 
// smaller 
// --------------------------------------------------------------------------
bool ChildrenBook::operator<(const ChildrenBook& rhs) const
{
	if (title < rhs.title) {
		return true;
	}
	else if (title > rhs.title) {
		return false;
	}
	else {
		if (author < rhs.author) {
			return true;
		}
		else {
			return false;
		}
	}
}

// --------------------------------------------------------------------------
// Overload operator >
// Compare the title, then the author to determine if this->children book is 
// bigger 
// --------------------------------------------------------------------------
bool ChildrenBook::operator>(const ChildrenBook& rhs) const
{
	if (title > rhs.title) {
		return true;
	}
	else if (title < rhs.title) {
		return false;
	}
	else {
		if (author > rhs.author) {
			return true;
		}
		else {
			return false;
		}
	}
}

// --------------------------------------------------------------------------
// Overload operator ==: 
// checks if two children books variables are equal
// --------------------------------------------------------------------------
bool ChildrenBook::operator==(const ChildrenBook& rhs) const
{
	//does not compare year and month as the transactions does not include
	return ((title == rhs.title) && (author == rhs.author));
}

bool ChildrenBook::operator!=(const ChildrenBook& rhs) const
{
	return !(*this == rhs);
}

bool ChildrenBook::operator<(const Media& rhs) const
{

	return (*this < (dynamic_cast<const ChildrenBook&>(rhs)));

}

bool ChildrenBook::operator>(const Media& rhs) const
{
	return (*this > (dynamic_cast<const ChildrenBook&>(rhs)));
}

bool ChildrenBook::operator==(const Media& rhs) const
{
	return (*this == (dynamic_cast<const ChildrenBook&>(rhs)));
}

bool ChildrenBook::operator!=(const Media& rhs) const
{
	return (!(*this == (dynamic_cast<const ChildrenBook&>(rhs))));
}


