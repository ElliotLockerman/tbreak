#import "ball.h"


Ball::Ball(int x, int y, int dx, int dy, uint32_t ch, uint16_t fg, uint16_t bg)
{
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
	if(this->x == x && this->y == y)
		return true;
	
	return false;
}

void Ball::move_to(int x, int y)
{
	this->x = x;
	this->y = y;
}

int Ball::get_x(){return x;}

int Ball::get_y(){return y;}
	
// End Drawables;