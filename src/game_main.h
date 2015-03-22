#include <string>

#include "termbox.h"

#include "constants.h"
#include "draw_string.h"
#include "utility.h"

#include "level_1.h"

class Game_main
{
private:
	tb_event ev;
	
	int lives;
	int score;
	
	Level_status status;
	
public:
	void run();
		
};