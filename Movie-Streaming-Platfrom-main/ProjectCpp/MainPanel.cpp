#include "MainPanel.h"

#include <scancodes.h>

#include "TextWidget.h"
#include "Movie.h"
#include "MovieCoverWidget.h"
#include "Selector.h"

using namespace std;


/// <summary>
/// Initializes widgets
/// </summary>
void MainPanel::initWidgets() {
	float header_location[2] = { 32.0f, 10.0f };	

	widgets.push_back(new TextWidget("Film browser", 6, header_location));	
}

/// <summary>
/// Initializes movie collection
/// </summary>
void MainPanel::initMovies() {
	Movie movie;

	movie = Movie();
	movie.title = "Shawshank Redemption";
	movie.texture = cover_path + "TheShawshankRedemption" + ".png";
	movie.year = 1994;
	movie.directors.insert("Stephen King");
	movie.actors.insert("Tim Robbins");
	movie.actors.insert("Morgan Freeman");
	movie.genres.insert("Drama");
	movies.push_back(movie);

	movie = Movie();
	movie.title = "The Godfather";
	movie.texture = cover_path + "TheGodfather" + ".png";
	movie.year = 1972;
	movie.directors.insert("Mario Puzo");
	movie.actors.insert("Marlon Brando");
	movie.actors.insert("Al Pacino");
	movie.actors.insert("James Caan");
	movie.genres.insert("Drama");
	movie.genres.insert("Crime");
	movies.push_back(movie);

	movie = Movie();
	movie.title = "Saving Private Ryan";
	movie.texture = cover_path + "SavingPrivateRyan" + ".png";
	movie.year = 1998;
	movie.directors.insert("Steven Spielberg");
	movie.actors.insert("Tom Hanks");
	movie.actors.insert("Matt Damon");
	movie.actors.insert("Tom Sizemore");
	movie.genres.insert("Action");
	movie.genres.insert("Drama");
	movie.genres.insert("War");
	movies.push_back(movie);

	movie = Movie();
	movie.title = "The Silence of the Lambs";
	movie.texture = cover_path + "TheSilenceofheLambs" + ".png";
	movie.year = 1991;
	movie.directors.insert("Jonathan Demme");
	movie.actors.insert("Jodie Foster");
	movie.actors.insert("Anthony Hopkins");
	movie.actors.insert("Lawrence A.Bonney");
	movie.genres.insert("Crime");
	movie.genres.insert("Drama");
	movie.genres.insert("Mystery");
	movies.push_back(movie);

	movie = Movie();
	movie.title = "Se7en";
	movie.texture = cover_path + "Se7en" + ".png";
	movie.year = 1995;
	movie.directors.insert("David Fincher");
	movie.actors.insert("Morgan Freeman");
	movie.actors.insert("Brad Pitt");
	movie.actors.insert("Kevin Spacey");
	movie.genres.insert("Crime");
	movie.genres.insert("Drama");
	movie.genres.insert("Mystery");
	movies.push_back(movie);

	movie = Movie();
	movie.title = "The Lord of the Rings: The Two Towers";
	movie.texture = cover_path + "theTwoTowers" + ".png";
	movie.year = 2002;
	movie.directors.insert("Peter Jackson");
	movie.actors.insert("Elijah Wood");
	movie.actors.insert("Ian McKellen");
	movie.actors.insert("Viggo Mortensen");
	movie.genres.insert("Action");
	movie.genres.insert("Adventure");
	movie.genres.insert("Drama");
	movies.push_back(movie);

	movie = Movie();
	movie.title = "The Lord of the Rings: The Return of the King";
	movie.texture = cover_path + "lotr-returnoftheking" + ".png";
	movie.year = 2003;
	movie.directors.insert("J.R.R.Tolkien");
	movie.actors.insert("Elijah Wood");
	movie.actors.insert("Ian McKellen");
	movie.actors.insert("Viggo Mortensen");
	movie.genres.insert("Action");
	movie.genres.insert("Adventure");
	movie.genres.insert("Drama");
	movies.push_back(movie);

	movie = Movie();
	movie.title = "Pulp Fiction";
	movie.texture = cover_path + "Pulp-Fiction" + ".png";
	movie.year = 1994;
	movie.directors.insert("Quentin Tarantino");
	movie.actors.insert("John Travolta");
	movie.actors.insert("Uma Thurman");
	movie.actors.insert("Samuel L.Jackson");
	movie.genres.insert("Crime");
	movie.genres.insert("Drama");
	movies.push_back(movie);

	movie = Movie();
	movie.title = "The Lord of the Rings: The Fellowship of the Ring";
	movie.texture = cover_path + "lotr-thefellowshipofthering" + ".png";
	movie.year = 2001;
	movie.directors.insert("J.R.R.Tolkien");
	movie.actors.insert("Elijah Wood");
	movie.actors.insert("Ian McKellen");
	movie.actors.insert("Viggo Mortensen");
	movie.genres.insert("Action");
	movie.genres.insert("Adventure");
	movie.genres.insert("Drama");
	movies.push_back(movie);

	movie = Movie();
	movie.title = "Fight Club";
	movie.texture = cover_path + "fightclub" + ".png";
	movie.year = 1999;
	movie.directors.insert("David Fincher");
	movie.actors.insert("Brad Pitt");
	movie.actors.insert("Edward Norton");
	movie.actors.insert("Meat Loaf");
	movie.genres.insert("Drama");
	movies.push_back(movie);

	cout << "Total movies: " << movies.size() << endl;
}

/// <summary>
/// Initializes cover preview widgets
/// </summary>
void MainPanel::initPreviews() {
	float cover_size[2] = { 12 , 18 };
	float cover_base_location[2] = { 5.5f + cover_size[0] / 2.0f, 15.0f + cover_size[1] / 2.0f };
	float offset_location[2] = { 15.0f , 20.0f };
	int i = 0;
	int j = 0;

	float title_location[2] = { 5.0f, 63.0f };
	float genres_location[2] = { 5.0f, 68.0f };
	float year_location[2] = { 5.0f, 71.0f };
	float directors_location[2] = { 5.0f, 74.0f };
	float actors_location[2] = { 5.0f, 77.0};
	

	movieDetailsWidgets.widgets.push_back(new TextWidget("Title", 3, title_location));
	movieDetailsWidgets.widgets.push_back(new TextWidget("Year", 2, year_location));
	movieDetailsWidgets.widgets.push_back(new TextWidget("Directors", 2, directors_location));
	movieDetailsWidgets.widgets.push_back(new TextWidget("Actors", 2, actors_location));
	movieDetailsWidgets.widgets.push_back(new TextWidget("Genres", 2, genres_location));

	for (list<TextWidget*>::iterator p = movieDetailsWidgets.widgets.begin(); p != movieDetailsWidgets.widgets.end(); ++p) {
		widgets.push_back(*p);
	}
	
	for (list<Movie>::const_iterator p = movies.begin(); p != movies.end(); ++p, i = (i + 1) % 5, j = j + (i == 0)) {
		float cover_location[2] = { cover_base_location[0] + i * offset_location[0], cover_base_location[1] + j * offset_location[1] };

		widgets.push_back(new MovieCoverWidget(*p, filter, movieDetailsWidgets, cover_location, cover_size));
	}
}

/// <summary>
///  Initializes selectors
/// </summary>

void MainPanel::initSelectors() {
	float year_selector_location[2] = { 82.0f, 45.0f };
	float year_selector_size[2] = { 0.5f , 50.0f };

	float genres_selector_location[2] = { 90.0f, 45.0f };
	float genres_selector_size[2] = { 0.5f , 50.0f };

	set<string> years;
	set<string> genres;

	years.insert("");
	genres.insert("");

	for (list<Movie>::const_iterator p = movies.begin(); p != movies.end(); ++p) {
		years.insert(std::to_string(p->year));

		for (string s : (*p).genres) {
			genres.insert(s);
		}
	}

	cout << "Total years: " << years.size() << endl;
	cout << "Total genres: " << genres.size() << endl;

	widgets.push_back(new Selector<string>(filter.year, years, year_selector_location, year_selector_size));
	widgets.push_back(new Selector<string>(filter.genre, genres, genres_selector_location, genres_selector_size));

}

/// <summary>
/// Calls other initialization methods
/// </summary>
void MainPanel::init() {
	graphics::createWindow(window_width, window_height, "Film browser");
	graphics::setWindowBackground(background);
	graphics::setFont(font);
	graphics::setCanvasSize(canvas_width, canvas_height);
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

	initWidgets();
	initMovies ();
	initPreviews();
	initSelectors();
}

/// <summary>
/// Renders all widgets
/// </summary>
void MainPanel::draw() {
	graphics::MouseState ms;
	getMouseState(ms);

	float mx = graphics::windowToCanvasX(1.0f * ms.cur_pos_x);
	float my = graphics::windowToCanvasY(1.0f * ms.cur_pos_y);

	for (list<Widget*>::iterator p = widgets.begin(); p != widgets.end(); ++p) {
		(*p)->draw(mx, my);
	}
}

/// <summary>
/// Updates all widgets
/// </summary>
/// <param name="t">SGG ms</param>
void MainPanel::update(float t) {
	graphics::MouseState ms;
	getMouseState(ms);

	float mx = graphics::windowToCanvasX(1.0f * ms.cur_pos_x);
	float my = graphics::windowToCanvasY(1.0f * ms.cur_pos_y);

	for (list<Widget*>::iterator p = widgets.begin(); p != widgets.end(); ++p) {
		(*p)->update(mx, my, t);
	}

	if (graphics::getKeyState(graphics::scancode_t::SCANCODE_ESCAPE)) {
		graphics::stopMessageLoop();
	}
}
