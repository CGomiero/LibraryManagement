#ifndef MEDIAFACTORY_H_
#define MEDIAFACTORY_H_

#include <string>
#include "media.h"
#include "fictionbook.h"
#include "childrenbook.h"
#include "periodicalbook.h"
using namespace std;
#define MAXMEDIA 26 

class MediaFactory
{
public:
	MediaFactory();
	~MediaFactory();
	Media* createBook(char bookType, istream& infile);
	Media* transactionBook(char bookType, istream& infile);
	int hash(char bookType);
private:
	Media* mediaFactory[MAXMEDIA];
};
#endif
