#include <string>
#include <memory>

#include "termbox.h"

#include "level_type_a.h"
#include "draw_string.h"
#include "window.h"


#pragma once


class Level_a_1 : public Level_type_a
{
private:

	
	
public:	
	Level_a_1(std::string name, int lives, int score) : 
        Level_type_a::Level_type_a(name, lives, score)
    {
		
		for(int i = 0; i < 13; i++) // < 13
		{
			for(int j = 0; j < 4; j++) // < 4
			{
				int x = (i * 6) + 1;
				int y = (j * 2) + 3;
		
    			Box* block = new Box(x, y, 6, 2, '%', TB_DEFAULT, TB_DEFAULT);
		
				block->replace_string(0, 0, 6, "|\"\"\"\"||____|", TB_DEFAULT, TB_DEFAULT);

    			blocks.push_back(std::shared_ptr<Box>(block));
				
			}
		}
		
    }

};