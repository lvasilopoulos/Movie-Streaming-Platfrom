#pragma once

#include <string>

#include "Widget.h"
#include <graphics.h>
#include "FilmBrowserBrushes.h"

using namespace std;

/// <summary>
/// An image widget rendes a simple image.
/// </summary>
class ImageWidget : public Widget {
public:
	graphics::Brush brush = FilmBrowserBrushes::opaque();
	string texture;

	ImageWidget(string texture, float r[2], float s[2]);

	virtual void do_draw();
};

