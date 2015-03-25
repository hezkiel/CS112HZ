/*
 * VecTester.h
 *
 *  Created on: Sep 23, 2013
 *      Author: hezkiel
 */

#ifndef VECTESTER_H_
#define VECTESTER_H_

#include "Vec.h"



class VecTester {
public:
	void runTests();
	void testConstructor();
	void testAssignment();
	void testSubscript();
//    void testReadSubscript(const Vec& v);
	void testEquality();

};

#endif /* VECTESTER_H_ */
