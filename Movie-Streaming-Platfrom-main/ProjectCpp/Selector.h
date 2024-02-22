#pragma once

#include <string>
#include <set>
#include <map>
#include <graphics.h>
#include "Widget.h"
#include"FilmBrowserBrushes.h"

using namespace std;

/// <summary>
/// The slider for genres and years
/// It contains a set with the available options, a map to find the option from its index on screen
/// a selected index that stores the current choice and a target that stores the resulted value when clicked
/// </summary>
template <typename T>
class Selector : public Widget {
private:
	graphics::Brush brush = FilmBrowserBrushes::white();
	set<T> options;
	map<int, T> choices;
	int selected = 0;
	string& target;
public:
	Selector(string & target, set<T> options, float r[2], float s[2]) : target(target), options(options) {
		this->r[0] = r[0];
		this->r[1] = r[1];
		this->s[0] = s[0];
		this->s[1] = s[1];

		this->enable_hover = true;
		this->enable_click = true;

		this->top_left[0] = r[0] - s[0] / 2.0f - 0.5f;
		this->top_left[1] = r[1] - s[1] / 2.0f - 1.0f;

		this->bottom_right[0] = r[0] + s[0] / 2.0f + 5.0f;
		this->bottom_right[1] = r[1] + s[1] / 2.0f + 1.0f;


		int id = 0;

		for (typename set<T>::iterator p = options.begin(); p != options.end(); ++p) {
			choices[id++] = *p;
		}
	}

	virtual void do_draw() {
		graphics::drawRect(r[0], r[1], s[0], s[1], brush);

		float r[2] = { this->r[0] + 0.8f, this->r[1] + 0.2f };
		float y = r[1] - s[1]/2.0f;

		const float dy = s[1] / (options.size() - 1.0f);

		for (typename set<T>::iterator p = options.begin(); p != options.end(); ++p) {
			graphics::drawText(r[0], y, 2, *p, brush);
			y += dy;
		}

		graphics::drawRect(r[0]-0.8f, r[1] - s[1] / 2.0f + selected * dy, 1.5f, 0.3f, brush);
	}

	virtual void do_click(float mx, float my) {
		float r[2] = { this->r[0] + 0.8f, this->r[1] + 0.2f };
		float y = r[1] - s[1] / 2.0f;

		const float dy = s[1] / (options.size() - 1.0f);

		selected = (int) ((my - y + dy/2.0f) / dy);

		if (selected < 0) {
			selected = 0;
		} else if (selected >= options.size()) {
			selected = ((int) options.size()) - 1;
		}

		target = choices[selected];

		cout << "selector clicked, select: " << selected << ", y=" << y << ",dy= " << dy << ",my="<< my << endl;
		cout << "Target: " << target << endl;
	}
};

