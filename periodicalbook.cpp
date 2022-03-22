#include "periodicalbook.h"

PeriodicalBook::PeriodicalBook()
{
	year = -1;
	month = -1;
}

// --------------------------------------------------------------------------
// Destructor:
// If not created, there is memory leaks
// --------------------------------------------------------------------------
PeriodicalBook::~PeriodicalBook()
{
}

Media* PeriodicalBook::create(istream& infile)
{
	PeriodicalBook* book = new PeriodicalBook();
	infile.get();
	getline(infile, book->title, ',');

	infile >> book->month >> book->year;
	return book;
}

// --------------------------------------------------------------------------
// createTransBook: 
// Create a fiction book object with year, month and title
// return a pointer of the object
// (The input order is different from the create function
// --------------------------------------------------------------------------
Media* PeriodicalBook::createTransBook(istream& infile)
{
	PeriodicalBook* book = new PeriodicalBook();
	infile >> book->year >> book->month;

	infile.get();
	getline(infile, book->title, ',');

	return book;
}

// --------------------------------------------------------------------------
// getTitle:
// return the title as a string
// --------------------------------------------------------------------------
string PeriodicalBook::getTitle()
{
	return title;
}

// --------------------------------------------------------------------------
// displayBook:
// Output number of books available, author, title, and year of a book
// --------------------------------------------------------------------------
void PeriodicalBook::displayBook() const
{
	cout << setw(16) << month;
	cout << setw(12) << year;
	cout << setw(35) << title;
	cout << endl;
}

// --------------------------------------------------------------------------
// displayAllInfo:
// Output number of books available, and the book information
// --------------------------------------------------------------------------
void PeriodicalBook::displayAllInfo() const
{
	cout << setw(0) << available;
	displayBook();
}

// --------------------------------------------------------------------------
// checkOut:
// check if the book is avaible to check out by checking the amount of 
// books
// --------------------------------------------------------------------------
bool PeriodicalBook::checkOut()
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
bool PeriodicalBook::returnBook()
{
	if (available < 1) {
		available++;
		return true;
	}
	else {
		return false;
	}
}

// --------------------------------------------------------------------------
// Overload operator <:
// Smaller comparator, compare year, then month, then title
// --------------------------------------------------------------------------
bool PeriodicalBook::operator<(const PeriodicalBook& rhs) const
{
	if (year < rhs.year) {
		return true;
	}
	else if (year > rhs.year) {
		return false;
	}
	else {
		if (month < rhs.month) {
			return true;
		}
		else if (month > rhs.month) {
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
}

// --------------------------------------------------------------------------
// Overload operator >:
// Greater comparator, compare year, then month, then title
// --------------------------------------------------------------------------
bool PeriodicalBook::operator>(const PeriodicalBook& rhs) const
{
	if (year > rhs.year) {
		return true;
	}
	else if (year < rhs.year) {
		return false;
	}
	else {
		if (month > rhs.month) {
			return true;
		}
		else if (month < rhs.month) {
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
}

// --------------------------------------------------------------------------
// Overload operator ==: 
// checks if two periodical books variables are equal
// --------------------------------------------------------------------------
bool PeriodicalBook::operator==(const PeriodicalBook& rhs) const
{
	return ((year == rhs.year) && (month == rhs.month) && (title == rhs.title));
}

bool PeriodicalBook::operator !=(const PeriodicalBook& rhs) const {
	return !(*this == rhs);
}
bool PeriodicalBook::operator<(const Media& rhs) const
{
	return (*this < dynamic_cast<const PeriodicalBook&>(rhs));
}

bool PeriodicalBook::operator>(const Media& rhs) const
{
	return (*this > dynamic_cast<const PeriodicalBook&>(rhs));
}

bool PeriodicalBook::operator==(const Media& rhs) const
{
	return (*this == dynamic_cast<const PeriodicalBook&>(rhs));
}

bool PeriodicalBook::operator!=(const Media& rhs) const
{
	return (!(*this == dynamic_cast<const PeriodicalBook&>(rhs)));
}

