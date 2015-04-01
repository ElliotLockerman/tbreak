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
	
	Level_status level_status;
	
    void after_level_window();
    
public:
	Level_status run();
		
};