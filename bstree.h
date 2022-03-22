//----------------------------------------------------------------------------
// class BSTree
// ADT Binary Search Tree: binary tree that is ordered in a way where any node
// left of it is of lesser value while the nodes right of it are always
// of greater value.
// Implementation and assumptions:
//    -- Implemented as a binary search tree.
//    -- If the tree is empty, then root is null.
//    -- Allows inserting and removing Media
//    -- Allows retrieving a Media from the tree.
//----------------------------------------------------------------------------

#ifndef BSTREE_H_
#define BSTREE_H_
#include "media.h"
#include <iostream>
using namespace std;

class BSTree {

public:
    BSTree();                       // default constructor
    ~BSTree();                      // destructor

    // inserts one Media object, assume parameter points to valid object
    // return if successful
    bool insert(Media* data);

    // removes a Media object, restructures tree if needed
    // return if sucessful
    bool remove(Media* data);

    // searches tree for a Media, returns if found and points data if found
    bool retrieve(const Media& target, Media*& data) const;
    bool isEmpty() const;
    void makeEmpty();

    void displayAll() const;
    void display(Media*) const;
private:
    // structure for a Node of a binary tree

    struct Node {
        Media* data = nullptr;    // pointer to the data
        Node* left = nullptr;        // pointer to left node
        Node* right = nullptr;       // pointer to right node
    };
    Node* root;           // pointer to the root node
    void makeEmptyHelper(Node* node);
    Node* findMin(Node* current);
    void inorderHelper(Node* current) const;
    // void searchKey(Node*& current, Media* key, Node* parent);
};
#endif