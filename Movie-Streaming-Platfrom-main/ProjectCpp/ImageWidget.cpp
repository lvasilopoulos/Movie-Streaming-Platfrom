#include "ImageWidget.h"

/// <summary>
/// Creates an image widget
/// </summary>
/// <param name="texture">the tecture</param>
/// <param name="r">location</param>
/// <param name="s">size</param>
ImageWidget::ImageWidget(string texture, float r[2], float s[2]) : texture(texture) {
	this->r[0] = r[0];
	this->r[1] = r[1];
	this->s[0] = s[0];
	this->s[1] = s[1];

	this->top_left[0] = r[0] - s[0] / 2.0f;
	this->top_left[1] = r[1] - s[1] / 2.0f;

	this->bottom_right[0] = r[0] + s[0] / 2.0f;
	this->bottom_right[1] = r[1] + s[1] / 2.0f;	
}

/// <summary>
/// Draws the image
/// </summary>
void ImageWidget::do_draw() {	
	brush.texture = texture;
	graphics::drawRect(r[0], r[1], s[0], s[1], brush);
}
