#include "Widget.h"

#include <graphics.h>

using namespace std;

void Widget::draw(float mx, float my) {
	if (visible) {					
		do_draw();
	}
}

void Widget::update(float mx, float my, float ms) {
	if (visible) {
		hover = false;

		if (enable_hover) {
			hover = mx >= top_left[0] && mx <= bottom_right[0] && my >= top_left[1] && my <= bottom_right[1];
		}

		if (enable_click) {
			graphics::MouseState ms;
			getMouseState(ms);

			if (ms.button_left_pressed) {
				if (hover) {
					do_click(mx, my);
				}
			}
		}		
	}

	do_update(ms);
}

void Widget::do_update(float ms) {

}


void Widget::do_click(float mx, float my) {
}
