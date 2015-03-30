#include <string>

#include "termbox.h"

#include "level_type_a.h"
#include "draw_string.h"
#include "window.h"

#pragma once


class Level_a_3 : public Level_type_a
{
private:

	
	
public:	
	Level_a_3(int lives, int level, int score) :
        Level_type_a(lives, level, score)
    {
    	// Draw blocks
    	for(int i = 0; i < 11; i++)
    	{
    		for(int j = 0; j < 3; j++)
    		{
    			int x = (i * 7) + 2;
    			int y = (j * 3) + 3;
		
    			Box* block = new Box(x, y, 6, 2, '%', TB_DEFAULT, TB_DEFAULT);

    			blocks.push_back(std::shared_ptr<Box>(block));
    		}
    	}
    }

};