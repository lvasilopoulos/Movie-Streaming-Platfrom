#include "Movie.h"

#include <iostream>

using namespace std;


/// <summary>
/// Prints a movie to terminal, used for testing
/// </summary>
void Movie::print() const {
	cout << title << endl;
	cout << year << endl;

	cout << "Directors " << endl;
	for (set <string>::iterator p = directors.begin(); p != directors.end(); ++p) {
		cout << *p << "\t";
	}
	cout << endl;

	cout << "Actors " << endl;
	for (set <string>::iterator p = actors.begin(); p != actors.end(); ++p) {
		cout << *p << "\t";
	}
	cout << endl;

	cout << "Genres " << endl;
	for (set <string>::iterator p = genres.begin(); p != genres.end(); ++p) {
		cout << *p << "\t";
	}
	cout << endl;
}

/// <summary>
/// Simple accessor
/// </summary>
/// <returns>Directors as string</returns>
string Movie::getDirectors() const {
	string buffer = "";

	for (string s : directors) {
		buffer += s + "   ";
	}
	return buffer;
}

/// <summary>
/// Simple accessor
/// </summary>
/// <returns>Actors as string</returns>
string Movie::getActors() const {
	string buffer = "";

	for (string s : actors) {
		buffer += s + "   ";
	}
	return buffer;
}

/// <summary>
/// Simple accessor
/// </summary>
/// <returns>Genres as string</returns>
string Movie::getGenres() const {
	string buffer = "";

	for (string s : genres) {
		buffer += s + "   ";
	}
	return buffer;
}
