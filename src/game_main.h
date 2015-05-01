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
#include "level_type_block_freeform.h"
#include "constants.h"


/*
 * The main game class
 * Displays the home screen, initializes and runs the levels, 
 * displays ending screens
 *
 */

class Game_main
{
private:
    int points_for_life;
    
    std::vector<Json::Value> levels;
    Level_status level_status;
        
    bool new_game();
    
    bool after_level_window();
    
public:
    Game_main(int points_for_life, int starting_lives, std::vector<Json::Value> levels)
    {
        this->points_for_life = points_for_life;
        
        this->level_status.lives = starting_lives;
        this->level_status.score = 0;
        this->level_status.result = OUT_OF_LIVES;
        
        this->levels = levels;
    }
    
    Game_main(const Game_main&) = delete;
    
    void run();
        
};