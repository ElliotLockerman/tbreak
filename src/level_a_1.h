#include <string>

#include "termbox.h"

#include "level_type_a.h"
#include "draw_string.h"
#include "window.h"


#pragma once


class Level_a_1 : public Level_type_a
{
private:

	
	
public:	
	Level_a_1(int lives, int level, int score) : 
        Level_type_a::Level_type_a(lives, level, score)
    {
    	// Draw blocks
    	for(int i = 0; i < 13; i++)
    	{
    		for(int j = 0; j < 4; j++)
    		{
    			int x = (i * 6) + 1;
    			int y = (j * 2) + 3;
		
    			Box* block = new Box(x, y, 6, 2, '%', TB_DEFAULT, TB_DEFAULT);
		

    			block->replace_char(0, 0, '|', TB_DEFAULT, TB_DEFAULT);	
    			block->replace_char(0, 1, '|', TB_DEFAULT, TB_DEFAULT);
    			block->replace_char(5, 1, '|', TB_DEFAULT, TB_DEFAULT);
    			block->replace_char(5, 0, '|', TB_DEFAULT, TB_DEFAULT);
             
    			block->replace_char(1, 0, '"', TB_DEFAULT, TB_DEFAULT);
    			block->replace_char(2, 0, '"', TB_DEFAULT, TB_DEFAULT);
    			block->replace_char(3, 0, '"', TB_DEFAULT, TB_DEFAULT);
    			block->replace_char(4, 0, '"', TB_DEFAULT, TB_DEFAULT);
             
    			block->replace_char(1, 1, '_', TB_DEFAULT, TB_DEFAULT);
    			block->replace_char(2, 1, '_', TB_DEFAULT, TB_DEFAULT);
    			block->replace_char(3, 1, '_', TB_DEFAULT, TB_DEFAULT);
    			block->replace_char(4, 1, '_', TB_DEFAULT, TB_DEFAULT);

    			blocks.push_back(std::shared_ptr<Box>(block));
    		}
    	}
    }

};