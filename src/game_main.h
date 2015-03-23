#include <string>

#include "termbox.h"

#include "constants.h"
#include "draw_string.h"
#include "utility.h"
#include "window.h"

#include "level_a_1.h"
#include "level_a_2.h"
#include "level_a_3.h"

class Game_main
{
private:
	tb_event ev;
	
	int lives;
	int score;
	
	Level_status status;
	
public:
	Level_status run();
		
};