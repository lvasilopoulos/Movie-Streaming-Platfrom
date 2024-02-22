#pragma once

#include <string>

#include "Widget.h"
#include <graphics.h>
#include "FilmBrowserBrushes.h"

using namespace std;

/// <summary>
/// A simple text widget
/// </summary>
class TextWidget : public Widget {
public:
	graphics::Brush brush = FilmBrowserBrushes::white();
	string text;
	float size;

	TextWidget(string text, float size, float r[2]);

	virtual void do_draw();
};

