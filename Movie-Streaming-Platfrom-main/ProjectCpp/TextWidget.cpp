#include "TextWidget.h"

TextWidget::TextWidget(string text, float size, float r[2]) : text(text), size(size) {
	this->r[0] = r[0];
	this->r[1] = r[1];
}

void TextWidget::do_draw() {
	graphics::drawText(r[0], r[1], size, text, brush);
}
