#include <string>

#include "termbox.h"

#include "constants.h"
#include "draw_string.h"
#include "utility.h"
#include "window.h"

#include "level_a_1.h"
#include "level_a_2.h"
#include "level_a_3.h"

/*
 * The main game class
 * Displays the home screen, initializes and runs the levels, displays ending screens
 *
 */

class Game_main
{
private:
	tb_event ev;
	
	Level_status level_status;

	
	void new_game();
	
    void after_level_window();
    
public:
	void run();
		
};