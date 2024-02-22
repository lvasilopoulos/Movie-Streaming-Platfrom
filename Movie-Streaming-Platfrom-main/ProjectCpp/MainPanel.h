#pragma once

#include <iostream>
#include <random>
#include <string>
#include <list>

#include <graphics.h>
#include "FilmBrowserBrushes.h"
#include "Widget.h"
#include "Movie.h"
#include "MovieDetailsWidgets.h"
#include "MovieFilter.h"

using namespace std;

/// <summary>
/// Main screen.
/// 
/// Main scren contains all the widgets, movies, the details structure and the filter structure
/// It is based on the game example
/// </summary>
class MainPanel {
private:
	list<Widget*> widgets;
	list<Movie> movies;
	MovieDetailsWidgets movieDetailsWidgets;
	MovieFilter filter;

	void initWidgets();
	void initMovies();
	void initPreviews();
	void initSelectors();
public:
	const int window_width = 1024;
	const int window_height = 768;
	const float canvas_width = 100.0f;
	const float canvas_height = 100.0f;
	const graphics::Brush background = FilmBrowserBrushes::black();
	const std::string assets_path = "assets/";
	const std::string cover_path = assets_path + "Covers/thumb_";
	const std::string font = assets_path + "fonts/OpenSans-Regular.ttf";

	void init();
	void draw();
	void update(float ms);
	
};

