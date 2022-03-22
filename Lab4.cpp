// ----------------------------------------------------------------------------
// Lab4.cpp
//----------------------------------------------------------------------------
// Lab4 is the main class where the files will be created and a manager object
// is created which will take all files required.
// Implementation and Assumptions:
// -- Lab4.cpp main needs to be small
// -- Only the files and a manager object are created
// -- The manager will take in all the files and perform the action that it 
// needs to do
// ----------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include "manager.h"


using namespace std;
int main()
{
	ifstream media("data4books.txt");
	ifstream patron("data4patrons.txt");
	ifstream transaction("data4commands.txt");
	Manager manager;
	manager.inputMediaFile(media);
	manager.inputPatronFile(patron);
	manager.inputTransactionFile(transaction);
}


