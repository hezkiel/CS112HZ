/* main.cpp performs the main functions.
 * Student Name: Hezkiel A. Nanda
 * Date: Sept 16, 2013
 * Assignment: Project #1
 */


#include "MovieTester.h" // Movie class tester file
#include "CollectionTester.h" // collection class tester file
#include "MovieCollection.h" // MovieCollection mc
#include "Movie.h" // Movie newMovie
#include <iostream> // cout,  cin, cin.ignore()
#include <string> //string and getline
using namespace std;

void mainmenu() {
		// Variables used in the mainmenu:
		MovieCollection mc("testCollection.txt");
	    unsigned char userAnswer = '7';
	    string newMovieTitle;
	    int newMovieYear;
	    string newMovieDirector;

	    // looping begins for the mainmenu display:
		while (userAnswer == '7' or userAnswer == 'g'){
			//main display:
			cout << "Welcome to Phil's Movie Collection Manager!";
			cout << "\nThe options are as follows:";
			cout << "\n  1 - search the collection for movies by a given director";
			cout << "\n  2 - search the collection for movies made in a given year";
			cout << "\n  3 - search the collection for movies with a given phrase in their title";
			cout << "\n  4 - add a new movie to the collection";
			cout << "\n  5 - remove a movie from the collection";
			cout << "\n  6 - save the collection";
			cout << "\n  0 - quit";
			cout << "\n Please enter your answer:";
			cin >> userAnswer;
			cout << "You have answered:" << userAnswer << endl;

				// 1st option: searching for titles of the movie based on the director's name [works with first character in capital].
				if (userAnswer == '1' or userAnswer == 'a'){
					string directorName;
					cout << "\n Please give the name of the director: ";
					cin >> directorName;
					vector<Movie> v1 = mc.searchByDirector(directorName);
					if(v1.size() !=0 ){
						cout << "The result[s] are: " << endl;
						for (unsigned i = 0; i < v1.size(); i++ ){
							cout << v1[i].getTitle() << endl;
						}
					} else{
						cout << "There is no result." << endl;
					}
					cout << "\n Do you want to do another search?";
					cout << "\n Press '7' or 'g' to go back to main menu. Otherwise press '0' to quit. Your input: ";
					cin >> userAnswer;
				}

				// 2nd option: searching for titles of the movie based on the year
				if (userAnswer == '2' or userAnswer == 'b'){
					unsigned int year;
					cout << "\n Please input the year of the movie title: ";
					cin >> year;
					vector<Movie> v1 = mc.searchByYear(year);
					if(v1.size() !=0 ){
						cout << "The result[s] are: " << endl;
						for (unsigned i = 0; i < v1.size(); i++ ){
							cout << v1[i].getTitle() << endl;
						}
					} else{
						cout << "There is no result." << endl;
					}
					cout << "\n Do you want to do another search?";
					cout << "\n Press '7' or 'g' to go back to main menu. Otherwise press '0' to quit. Your input: ";
					cin >> userAnswer;
				}

				// 3rd option: searching for titles of the movie based on the phrase in the title [works with exact characters]
				if (userAnswer == '3' or userAnswer == 'c'){
					string titlePhrase;
					cout << "\n Please give the phrase of the movie title: ";
					cin >> titlePhrase;
					vector<Movie> v1 = mc.searchByTitlePhrase(titlePhrase);
					if(v1.size() !=0 ){
						cout << "The result[s] are: " << endl;
						for (unsigned i = 0; i < v1.size(); i++ ){
							cout << v1[i].getTitle() << endl;
						}
					} else{
						cout << "There is no result." << endl;
					}
					cout << "\n Do you want to do another search?";
					cout << "\n Press '7' or 'g' to go back to main menu. Otherwise press '0' to quit. Your input: ";
					cin >> userAnswer;
				}

				// 4th option: adding a new movie to the "movieTest2.txt" collection [without save]
				if (userAnswer == '4' or userAnswer == 'd'){
					cout << "Please insert the title of the movie that you want to add: ";
					//cin.ignore() is used for discarding characters until newline is found.
					cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
					getline (cin,newMovieTitle);
					cout << "Please insert the year of the movie: ";
					cin >> newMovieYear;
					cout << "Please insert the Director's name of the movie "<< newMovieTitle<< ": ";
					cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
					getline(cin,newMovieDirector);

					Movie newMovie (newMovieTitle, newMovieYear, newMovieDirector);
					mc.addMovie(newMovie);

					cout << "\n Movie "<< newMovieTitle << "has been added to the collection.";
					cout << "\n Press '0' or 'o' to quit. Press '7' or 'g' to go back to the main menu. Your input: ";
					cin >> userAnswer;
				}

				// 5th option: removing a movie from the "movieTest2.txt" collection [without save]
				if (userAnswer == '5' or userAnswer == 'e'){
					cout << "Please insert the title of the movie that you want to delete: ";
					cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
					getline (cin,newMovieTitle);
					cout << "Please insert the year of the movie: ";
					cin >> newMovieYear;
					cout << "Please insert the Director's name of the movie "<< newMovieTitle<< ": ";
					cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
					getline(cin,newMovieDirector);

					Movie delMovie (newMovieTitle, newMovieYear, newMovieDirector);
					mc.removeMovie(delMovie);

					cout << "\n Movie "<< newMovieTitle << "has been deleted from the collection.";
					cout << "\n Press '0' or 'o' to quit. Press '7' or 'g' to go back to the main menu. Your input: ";
					cin >> userAnswer;
				}

				// 6th option: saving all changes made to the "movieTest2.txt" collection
				if (userAnswer == '6' or userAnswer == 'f'){
					mc.save();
					cout << "\n The changes in the collection has been saved.";
					cout << "\n Do you want to do another search?";
					cout << "\n Press '7' or 'g' to go back to main menu. Otherwise press '0' to quit. Your input: ";
					cin >> userAnswer;
				}

				// wrong input protocol
				if (userAnswer >= '7' or userAnswer >= 'g'){
					cout << "Wrong input. Please try again." <<endl;
					userAnswer = '7';
				}

		}
		cout << "See you next time!"<< endl;
}

int main() {

// tester:
//	MovieTester mt;
//    mt.runTests();
//    CollectionTester ct;
//    ct.runTests();

// Main menu from mainmenu.h:
	mainmenu();

	return 0;
}


