#include <vector>
#include <string>
#include <list>
#include <iostream>
#include <cassert>

#include "termbox.h"

#include "drawable.h"


#pragma once

/*
 * A box
 * Can have a center, border, or both
 * x, y are the upper left corner
 * Extra lines for thicknesses greater than 1 are placed on the *inside* of the width and height, replacing any center
 * Character provided in constructor is default, but can be replaced or removed with replace_char(), replace_string(), remove_char();
 * For information on ch, fg and bg, see termbox.h
 */

class Box: public Drawable
{
private:
	
	// The basic unit - one character on the screen, if !empty
	struct char_wrap
	{
		tb_cell cell;	
		bool empty; 
	} empty_wrap, border_wrap, center_wrap;
	
	// Matrix representing the box; is directly drawn to buffer
	// Outer is column/width (x), inner is row/height (y)
	std::vector<std::vector<char_wrap> > matrix; 

	// ALl the constructers feed in to this after dealing with their arguments
	void initialize_matrix(bool has_border, bool has_center);


protected:
	// Protected for subclassing
	unsigned int width, height, border_thickness;
	

public:
	// Border only
	Box(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned int border_thickness, uint32_t bch, uint16_t bfg, uint16_t bbg);

	
	// Center only
	Box(unsigned int x, unsigned int y, unsigned int width, unsigned int height, uint32_t cch, uint16_t cfg, uint16_t cbg);
	
	// Both border and center
	Box(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned int border_thickness, uint32_t bch, uint16_t bfg, uint16_t bbg, uint32_t cch, uint16_t cfg, uint16_t cbg);


	
	
	// Replaces the char at the given location with the arguments.
	// X and Y are relative
	// Cannot be placed outside of box's bounds
	void replace_char(unsigned int x, unsigned int y, uint32_t ch, uint16_t fg, uint16_t bg);
	
	// Same as char but for an entire string, with wrapping behavior similar to draw_string()
	// X and Y are relative
	// Cannot be placed outside of box's bounds
	void replace_string(unsigned int x, unsigned int y, unsigned int colwidth, std::string str, uint16_t fg, uint16_t bg);
	
	// Remove a char. Will no longer be collidable and will not overwrite buffer
	// X and Y are relative
	void remove_char(unsigned int x, unsigned int y);
	
	
	
	
	// Drawable implementations. See drawable.h
	using Drawable::draw;
	virtual void draw();
	
	// X and Y are absolute
	using Drawable::contains_point;
	virtual bool contains_point(unsigned int x, unsigned int y);
	
	// X and Y are absolute
	using Drawable::move_to;
	virtual void move_to(unsigned int x, unsigned int y);
	
	
	using Drawable::get_x;
	virtual int get_x();
	
	using Drawable::get_y;
	virtual int get_y();
	
	int get_width(){return width;}
	int get_height(){return height;}
	
};
