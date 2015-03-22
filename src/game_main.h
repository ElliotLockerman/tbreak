#include <string>
#include <list>
#include <set>

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
	
	static const int peek_time = 20; // Time waiting for event per cycle
 
	static const int full_width = 80;
	static const int full_height = 24; 
	
	int lives;
	int score;
	
	bool ball_in_play;
	bool game_status; // True for no more blocks (i.e. perfect game), false for out of lives
	
	std::list<std::shared_ptr<Box> > blocks;
	std::list<std::shared_ptr<Box> >::iterator blocks_it;
	
	std::set<std::shared_ptr<Box> > hit_blocks;
	std::set<std::shared_ptr<Box> >::iterator hit_it;
		
	Box* border;
	Paddle* paddle;
	Ball* ball;
	
		
	bool will_collide(Drawable *object, int x, int y);
	
	// Deletes all hit_blocks
	void delete_hit();
	
public:
	int run();
		
};