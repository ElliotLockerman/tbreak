#include <string>

#include "termbox.h"

#include "draw_string.h"

void draw_string(int x, int y, int colwidth, std::string str, 
    uint16_t fg, uint16_t bg)
{
    // TODO: Try to break between words
    assert(x >= 0);
    assert(y >= 0);
    assert(colwidth > 0);
    assert(x < game_width);
    assert(y < game_height);
    
    if(x + colwidth > tb_width()) colwidth = tb_width() - x;

    
    for(int i = 0; i < static_cast<int>(str.length()); i++)
    {   
        // Bounds checking, mainly for running off the bottom
        if(x + (i % colwidth) < tb_width() && y + (i / colwidth) < tb_height())
        {
            tb_change_cell(x + (i % colwidth), y + (i / colwidth),
                (uint32_t)str[i], fg, bg);
        }
    }
    
}

