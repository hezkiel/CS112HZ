/*
 * main.cpp
 *
 *  Created on: Sep 23, 2013
 *      Author: hezkiel
 */

#include <iostream>
#include "VecTester.h"
using namespace std;

/*
 * Assignment this week: (1970s C-style stuff)
 * Type * variable = NULL; [ 0 ]
 *  variable = new type (); [] -> [type, object, method f(), ...]
 *  variable -> f()
 *  double * ptr = new double [5]; [] -> [][][][][] block of memory
 *  delete [] ptr; will delete the pointer.
 *  (in C++)
 */

int main() {
	VecTester vt;
	vt.runTests();
}


