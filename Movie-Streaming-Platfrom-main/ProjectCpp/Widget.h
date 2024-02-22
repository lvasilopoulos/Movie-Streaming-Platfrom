#pragma once

/// <summary>
/// The base widget. Contains location (r), size (s), upper left and lower right box coordinates 
/// (used to detect mouse clicks) and whether widget is visible, it reacts to hover or click events
/// The draw and update method do the necessary checks and then call the do_draw(), do_update)(
/// and do_click() methods that are to be overidden by the children
/// </summary>
class Widget {
public:
	float r[2] = { 50.0f, 50.0f};    // x,y
	float s[2] = { 10, 10 }; // width,height	
	float top_left[2] = { 0, 0 };
	float bottom_right[2] = { 0 ,0 };
	bool visible = true;
	bool enable_hover = false;
	bool enable_click = false;
	bool hover = false;	

	virtual void draw(float mx, float my);
	virtual void update(float mx, float my, float ms);

	virtual void do_draw() = 0;
	virtual void do_update(float ms);
	virtual void do_click(float mx, float my);
};


