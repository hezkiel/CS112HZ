/* MovieCollection.cpp defines the MovieCollection class methods.
 * Student Name: Hezkiel A. Nanda
 * Date: Sept 16, 2013
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Assignment: Project #1
 */

#include "MovieCollection.h"
#include <fstream>
using namespace std;

MovieCollection::MovieCollection(const string& fileName) {
	ifstream fin( fileName.c_str() );
	assert( fin.is_open() );

	Movie aMovie;
	while (true) {
		aMovie.readFrom(fin);
		if ( !fin ) break;
		string blankLine;
		getline(fin, blankLine);
		myMovies.push_back(aMovie);
	}
	fin.close();
}

vector<Movie> MovieCollection::searchByDirector(const string& directorName) const {
   vector<Movie> v;
   for (unsigned i = 0; i < myMovies.size(); i++) {
      if ( myMovies[i].getDirector().find(directorName) != string::npos ) {
         v.push_back( myMovies[i] );
      }
   }
   return v;
}

/* searchByYear() is searching movies from the MovieCollection class by a given year.
    *
    * @param: year, an integer containing the specific year.
    * @return: a vector containing all movies in the collection in which myYear = year.
    */
vector<Movie> MovieCollection::searchByYear (int year) const{
	vector<Movie> v;
	   for (unsigned i = 0; i < myMovies.size(); i++) {
	      if ( myMovies[i].getYear() == year ) {
	         v.push_back( myMovies[i] );
	      }
	   }
	   return v;
}

/* searchByTitlePhrase() is searching movies from the MovieCollection class by a given title phrase.
    *
    * @param: phrase, a constant string that contains the specific phrase.
    * @return: a vector containing all movies in the collection in which variable phrase is the substring of myTitle.
    */
vector<Movie> MovieCollection::searchByTitlePhrase (const string& phrase) const{
	vector<Movie> v;
	   for (unsigned i = 0; i < myMovies.size(); i++) {
	      if ( myMovies[i].getTitle().find(phrase) != string::npos ) {
	         v.push_back( myMovies[i] );
	      }
	   }
	   return v;
}

void MovieCollection::addMovie (const Movie& newMovie) {
	myMovies.push_back(newMovie);
}

void MovieCollection::removeMovie (const Movie& aMovie){
	vector<Movie>::iterator i = myMovies.begin();
   while ( i != myMovies.end()) {
	if ( i->getTitle() == aMovie.getTitle()){
		 i = myMovies.erase(i);
	}
	else {
		++i;
	}
   }
}

void MovieCollection::save() const{
	ofstream fout ("movieTest2.txt");
	for (unsigned i = 0; i < myMovies.size(); i++) {
		myMovies[i].writeTo(fout);
		fout << "\n";
	}
	fout.close();
}
