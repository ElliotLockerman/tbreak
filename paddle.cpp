#import "paddle.h"

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