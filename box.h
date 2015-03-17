#include "drawable.h"

/*
A box drawn to the terminal, consisting of a single character ch.
x, y are the upper left corner
Extra lines for thicknesses greater than 1 are placed on the *inside* of the width and height, replacing any center
For information on ch, fg and bg, see termbox.h
*/

class Box: public Drawable
{
private:
	int width, height, border_thickness;
	tb_cell border, center;
	bool has_border, has_center;
	
	vector<vector<char_wrapper*>> mat;
	
	struct char_wrapper
	{
		int x;
		int y;
		tb_cell cell;
		
		bool removed;
	}
	// Constructors' helpers
	void prepare_border();
	void prepare_center();
	

public:
	// Border only
	//Box(int x, int y, int width, int height, int border_thickness, uint32_t bch, uint16_t bfg, uint16_t bbg);
	Box(int x, int y, int width, int height, int border_thickness, tb_cell border);
	
	// Center only
	//Box(int x, int y, int width, int height, uint32_t cch, uint16_t cfg, uint16_t cbg);
	Box(int x, int y, int width, int height, tb_cell center);
	
	// Both border and center
	//Box(int x, int y, int width, int height, int border_thickness, uint32_t bch, uint16_t bfg, uint16_t bbg, uint32_t cch, uint16_t cfg, uint16_t cbg);
	//Box(int x, int y, int width, int height, int border_thickness, tb_cell border,  tb_cell center);
	
	
	
	// Replaces the char at the given location with the arguments.
	//void replace_char(int x, int y, uint32_t ch, uint16_t fg, uint16_t bg);
	void replace_char(int x, int y, tb_cell cell);	
	void remove_char(int x, int y);
	
	
	// Drawable implementations. See drawable.h
	using Drawable::draw;
	virtual void draw ();
	
	using Drawable::contains_point;
	virtual bool contains_point(int x, int y);
	
	using Drawable::move_to;
	virtual bool move_to(int x, int y);
};
