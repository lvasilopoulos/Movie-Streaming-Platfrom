#pragma once

#include <string>
#include <set>

using namespace std;


/// <summary>
/// The model of a movie
/// </summary>
class Movie {
public:
	string title;
	int year = 0;
	set<string> directors;
	set<string> actors;
	set<string> genres;
	string texture;

	void print() const;
	string getDirectors() const;
	string getActors() const;
	string getGenres() const;
};

