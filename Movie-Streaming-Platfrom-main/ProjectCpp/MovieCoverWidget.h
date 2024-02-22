#pragma once

#include <string>

#include "Widget.h"
#include <graphics.h>
#include "FilmBrowserBrushes.h"
#include "ImageWidget.h"
#include "Movie.h"
#include "MovieDetailsWidgets.h"
#include "MovieFilter.h"

/// <summary>
/// A widget to display a cover on the screen
/// </summary>
class MovieCoverWidget : public ImageWidget {
private:
	const Movie& movie;
	MovieDetailsWidgets& details;
	MovieFilter& filter;
public:
	MovieCoverWidget(const Movie & movie, MovieFilter & filter, MovieDetailsWidgets& details, float r[2], float s[2]);

	virtual void do_update(float ms);

	virtual void do_click(float mx, float my);
};

