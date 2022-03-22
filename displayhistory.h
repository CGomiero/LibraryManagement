// ----------------------------------------------------------------------------
// DISPLAYHISTORY_H_
// ----------------------------------------------------------------------------
// The class DisplayHistory is subclass of Transaction where it is suppose to 
// output the history of a patron
// Implementation and Assumption:
// -- The class only need an int from the file
// -- Find the patron
// -- Output its history
// -- As it is a subclass, it has override create and display but they will be 
// empty
// ----------------------------------------------------------------------------
#ifndef DISPLAYHISTORY_H_
#define DISPLAYHISTORY_H_

#include "transaction.h"
#include "media.h"
#include "mediafactory.h"
#include "manager.h"
#include <iomanip>

using namespace std;
class DisplayHistory: public Transaction
{
public:
	DisplayHistory();
	~DisplayHistory();
	
	virtual bool execute(Manager* manager, char type, istream& infile);

	//empty method that need to be override
	virtual void display() const;
	virtual Transaction* create();
private:
	int ID = 0;
	Patron* patronPtr;
	string type = "Patron History";
	char charType;
};
#endif
