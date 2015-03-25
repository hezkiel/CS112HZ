/* MovieCollection.h declares variables in MovieCollection class.
 * Student Name: Hezkiel A. Nanda
 * Date: Sept 16, 2013
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Assignment: Project #1
 */

#ifndef MOVIECOLLECTION_H_
#define MOVIECOLLECTION_H_

#include <string>
#include "Movie.h"
#include <vector>
#include <cassert>
using namespace std;

class MovieCollection {
public:
   MovieCollection(const string& fileName);
   vector<Movie> searchByDirector(const string& directorName) const;
   vector<Movie> searchByYear (int year) const;
   vector<Movie> searchByTitlePhrase (const string& phrase) const;
   void addMovie (const Movie& newMovie);
   void removeMovie (const Movie& aMovie);
   void save() const;
private:
	vector<Movie> myMovies;

};

#endif /*MOVIECOLLECTION_H_*/
