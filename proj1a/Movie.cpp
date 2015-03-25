/* Movie.cpp defines the Movie class methods.
 * Student Name: Hezkiel A. Nanda
 * Date: Sept 16, 2013
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Assignment: Project #1
 */

#include "Movie.h"
#include <string>
#include <istream>


Movie::Movie() {
	myTitle = "";
	myYear = 0;
	myDirector = "";
}

Movie::Movie(const string& title, int year, const string& director) {
	myTitle = title;
	myYear = year;
	myDirector = director;
}

string Movie::getTitle() const {
	return myTitle;
}

int Movie::getYear() const {
	return myYear;
}

string Movie::getDirector() const {
	return myDirector;
}

void Movie::readFrom(istream& in) {
	getline(in, myTitle);
	in >> myYear;
	string newLine;
	getline(in, newLine);
	getline(in, myDirector);
}

void Movie::writeTo(ostream& out) const {
	out << myTitle << '\n'
	    << myYear  << '\n'
	    << myDirector << '\n';
}

bool Movie::operator== (const Movie& movie2) const{
	if (myTitle == movie2.getTitle() and myYear == movie2.getYear() and myDirector == movie2.getDirector()){
	return true;
	}
	return false;
}
