#include "drawable.h"

/*
A box drawn to the terminal, consisting of a single character ch.
x, y are the upper left corner
Extra lines for thicknesses greater than 1 are placed on the *inside* of the width and height. A thickness of <= 0 will result in nothing being drawn
For information on ch, fg and bg, see termbox.h
*/

class Box: public Drawable
{
private:
	int x, y, width, height, thickness;
	tb_cell cell;

public:
	Box(int x, int y, int width, int height, int thickness, uint32_t ch, uint16_t fg, uint16_t bg);
	
	
	
	
	// See drawable.h
	using Drawable::draw;
	virtual void draw ();
	
	using Drawable::contains_point;
	virtual bool contains_point(int x, int y);
};
