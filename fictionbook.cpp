#include "fictionbook.h"

FictionBook::FictionBook()
{
	year = -1;
}


// --------------------------------------------------------------------------
// Destructor:
// If not created, there is memory leaks
// --------------------------------------------------------------------------
FictionBook::~FictionBook()
{
}

// --------------------------------------------------------------------------
// create: 
// Create a fiction book object with a title, author, and date
// return a pointer of the object
// --------------------------------------------------------------------------
Media* FictionBook::create(istream& infile)
{
	FictionBook* book = new FictionBook();
	infile.get();
	getline(infile, book->author, ',');

	infile.get();
	getline(infile, book->title, ',');

	infile >> book->year;
	return book;
}

// --------------------------------------------------------------------------
// createTransBook: 
// Create a fiction book object with an author and a title
// return a pointer of the object
// (The input order is different from the create function
// --------------------------------------------------------------------------
Media* FictionBook::createTransBook(istream& infile)
{
	FictionBook* book = new FictionBook();
	infile.get();
	getline(infile, book->author, ',');

	infile.get();
	getline(infile, book->title, ',');
	return book;
}

// --------------------------------------------------------------------------
// getTitle:
// return the title as a string
// --------------------------------------------------------------------------
string FictionBook::getTitle()
{
	return title;
}

// --------------------------------------------------------------------------
// displayBook:
// Output author, title, and year of a book
// --------------------------------------------------------------------------
void FictionBook::displayBook() const
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
void FictionBook::displayAllInfo() const
{
	cout << setw(0) << available;
	displayBook();
}

// --------------------------------------------------------------------------
// checkOut:
// check if the book is avaible to check out by checking the amount of 
// books
// --------------------------------------------------------------------------
bool FictionBook::checkOut()
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
bool FictionBook::returnBook()
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
// Compare the author, then the title to determine if this->fiction book is 
// smaller 
// --------------------------------------------------------------------------
bool FictionBook::operator<(const FictionBook& rhs) const
{
	if (author < rhs.author) {
		return true;
	}
	else if (author > rhs.author) {
		return false;
	}
	else {
		if (title < rhs.title) {
			return true;
		}
		else {
			return false;
		}
	}
}

// --------------------------------------------------------------------------
// Overload operator >
// Compare the author, then the title to determine if this->fiction book is 
// bigger 
// --------------------------------------------------------------------------
bool FictionBook::operator>(const FictionBook& rhs) const
{
	if (author > rhs.author) {
		return true;
	}
	else if (author < rhs.author) {
		return false;
	}
	else {
		if (title > rhs.title) {
			return true;
		}
		else {
			return false;
		}
	}
}

// --------------------------------------------------------------------------
// Overload operator ==: 
// checks if two fictions books variables are equal
// --------------------------------------------------------------------------
bool FictionBook::operator==(const FictionBook& rhs) const
{
	//does not compare year and month as the transaction does not provide it
	return ((title == rhs.title) && (author == rhs.author));
}

bool FictionBook::operator!=(const FictionBook& rhs) const
{
	return !(*this == rhs);
}

bool FictionBook::operator<(const Media& rhs) const
{
	return (*this < dynamic_cast<const FictionBook&>(rhs));
}

bool FictionBook::operator>(const Media& rhs) const
{
	return (*this > dynamic_cast<const FictionBook&>(rhs));
}

bool FictionBook::operator==(const Media& rhs) const
{
	return (*this == dynamic_cast<const FictionBook&>(rhs));
}

bool FictionBook::operator!=(const Media& rhs) const
{
	return (!(*this == dynamic_cast<const FictionBook&>(rhs)));
}
