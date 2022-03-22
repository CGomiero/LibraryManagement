// ----------------------------------------------------------------------------
// MEDIA_H_
// ----------------------------------------------------------------------------
// Media is an abstract class for the ChildrenBoo, PeriodicalBook, and 
// FictionBook classes. It provides the methods which all classes must have.
// The class:
// -- Provide method to handle transactions such as checkOut or return 
// -- Provide create methods that takes a file in a set the data from it
// -- Provide methods to display a book in a specific format
// -- Provide overloaded comparator operators that need to be override
// ----------------------------------------------------------------------------
#ifndef MEDIA_H_
#define MEDIA_H_

#include <string>
using namespace std;

class Media
{
public:
	//transaction methods
	virtual bool checkOut() = 0;
	virtual bool returnBook() = 0;

	//output / display methods
	virtual void displayBook() const = 0;
	virtual void displayAllInfo() const = 0;

	//create methods to set data
	virtual Media* create(istream& infile) = 0;
	virtual Media* createTransBook(istream& infile) = 0;
	virtual string getTitle() = 0;

	//comparators operator
	virtual bool operator <(const Media&) const = 0;
	virtual bool operator >(const Media&) const = 0;
	virtual bool operator ==(const Media&) const = 0;
	virtual bool operator !=(const Media&) const = 0;
private:

};
#endif

