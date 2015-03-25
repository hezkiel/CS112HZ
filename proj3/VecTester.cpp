/*
 * VecTester.cpp
 *
 *  Created on: Sep 23, 2013
 *      Author: hezkiel
 */

#include <cassert>
#include "VecTester.h"
#include <cstdlib> //exit
/*
 *  Regarding destructor of a class: will automate new and delete []
 *
 */
void VecTester::runTests() {
	cout << "Running tests class Vec..." << endl;
	testConstructor();
	testAssignment();
	testSubscript();
	testEquality();
	cout << "All Tests passed!" << endl;
}

void VecTester::testEquality() {
	cout << "-equality.." << flush;
	//empty case
	Vec v0;
	Vec v1;
	assert(v0 == v1);
	cout << " 0 " << flush;
	//non empty, equal
	Vec v2(3);
	Vec v3(3);
	for (unsigned i = 0; i < 3; i++) {
		v2[i] = i + 11;
		v3[i] = i + 11;
	}
	assert(v2 == v3);
	cout << " 1 " << flush;
	//non-empty,non-equal
	v2[0] = 0;
	assert(!(v2 == v3));
	cout << " 2 " << flush;
	v2[0] = 11;
	assert(v2 == v3);
	v2[1] = 0;
	assert(!(v2 == v3));
	cout << " 3 " << flush;
	v2[1] = 12;
	assert(v2 == v3);
	v2[2] = 0;
	assert(!(v2 == v3));
	cout << " 4 " << flush;

	cout << " 5 " << flush;
	cout << "Passed!" << endl;
}

void testReadSubscript(const Vec& v) {
	for (unsigned i = 0; i < 3; i++) {
		assert(v[i] == i + 11);
	}
}

void VecTester::testSubscript() {
	cout << "- subscript... " << flush;
	Vec v0;
	try {
		v0[0];
		cerr << "Subscript succeeded on empty Vec";
		exit(1);
	} catch (range_error& re) {
		cout << " 0 " << flush;
	}
	Vec v1(3);
	for (unsigned i = 0; i < 3; i++) {
		v1[i] = i + 11;
	}
	cout << " 1a " << flush;
	for (unsigned i = 0; i < 3; i++) {
		assert(v1[i] == i + 11);
	}
	cout << " 1b " << flush;

	testReadSubscript(v1);
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void VecTester::testAssignment() {
	cout << "- assignment... " << flush;
//default
	Vec v0;
	Vec v1(3);
	assert(v1.getSize() == 3);
	assert(v1.myArrayPtr !=NULL);
	v1 = v0;
	assert(v1.getSize() == 0);
	assert(v1.myArrayPtr == NULL);
	cout << " 0 " << flush;
	Vec v2(5);
	assert(v2.getSize() == 5);
	assert(v2.myArrayPtr !=NULL);
	for (unsigned i = 0; i < 5; i++) {
		v2.myArrayPtr[i] = i + 11;
	}
	Vec v3(v1);
	assert(v3.getSize() == 0);
	assert(v3.myArrayPtr == NULL);
	v3 = v2;
	assert(v3.getSize() == 5);
	assert(v3.myArrayPtr != NULL);
	for (unsigned i = 0; i < 5; i++) {
		assert(v3.myArrayPtr[i] == i + 11);
	}
	assert(v3.myArrayPtr != v2.myArrayPtr);
	cout << " 1 " << flush;
	Vec v4;
	v4 = v0 = v3;
	assert(v4.getSize() == 5);
	assert(v3.myArrayPtr != NULL);
	for (unsigned i = 0; i < 5; i++) {
		assert(v4.myArrayPtr[i] == i + 11);
	}
	assert(v0.getSize() == 5);
	assert(v0.myArrayPtr != NULL);
	for (unsigned i = 0; i < 5; i++) {
		assert(v0.myArrayPtr[i] == i + 11);
	}
	assert(v4.myArrayPtr != v2.mvoid VecTester::testSubscriptOperator() const{

}yArrayPtr);
	assert(v0.myArrayPtr != v2.myArrayPtr);
	assert(v4.myArrayPtr != v0.myArrayPtr);
	cout << " 2 " << flush;
	cout << "Test Passed!" << endl;
}
void VecTester::testConstructor() {
	cout << "- constructors.. " << flush;
	Vec v; // lifetime of v is in this block
	assert(v.getSize() == 0);
	assert(v.myArrayPtr == NULL); // if it is a private item we should give
	cout << " 0 " << flush;
//explicit
	Vec v1(5);
	assert(v1.getSize() == 5);
	assert(v1.myArrayPtr != NULL);
	for (unsigned i = 0; i < 5; i++) {
		assert(v1.myArrayPtr[i] == 0);
	}
	cout << " 1 " << flush;
//copy constructor
	Vec v2(v);
	assert(v2.getSize() == 0);
	assert(v2.myArrayPtr == NULL);
	cout << " 2 " << flush;
	for (unsigned i = 0; i < 5; i++) {
		v1.myArrayPtr[i] = i + 11;
	}
	Vec v3(v1);
	assert(v3.getSize() == 5);
	assert(v3.myArrayPtr != NULL);
	for (unsigned i = 0; i < 5; i++) {
		assert(v3.myArrayPtr[i] == i + 11);
	}
	assert(v3.myArrayPtr != v1.myArrayPtr); //-> it failed because the address of v3 is the same as v1
	cout << " 3 " << flush;

	cout << "Test passed!" << endl;
//v.~Vec(); v1.~Vec() // automatically destructing the class
}
