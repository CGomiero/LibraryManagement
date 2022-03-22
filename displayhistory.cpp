#include "displayhistory.h"

// ----------------------------------------------------------------------------
// Constructor:
// ----------------------------------------------------------------------------
DisplayHistory::DisplayHistory()
{
}

// ----------------------------------------------------------------------------
// Destructor:
// Delete the patron pointer
// ----------------------------------------------------------------------------
DisplayHistory::~DisplayHistory()
{
	delete patronPtr;
}

// ----------------------------------------------------------------------------
// execute:
// read an int(ID) from the file, find the patron with the same id and 
// print its array containing all the transactions
// ----------------------------------------------------------------------------
bool DisplayHistory::execute(Manager* manager, char type, istream& infile)
{
	infile >> ID;
	charType = type;

	patronPtr = manager->getPatron(ID);

	if (patronPtr != nullptr) {//output its historic
		patronPtr->displayHistory();
		cout << endl;
		return true;
	}
	else {
		return false;
	}
}

// ----------------------------------------------------------------------------
// display:
// ----------------------------------------------------------------------------
void DisplayHistory::display() const
{
}

// ----------------------------------------------------------------------------
// create:
// ----------------------------------------------------------------------------
Transaction* DisplayHistory::create()
{
	return nullptr;
}
