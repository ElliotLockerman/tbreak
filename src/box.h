#include <vector>
#include <string>
#include <list>

#include "drawable.h"


#pragma once

/*
A box drawn to the terminal, consisting of a single character ch.
x, y are the upper left corner
Extra lines for thicknesses greater than 1 are placed on the *inside* of the width and height, replacing any center
For information on ch, fg and bg, see termbox.h
*/

class Box: public Drawable
{
private:
	
	struct char_wrap
	{
		tb_cell cell;	
		bool empty; 
	} empty_wrap, border_wrap, center_wrap;
	
	
	 // Outer is column/width (x), inner is row/height (y)
	std::vector<std::vector<char_wrap> > matrix; 

	void initialize_matrix();


protected:
	int width, height, border_thickness;
	

public:
	// Border only
	Box(int x, int y, int width, int height, int border_thickness, uint32_t bch, uint16_t bfg, uint16_t bbg);

	
	// Center only
	Box(int x, int y, int width, int height, uint32_t cch, uint16_t cfg, uint16_t cbg);
	
	// Both border and center
	Box(int x, int y, int width, int height, int border_thickness, uint32_t bch, uint16_t bfg, uint16_t bbg, uint32_t cch, uint16_t cfg, uint16_t cbg);


	
	
	// Replaces the char at the given location with the arguments.
	// X and Y are relative
	void replace_char(int x, int y, uint32_t ch, uint16_t fg, uint16_t bg);
	
	// Same as char but for an entire string, with behavior similar to draw_string()
	// X and Y are relative
	void replace_string(int x, int y, int colwidth, std::string str, uint16_t fg, uint16_t bg);
	
	// Remove a char. Will no longer be collidable and will not overwrite previous chars
	// X and Y are relative
	void remove_char(int x, int y);
	
	
	
	
	// Drawable implementations. See drawable.h
	using Drawable::draw;
	virtual void draw();
	
	// X and Y are absolute
	using Drawable::contains_point;
	virtual bool contains_point(int x, int y);
	
	// X and Y are absolute
	using Drawable::move_to;
	virtual void move_to(int x, int y);
	
	
	using Drawable::get_x;
	virtual int get_x();
	
	using Drawable::get_y;
	virtual int get_y();
	
	int get_width(){return width;}
	int get_height(){return height;}
	
};
