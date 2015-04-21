#include "ball.h"


Ball::Ball(int x, int y, int dx, int dy, uint32_t ch, uint16_t fg, uint16_t bg)
{
	assert(x >= 0);
	assert(y >= 0);
	assert(x < game_width);
	assert(y < game_height);
	
	this->x = x;
	this->y = y;
	
	this->dx = dx;
	this->dy = dy;
	
	this->cell.ch = ch;
	this->cell.fg = fg;
	this->cell.bg = bg;
}

void Ball::move()
{
	assert(x + dx < game_width);
	assert(y + dy < game_height);
	
	x += dx;
	y += dy;
}


// Drawables

void Ball::draw()
{
	tb_put_cell(x, y, &cell);
}

bool Ball::contains_point(int x, int y)
{
	if(x == this->x && y == this->y)
		return true;
	
	return false;
}

void Ball::move_to(int x, int y)
{
	assert(x >= 0);
	assert(y >= 0);
	assert(x < game_width);
	assert(y < game_height);
	
	this->x = x;
	this->y = y;
}

int Ball::get_x(){return x;}

int Ball::get_y(){return y;}
	
// End Drawables;