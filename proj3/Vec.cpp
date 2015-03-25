/*
 * Vec.cpp
 *
 *  Created on: Sep 23, 2013
 *      Author: hezkiel
 */

#include "Vec.h"

Vec::Vec() {
	mySize = 0;
	myArrayPtr = NULL;
}
/*
 * Classes containing pointer members:
 * Constructors
 * 	- default : initialize the pointer to NULL
 * 	- explicit: initialize the pointer to address of dynamically allocated memory
 * 	- copy: to make distinct copies
 * Destructor: reclaim the dynamically allocated memory
 *
 * ex:
 * void f(Vec v){ -> makes a copy of the argument
 * 		...
 * }
 * f(v1) there is a default copy constructor that makes a bit-by-bit copy of the argument.
 *
 * Vec (g() { -> make a copy of result.
 * 		vec result;
 * 		...
 * 		return result
 * }
 */
Vec::Vec(unsigned int size) {
	mySize = size;
	myArrayPtr = new Item[size](); //this is the faster way
//	for (unsigned i = 0; i < size; i++){
//		myArrayPtr[i] = 0;
//	} //this requires many characters.
}

void Vec::makeCopyOf(const Vec& original) {
	mySize = original.mySize;
	if (original.mySize > 0) {
		myArrayPtr = new Item[mySize];
		for (unsigned i = 0; i < mySize; i++) {
			myArrayPtr[i] = original.myArrayPtr[i];
		}
	} else {
		myArrayPtr = NULL;
	}
}

Vec::Vec(const Vec & original) {
	makeCopyOf(original);
}

Vec::~Vec() {
	delete[] myArrayPtr;
//	cout << "Array deleted! " << flush;
}

Vec& Vec::operator=(const Vec& original) {
	if (this != &original) {
		delete[] myArrayPtr;
		makeCopyOf(original);
	}
	return *this;
}

//v.setItem(i,val)
//Item getItem(i) ->value
Item& Vec::operator[](unsigned i) {
	if (i >= mySize) {
		throw range_error("Vec Subscript: index too large");
	}
	return myArrayPtr[i];
}

const Item& Vec::operator[](unsigned i) const{
	if (i >= mySize) {
		throw range_error("Vec Subscript: index too large");
	}
	return myArrayPtr[i];
}

bool Vec::operator==(const Vec& v2) const {
	if (mySize != v2.mySize) {
		return false;
	}
	for (unsigned i = 0; i < mySize; i++) {
		if (myArrayPtr[i] != v2[i]) {
			return false;
		}
	}
	return true;
}
