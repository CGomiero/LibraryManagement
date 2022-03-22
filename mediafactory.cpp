#include "mediafactory.h"

// --------------------------------------------------------------------------
// MediaFactory:
// create an array holding Media to create the correct type of new books
// --------------------------------------------------------------------------
MediaFactory::MediaFactory()
{
	for (int i = 0; i < MAXMEDIA; i++) {
		mediaFactory[i] = nullptr;
	}
	mediaFactory[hash('C')] = new ChildrenBook();
	mediaFactory[hash('F')] = new FictionBook();
	mediaFactory[hash('P')] = new PeriodicalBook();
}

// --------------------------------------------------------------------------
// Destructor:
// delete all the media in the array 
// --------------------------------------------------------------------------
MediaFactory::~MediaFactory()
{
	for (int i = 0; i < MAXMEDIA; i++) {
		delete mediaFactory[i];
	}
}

// --------------------------------------------------------------------------
// createBook:
// call the correct book type, create the book from the right class 
// and return a pointer of it
// --------------------------------------------------------------------------
Media* MediaFactory::createBook(char bookType, istream& infile)
{
	if (mediaFactory[hash(bookType)] != nullptr) {
		return mediaFactory[hash(bookType)]->create(infile);
	}
	else {
		string line;
		getline(infile, line);
		cout << "Error: '" << bookType << "' is not a valid Media type." << endl;
		return nullptr;
	}
}

Media* MediaFactory::transactionBook(char bookType, istream& infile)
{
	if (mediaFactory[hash(bookType)] != nullptr) {
		return mediaFactory[hash(bookType)]->createTransBook(infile);
	}
	else {
		string line;
		getline(infile, line);
		cout << "Error: '" << bookType << "' is not a valid Media type. Unable to perform the transaction." << endl;
		return nullptr;
	}
}

// --------------------------------------------------------------------------
// hash:
// return an integer based on the char (a = 0, b = 1, etc.)
// --------------------------------------------------------------------------
int MediaFactory::hash(char bookType)
{
	int index = (int)bookType - 65;
	return index;
}
