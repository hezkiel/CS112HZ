/*
 * Vec.h
 *
 *  Created on: Sep 23, 2013
 *      Author: hezkiel
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
#include <stdexcept>
using namespace std;

typedef double Item; // defining the type of 'Item'. for example if we dont want to use double, we can change it in here only. a generic type

class Vec {
public:
	Vec(); // default constructor
	Vec(unsigned int size); // it will make changes so no const // invoke constructor
	Vec(const Vec & original);
	~Vec(); // anti constructor = destructor
	unsigned getSize() const {
		return mySize;
	} // this is a definition, more efficient.
	Vec& operator=(const Vec& original);
	Item& operator[](unsigned i);
	const Item& operator[](unsigned i) const;
	bool operator==(const Vec& v2) const;
private:
	unsigned mySize;
	Item * myArrayPtr;

	void makeCopyOf(const Vec& original);

	friend class VecTester;
	//give full access to Vec private
};

#endif /* VEC_H_ */
