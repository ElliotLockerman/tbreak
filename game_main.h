#include <time.h>
#include <string>

#include "termbox.h"

#include "box.h"
#include "draw_string.h"
#include "paddle.h"



class Game_main
{
private:
	static const unsigned int tick = 75; // Delay between event loop cycles
	static const int peek_time = 20; // Time waiting for event per cycle
 
	static const int full_width = 80;
	static const int full_height = 24; 

	tb_event ev;
	
	void quit();
	void sleep(unsigned int miliseconds);
	
public:
	
	int run();
	
	
};