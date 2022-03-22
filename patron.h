// ----------------------------------------------------------------------------
// PATRON_H_
// ----------------------------------------------------------------------------
// Patron class is a class that hold a patron information and all
// its books in a hashtable
// The class: 
// -- allows to create a patron object and store its information
// -- allows to store books in an hashtable
// -- allows to check out a book
// -- allows to display all books
// ----------------------------------------------------------------------------
#ifndef PATRON_H_
#define PATRON_H_

#include <iostream>
#include <string>
#include "transaction.h"
#include "media.h"
#include <array>
using namespace std;

#define MAXSIZE 100
class Patron
{
public:
	Patron();
	Patron(int id, string lastName, string firstName);
	~Patron();

	Patron* create(istream& infile, int id);
	//transaction methods
	bool performTransaction(Transaction* action, Media* book, char type);
	bool checkOut(Transaction* action, Media* book);
	bool returnBook(Transaction* action, Media* book);
	void addTransaction(Transaction* action);

	//display all books and transaction the patron has
	//also display itself
	void displayHistory() const;
	void displayAllBooks() const;
	void displayPatron() const;

	int getID();
	bool hasBook(Media*);
	int hash(char) const;

	//operator used for the hash function
	bool operator ==(const Patron&);
private:
	
	Media* allBooks[MAXSIZE];
	char transType;
	int ID, capacity = 1;
	string lastName, firstName;
	Transaction* patronHistory[MAXSIZE];
};
#endif

