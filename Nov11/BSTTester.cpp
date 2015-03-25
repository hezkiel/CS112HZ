/*
 * BSTTester.cpp
 *
 *  Created on: Nov 11, 2013
 *      Author: hezkiel
 */

#include "BSTTester.h"
#include "BST.h"
#include <cassert>
using namespace std;

void BST_Tester::runTests() {
	cout << "Testing class BST..." << endl;
	testConstructor();
	testInsert();
	testContains();
	testTraversals();
	cout << "All tests passed!" << endl;
}

void BST_Tester::testInsert() {
	cout << "-Insert..." << flush;
	BST bst;
	bst.insert(44);
	assert(bst.getSize() == 1);
	assert(bst.myRoot->myItem == 44);
	assert(bst.myRoot->myLeft == NULL);
	assert(bst.myRoot->myRight == NULL);
	cout << " 0 " << flush;
	bst.insert(66);
	assert(bst.getSize() == 2);
	assert(bst.myRoot->myItem == 44);
	assert(bst.myRoot->myLeft == NULL);
	assert(bst.myRoot->myRight != NULL);
	assert(bst.myRoot->myRight->myItem == 66);
	assert(bst.myRoot->myRight->myLeft == NULL);
	assert(bst.myRoot->myRight->myRight == NULL);
	cout << " 1 " << flush;
	cout << " Test Passed! " << endl;
}
void BST_Tester::testConstructor() {
	cout << "-Constructors..." << flush;
	BST bst;
	assert(bst.getSize() == 0);
	cout << " 0 " << flush;
	cout << " Test Passed! " << endl;
}
void BST_Tester::testContains() {
	cout << "-Contains..." << flush;
	BST bst;
	assert(!bst.contains(44));
	cout << " 0 " << flush;
	bst.insert(44);
	assert(bst.contains(44));
	cout << " 1 " << flush;
	bst.insert(22);
	assert(bst.contains(22));
	assert(bst.contains(44));
	cout << " 2 " << flush;
	bst.insert(33);
	assert(bst.contains(22));
	assert(bst.contains(44));
	assert(bst.contains(33));
	assert(!bst.contains(11));
	cout << " 3 " << flush;
	bst.insert(11);
	assert(bst.contains(22));
	assert(bst.contains(44));
	assert(bst.contains(33));
	assert(bst.contains(11));
	assert(!bst.contains(66));
	cout << " 4 " << flush;
	bst.insert(66);
	assert(bst.contains(22));
	assert(bst.contains(44));
	assert(bst.contains(33));
	assert(bst.contains(11));
	assert(bst.contains(66));
	assert(!bst.contains(77));
	cout << " 5 " << flush;
	bst.insert(77);
	assert(bst.contains(22));
	assert(bst.contains(44));
	assert(bst.contains(33));
	assert(bst.contains(11));
	assert(bst.contains(66));
	assert(bst.contains(77));
	assert(!bst.contains(55));
	cout << " 6 " << flush;
	bst.insert(55);
	assert(bst.contains(22));
	assert(bst.contains(44));
	assert(bst.contains(33));
	assert(bst.contains(11));
	assert(bst.contains(66));
	assert(bst.contains(77));
	assert(bst.contains(55));
	cout << " 7 " << flush;
	cout << " Passed! " << endl;

}

void BST_Tester::testTraversals() {
	cout << "-Traversals..." << flush;
	BST bst;
	bst.insert(44);
	bst.insert(66);
	bst.insert(77);
	bst.insert(55);
	bst.insert(22);
	bst.insert(33);
	bst.insert(11);
	cout << "\npreorder: " << flush;
	bst.preorderTraverse();
	cout << "\ninorder: " << flush;
	bst.inorderTraverse();
	cout << "\npostorder: " << flush;
	bst.postorderTraverse();
	cout << " Passed! " << endl;
}
