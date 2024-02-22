#include <iostream>

#include "MovieCoverWidget.h"

using namespace std;

/// <summary>
/// Creates amovie widget
/// </summary>
/// <param name="movie">the bound movie</param>
/// <param name="filter">filter options</param>
/// <param name="details">details options</param>
/// <param name="r">location</param>
/// <param name="s">size</param>
MovieCoverWidget::MovieCoverWidget(const Movie& movie, MovieFilter& filter, MovieDetailsWidgets& details, float r[2], float s[2]) : ImageWidget(movie.texture, r, s), movie(movie), details(details), filter(filter) {
	enable_hover = true;
	enable_click = false;
}


/// <summary>
/// Updates the widget
/// </summary>
/// <param name="ms"></param>
void MovieCoverWidget::do_update(float ms) {
	if (filter.year != "" || filter.genre != "") {
		// check filter
		if (filter.year != "") {
			int y = atoi(filter.year.c_str());
			if (y != movie.year) {
				visible = false;
				return;
			}
		}

		if (filter.genre != "") {
			bool ok = false;

			for (string s : movie.genres) {
				if (s == filter.genre) {
					ok = true;
					break;
				}
			}

			if (!ok) {
				visible = false;
				return;
			}							
		}			
	}

	visible = true;




	if (hover) {
		brush.outline_opacity = 1.0f;
		brush.outline_color[0] = 1.0f;
		brush.outline_color[1] = 1.0f;
		brush.outline_color[2] = 1.0f;

		if (details.cache != this) {
			details.cache = this;
			//Enable view details if hover is enable
			int i = 0;
			for (list<TextWidget*>::iterator p = details.widgets.begin(); p != details.widgets.end(); ++p,++i) {
				switch (i) {				
				case 0:
					(*p)->text = movie.title;
					break;
				case 1:
					(*p)->text = "Year: " + std::to_string(movie.year);
					break;
				case 2:
					(*p)->text = "Directors: " + movie.getDirectors();
					break;
				case 3:
					(*p)->text = "Actors: " + movie.getActors();
					break;
				case 4:
					(*p)->text = movie.getGenres();
					break;
				}
			}
		}
	} else {
		brush.outline_opacity = 1.0f;
		brush.outline_color[0] = 0.0f;
		brush.outline_color[1] = 0.0f;
		brush.outline_color[2] = 0.0f;
	}
}

/// <summary>
///  performs click events
/// </summary>
/// <param name="mx">mouse mx</param>
/// <param name="my">mouse my</param>
void MovieCoverWidget::do_click(float mx, float my) {
	cout << "Movie clicked: " << movie.title << endl;
}
