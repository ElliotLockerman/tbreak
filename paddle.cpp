#import "paddle.h"

void Paddle::move_right()
{
	// TODO: Add collion detection
	move_to(++x, y);
}

void Paddle::move_left()
{
	// TODO: Add collion detection
	move_to(--x, y);
}