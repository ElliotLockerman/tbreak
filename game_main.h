#include <time.h>
#include <string>
#include <list>

#include "termbox.h"

#include "box.h"
#include "draw_string.h"
#include "paddle.h"
#include "ball.h"
#include "drawable.h"


class Game_main
{
private:
	tb_event ev;
	
	static const unsigned int tick = 75; // Delay between event loop cycles
	static const int peek_time = 20; // Time waiting for event per cycle
 
	static const int full_width = 80;
	static const int full_height = 24; 
	
	std::list<Drawable*> blocks;
	std::list<Drawable*>::iterator blocks_it;
	
	Box* border;
	Paddle* paddle;
	Ball* ball;
	
	
	void sleep(unsigned int miliseconds);
	
	bool will_collide(Drawable *object, int x, int y);
	
public:
	int run();
		
};