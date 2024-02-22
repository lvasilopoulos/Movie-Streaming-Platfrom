#pragma once

#include <list>
#include "Widget.h"
#include "TextWidget.h"

using namespace std;

/// <summary>
/// Details of a movie. Contains a list of textfields that display the attributes of a movie
/// </summary>
class MovieDetailsWidgets {
public:
	Widget* cache;
	list<TextWidget*> widgets;

	MovieDetailsWidgets();
};

