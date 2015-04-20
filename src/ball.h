#include "termbox.h"

#include "drawable.h"


#pragma once


/*
 * The Ball
 */


class Ball : public Drawable
{
private:
	
	tb_cell cell;
	
public:
	// Distance moved in each direction each time move() is called. 
	int dy, dx;
	
	Ball(unsigned int x, unsigned int y, int dx, int dy, uint32_t ch, uint16_t fg, uint16_t bg);
	
	// Moves the ball by one dx and one dy
	void move();
	
	
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
};