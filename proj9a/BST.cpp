/* BST.cpp defines binary search tree methods.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name: Hezkiel Nanda
 * Date: 11/19/13
 */
 
#include "BST.h"

BST::BST() {
	myRoot = NULL;
	myNumItems = 0;
}

BST::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}

BST::Node::Node(const Item& it) {
   myItem = it;
   myLeft = NULL;
   myRight = NULL;
}

BST::Node::~Node() {
	delete myLeft;
	delete myRight;
}

bool BST::isEmpty() const {
	return myNumItems == 0;
}

unsigned BST::getNumItems() const {
	return myNumItems;
}

void BST::traversePreorder() {
	if ( !isEmpty() ) {
		myRoot->traversePreorder();
	}
}

void BST::Node::traversePreorder() {
	processItem();
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
}

void BST::Node::processItem() {
		cout << ' ' << myItem;
}
void BST::traverseInorder(){
	if (myRoot != NULL)
		myRoot->traverseInorder();
}

void BST::Node::traverseInorder(){
	if (myLeft)
		myLeft->traverseInorder();
	processItem();
	if (myRight)
		myRight->traverseInorder();
}

void BST::traversePostorder() {
	if (myRoot != NULL)
		myRoot->traversePostorder();
}

void BST::Node::traversePostorder() {
	if (myLeft != NULL) {
		myLeft->traversePostorder();
	}
	if (myRight != NULL) {
		myRight->traversePostorder();
	}
	processItem();
}

void BST::insert(const Item& it) {
	if (myNumItems == 0) { //empty case
		myRoot = new Node(it);
	} else {
		myRoot->nodeInsert(it);
	}
	myNumItems++;
}

void BST::Node::nodeInsert(const Item& it) {
	if (it > myItem) {
		if (myRight == NULL) {
			myRight = new Node(it);
		} else {
			myRight->nodeInsert(it);
		}
	} else if (it < myItem) {
		if (myLeft == NULL) {
			myLeft = new Node(it);
		} else {
			myLeft->nodeInsert(it);
		}
	} else {
		throw Exception("BST::NODE::nodeInsert()","'it' is already in the BST!");
	}
}

bool BST::contains(const Item& it) {
	if (myNumItems == 0) {
		return false;
	}
	return myRoot->nodeContains(it);
}

bool BST::Node::nodeContains(const Item& it) {
	if (it == myItem) {
		return true;
	} else if (myItem > it && myLeft != NULL) {
		return myLeft->nodeContains(it);
	} else if (myItem < it && myRight != NULL) {
		return myRight->nodeContains(it);
	}
	return false;
}

unsigned BST::getHeight() const{
	if(isEmpty()){
		return 0;
	}
	return myRoot->nodeGetHeight();
}

unsigned BST::Node::nodeGetHeight() const{
	unsigned leftCount = 0;
	unsigned rightCount = 0;
	if(myLeft != NULL)
		leftCount = myLeft->nodeGetHeight();
	if(myRight != NULL)
		rightCount = myRight->nodeGetHeight();
	if (leftCount < rightCount)
		return rightCount+1;
	else
		return leftCount+1;
}

void BST::readFrom(const string& filename){
	int num = 0;
	unsigned count = 0;
	string text = "";
	BST<int> bst;
	ifstream fin(filename.c_str());
	while (getline(fin,text)){
		num = atoi(text.c_str());
		try{
			bst.insert(num);
		} catch (Exception& err){
			count++;
		}
	}
	cout << "The file is created!"
}
