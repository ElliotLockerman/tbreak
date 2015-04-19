#include <string>

#include "termbox.h"
#include "../external/jsoncpp/json/json.h"
#include <SFML/Window/Keyboard.hpp>

#include "constants.h"
#include "draw_string.h"
#include "utility.h"
#include "window.h"

#include "level_type_block_grid.h"


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

	Json::Value level_root;
	
	bool new_game();
	
    bool after_level_window();
    
public:
	Game_main(Json::Value level_root)
	{
		this->level_root = level_root;
	}
	void run();
		
};