/* CollectionTester.cpp defines the MovieCollection test-methods.
 * Student Name: Hezkiel A. Nanda
 * Date: Sept 16, 2013
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Assignment: Project #1
 */

#include "CollectionTester.h"
#include "MovieCollection.h"
#include "Movie.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
using namespace std;

void CollectionTester::runTests() const {
   cout << "Testing class MovieCollection..." << endl;
   testConstructor();
   testSaveMovie();
   testRemoveMovie();
   cout << "All Movie Collection tests passed!" << endl;
}

void CollectionTester::testConstructor() const {
    cout << "- constructor..." << flush;
    MovieCollection mc("testCollection.txt");
    // case of 1 movie
    vector<Movie> v1 = mc.searchByDirector("Hand");
    assert( v1.size() == 1 );
    assert( v1[0].getTitle() == "Bambi" );
    cout << " 1 " << flush;
    // case of 2 movies
    vector<Movie> v2 = mc.searchByDirector("Spielberg");
    assert( v2.size() == 2 );
    assert( v2[0].getTitle() == "Jaws" );
    assert( v2[1].getTitle() == "Raiders of the Lost Ark" );
    cout << " 2 " << flush;
    // case of no movies
    vector<Movie> v3 = mc.searchByDirector("Hitchcock");
    assert( v3.size() == 0 );
    cout << " 3 " << flush;

	//new assertions for testing searchByYear() and searchByTitlePhrase() for a MovieCollection class
   // case of 1 movie
   vector<Movie> v4 = mc.searchByYear(1981);
   assert( v4.size() == 1 );
   assert( v4[0].getTitle() == "Raiders of the Lost Ark" );
   cout << " 4 " << flush;
   // case of 2 movies
   vector<Movie> v5 = mc.searchByYear(1939);
   assert( v5.size() == 2 );
   assert( v5[0].getTitle() == "Gone with the Wind" );
   assert( v5[1].getTitle() == "The Wizard of Oz" );
   cout << " 5 " << flush;
   // case of no movies
   vector<Movie> v6 = mc.searchByYear(1919);
   assert( v6.size() == 0 );
   cout << " 6 " << flush;

   // case of 1 movie
   vector<Movie> v7 = mc.searchByTitlePhrase("Gone");
   assert( v7.size() == 1 );
   assert( v7[0].getTitle() == "Gone with the Wind" );
   cout << " 7 " << flush;
   // case of 2 movies
   vector<Movie> v8 = mc.searchByTitlePhrase("the");
   assert( v8.size() == 2 );
   assert( v8[0].getTitle() == "Gone with the Wind" );
   assert( v8[1].getTitle() == "Raiders of the Lost Ark" );
   cout << " 8 " << flush;
   // case of no movies
   vector<Movie> v9 = mc.searchByTitlePhrase("Stars");
   assert( v9.size() == 0 );
   cout << " 9 " << flush;
   cout << " Passed!" << endl;
}

/* testSaveMovie() is testing the addMovie function from the MovieCollection class.
    *
    * @param: none
    * Precondition: the collection "movieTest2.txt" has no newMovie specific variables.
    * Postcondition: newMovie is added and saved inside the collection "movieTest2.txt"
    */
void CollectionTester::testSaveMovie() const {
	cout << "- saving database Movie..." << flush;

	MovieCollection mc("movieTest2.txt");
	Movie newMovie ("The Shawshank Redemption", 1994, "Frank Darabont");
	mc.addMovie(newMovie);

	vector<Movie> v1 = mc.searchByDirector("Frank");
	assert( v1.size() == 1);
	cout << " 0 " << flush;

	mc.save();

	cout << " 1 " << flush;
	cout << "Passed!" <<endl;
}

/* testRemoveMovie() is testing the addMovie function from the MovieCollection class.
    *
    * @param: none
    * Precondition: the collection "movieTest2.txt" has newMovie specific variables.
    * Postcondition: newMovie is removed and saved inside the collection "movieTest2.txt"
    */
void CollectionTester::testRemoveMovie() const{
	cout << "- rechecking database Movie..." << flush;
	MovieCollection mc("movieTest2.txt");
	Movie newMovie ("The Shawshank Redemption", 1994, "Frank Darabont");
	mc.removeMovie(newMovie);
	mc.save();
	vector<Movie> v1 = mc.searchByDirector("Frank");
	assert( v1.size() == 0 );
	cout << "Passed!" <<endl;
}
