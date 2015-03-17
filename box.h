#include "drawable.h"

class Box: public Drawable
{
private:
	int x, y, width, height, thickness;
	tb_cell cell;

public:
	Box(int x, int y, int width, int height, int thickness, uint32_t ch, uint16_t fg, uint16_t bg);
	
	using Drawable::draw;
	virtual void draw ();
	
	using Drawable::contains_point;
	virtual bool contains_point(int x, int y);
};
