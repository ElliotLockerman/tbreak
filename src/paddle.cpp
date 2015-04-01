#include "paddle.h"

void Paddle::draw()
{
	Box::draw();
	
	if(ball)
		tb_put_cell(x + (width / 2), y, &ball_cell);
}


int Paddle::ball_x()
{
	return x + (width / 2);
}

void Paddle::move_right(int dx)
{
	// TODO: Add collion detection
	move_to(this->x += dx, y);
}

void Paddle::move_left(int dx)
{
	// TODO: Add collion detection
	move_to(this->x -= dx, y);
}