#include "patroncontainer.h"

// ----------------------------------------------------------------------------
// Constructor:
// ----------------------------------------------------------------------------
PatronContainer::PatronContainer()
{
    for (int i = 0; i < kMaxSize; i++) {
        allPatrons[getHash(i)][i] = nullptr;
    }
}

PatronContainer::~PatronContainer()
{
    
}

// ----------------------------------------------------------------------------
// remove:
// delete a patron from the hashTable
// ----------------------------------------------------------------------------
bool PatronContainer::remove(Patron* patron)
{
    if (allPatrons[getHash(patron->getID())] != nullptr) {
        delete allPatrons[getHash(patron->getID())];
        allPatrons[getHash(patron->getID())] = nullptr;
        return true;
    }
    else {
        return false;
    }
}

// ----------------------------------------------------------------------------
// insert:
// add a patron in the hashTable. It will be inserted based on its ID
// ----------------------------------------------------------------------------
bool PatronContainer::insert(Patron* patron)
{
    
        for (int i = 0; i < kMaxSize; i++) {
            if (allPatrons[getHash(patron->getID())][i] == nullptr) {
                allPatrons[getHash(patron->getID())][i] = patron;

                return true;
            }
        }
        cout << "The ID " << patron->getID() << " is already registered." << endl;
        return false;
}

// ----------------------------------------------------------------------------
// displayPatron:
// use the patron's id to find the actual object and display the patron info
// ----------------------------------------------------------------------------
void PatronContainer::displayPatron(int id)
{
    for (int i = 0; i < kMaxSize; i++) {
        if (allPatrons[getHash(id)][i]->getID() == id) {
            allPatrons[getHash(id)][i]->displayPatron();
        }
    }
    
}

// ----------------------------------------------------------------------------
// displayAll:
// output all patrons in the array
// ----------------------------------------------------------------------------
void PatronContainer::displayAll()
{
    for (int i = 0; i < kMaxSize; i++) {
        for (int j = 0; j < kMaxSize; j++) {
            if (allPatrons[getHash(i)][j] != nullptr) {
                allPatrons[getHash(i)][j]->displayPatron();
            }
        }
    }
}

// ----------------------------------------------------------------------------
// getPatron:
// find a patron with an id and return it
// ----------------------------------------------------------------------------
Patron* PatronContainer::getPatron(int id)
{
    for (int i = 0; i < kMaxSize; i++) {
        if (allPatrons[getHash(id)][i]->getID() == id) {
            return allPatrons[getHash(id)][i];
        }
    }
    return nullptr;
    
}
// ----------------------------------------------------------------------------
// getHash:
// return the remaining of index modulus MAXSIZE
// ----------------------------------------------------------------------------
int PatronContainer::getHash(int index)
{
   return index % kMaxSize;
}
