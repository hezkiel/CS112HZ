/* MovieTester.h declares variables in MovieTester class.
 * Student Name: Hezkiel A. Nanda
 * Date: Sept 16, 2013
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Assignment: Project #1
 */

#ifndef MOVIETESTER_H_
#define MOVIETESTER_H_

#include "Movie.h"
#include <iostream>
using namespace std;

class MovieTester {
public:
   void runTests() const;
   void testDefaultConstructor() const;
   void testExplicitConstructor() const;
   void testReadFrom() const;
   void testWriteTo() const;
   void testOperator() const;
};

#endif /*MOVIETESTER_H_*/
