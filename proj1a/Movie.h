/* Movie.h declares variables in Movie class.
 * Student Name: Hezkiel A. Nanda
 * Date: Sept 16, 2013
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Assignment: Project #1
 */

#ifndef MOVIE_H_
#define MOVIE_H_

#include <string>
using namespace std;

class Movie {
public:
   Movie();
   Movie (const string& title, int year, const string& director);
   string getTitle() const;
   int getYear() const;
   string getDirector() const;
   void readFrom(istream& in);
   void writeTo(ostream& out)const;
   bool operator==(const Movie& movie2) const;
private:
   string myTitle;
   int myYear;
   string myDirector;
};

#endif /*MOVIE_H_*/
