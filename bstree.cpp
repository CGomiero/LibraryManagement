#include "bstree.h"

// --------------------------------------------------------------------------
// Constructor BSTree:
// Every variables are assigned at the creation of the object
// --------------------------------------------------------------------------
BSTree::BSTree() : root(nullptr)
{
}

// --------------------------------------------------------------------------
// Destructor:
// Delete the tree no make sure there is no memory leaks
// Delete the tree no make sure there is no memory leaks
// --------------------------------------------------------------------------
BSTree::~BSTree()
{
	if (root != nullptr) {
		makeEmpty();
		delete root;
	}

}

// --------------------------------------------------------------------------
// insert: add a Media Object to the tree by iteratively finding the right 
// spot in the tree and adding it
// return true if the object was added
// --------------------------------------------------------------------------
bool BSTree::insert(Media* data)
{
	Node* insertNode = new Node();
	insertNode->data = data;

	if (root == nullptr) {
		root = insertNode;
		return true;
	}

	Node* current = root;
	Node* previous = nullptr;

	while (current != nullptr) {
		previous = current;
		if (*insertNode->data < *current->data) {
			current = current->left;
		}
		else if (*insertNode->data > *current->data) {
			current = current->right;
		}
		else if (*insertNode->data == *current->data) {
			insertNode->data = nullptr;
			delete insertNode->data;
			delete insertNode;
			insertNode = nullptr;
			return false;
		}
	}

	if (*insertNode->data < *previous->data) {		//insert the data
		previous->left = insertNode;
		return true;
	}
	if (*insertNode->data > *previous->data) {
		previous->right = insertNode;
		return true;
	}
	return false;
}

// --------------------------------------------------------------------------
// remove and deleteNodeHelper:
// delete a node from the tree
// return true if deleted
// --------------------------------------------------------------------------
bool BSTree::remove(Media* data)
{
	Node* parent = nullptr;
	Node* current = root;

	// find the node to delete
	while (current != nullptr && (*current->data != *data)) {
		parent = current;
		if (*data < *current->data) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}

	if (current == nullptr) { //item no found from search key
		return false;
	}
	// delete a node without leafs
	if (current->left == nullptr && current->right == nullptr) {
		// delete root
		if (parent == nullptr) {
			current->data = nullptr;
			delete current->data;
			delete current;
			current = nullptr;
			root = nullptr;
			return true;
		}
		if (current != nullptr) {

			if (parent->left == current) {
				parent->left = nullptr;
			}
			else {
				parent->right = nullptr;
			}
		}
		else {
			root = nullptr;
		}
	}
	// delete node with two leaf
	else if (current->left && current->right) {
		Node* sucessor = findMin(current->right);
		Media* val = sucessor->data;
		remove(sucessor->data);
	}
	// delete node with one child
	else {
		Node* child = (current->left) ? current->left : current->right;
		if (current != root) {
			if (current == parent->left) {
				parent->left = child;
			}
			else {
				parent->right = child;
			}
		}
		else {
			root = child;
		}
	}
	current->data = nullptr;
	delete current->data;
	delete current;
	current = nullptr;
	return true;
}

BSTree::Node* BSTree::findMin(Node* current)
{
	while (current->left != nullptr) {
		current = current->left;
	}
	return current;
}
// --------------------------------------------------------------------------
// retrieve:
// Find a Media and return bool if it was found
// Return the object using a pointer to a reference to a Media object
// --------------------------------------------------------------------------
bool BSTree::retrieve(const Media& target, Media*& data) const
{
	if (root == nullptr) {
		return false;
	}

	Node* current = root;
	while (current != nullptr) {
		if (*current->data == target) {
			data = current->data;
			return true;
		}
		if (*current->data > target) {
			current = current->left;
		}
		else {
			current = current->right;
		}
	}
	return false;
}

// --------------------------------------------------------------------------
// isEmpty:
// check the root if it is nullptr or not
// --------------------------------------------------------------------------
bool BSTree::isEmpty() const
{
	return root == nullptr;
}

// --------------------------------------------------------------------------
// makeEmpty and makeEmptyHelper:
// recursively delete the entire tree by deleting the pointers 
// --------------------------------------------------------------------------
void BSTree::makeEmpty()
{
	if (root != nullptr) {
		makeEmptyHelper(root);
		root = nullptr;
	}
}

// --------------------------------------------------------------------------
// displayAll:
// display all the books of a specific type inorder
// --------------------------------------------------------------------------
void BSTree::displayAll() const
{
	inorderHelper(root);
}

// --------------------------------------------------------------------------
// inorderHelper:
// output the data of the tree inorder
// --------------------------------------------------------------------------
void BSTree::inorderHelper(Node* current) const
{
	if (current == nullptr || current->data == nullptr) {
		return;
	}
	current->data->displayAllInfo();
	inorderHelper(current->left);
	inorderHelper(current->right);
}

// --------------------------------------------------------------------------
// display:
// find a book in the tree and display it
// --------------------------------------------------------------------------
void BSTree::display(Media* book) const
{
	if (root == nullptr) {
		return;
	}
	Node* current = root;

	while (current != nullptr) {
		if (*current->data == *book) {
			current->data->displayBook();
		}
		if (*current->data < *book) {
			current = current->right;
		}
		else {
			current = current->left;
		}
	}
}

void BSTree::makeEmptyHelper(Node* node)
{
	if (node != nullptr) {
		makeEmptyHelper(node->left);
		makeEmptyHelper(node->right);
		delete node->data;
		delete node;
	}
}