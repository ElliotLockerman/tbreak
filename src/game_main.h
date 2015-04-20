#include <string>
#include <vector>

#include "termbox.h"
#include "../external/jsoncpp/json/json.h"
#include <SFML/Window/Keyboard.hpp>

#include "constants.h"
#include "draw_string.h"
#include "utility.h"
#include "window.h"

#include "level.h"
#include "level_type_block_grid.h"


/*
 * The main game class
 * Displays the home screen, initializes and runs the levels, displays ending screens
 *
 */

class Game_main
{
private:
	int starting_lives;
	std::vector<Level::generic_level_config> levels;
	Level_status level_status;
		
	bool new_game();
	
    bool after_level_window();
    
public:
	Game_main(int starting_lives, std::vector<Level::generic_level_config> levels)
	{
		this->starting_lives = starting_lives;
		this->levels = levels;
	}
	void run();
		
};