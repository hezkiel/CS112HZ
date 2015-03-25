/*
 * BST.cpp
 *
 *  Created on: Nov 11, 2013
 *      Author: hezkiel
 */

#include "BST.h"

BST::BST() {
	myRoot = NULL;
	mySize = 0;
}

void BST::insert(const Item& it) {
	if (mySize == 0) { //empty case
		myRoot = new Node(it);
	} else {
		myRoot->nodeInsert(it);
	}
	mySize++;

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
		throw logic_error("BST::NODE::Insert() : item ");
	}
}

bool BST::contains(const Item& it) {
	if (mySize == 0) {
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

void BST::preorderTraverse() const {
	if (myRoot != NULL) {
		myRoot->preorder();
	}
}

void BST::Node::preorder() const {
	visit();
	if (myLeft)
		myLeft->preorder();
	if (myRight)
		myRight->preorder();
}

void BST::inorderTraverse() const {
	if (myRoot != NULL)
		myRoot->inorder();
}

void BST::Node::inorder() const {
	if (myLeft)
		myLeft->inorder();
	visit();
	if (myRight)
		myRight->inorder();
}

void BST::postorderTraverse() const {
	if (myRoot != NULL)
		myRoot->postorder();
}

void BST::Node::postorder() const {
	if (myLeft)
		myLeft->postorder();
	if (myRight)
		myRight->postorder();
	visit();
}
