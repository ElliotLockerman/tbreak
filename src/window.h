#include <string>

#include "termbox.h"

#include "box.h"
#include "constants.h"

#pragma once



/*
 * A (optionally aligned) box that can contain (optionally aligned) text
 *
 */



class Window : public Box
{
private:
    

    struct text
    {
        std::string str;
        
        int rel_x; // Relative to window
        int rel_y; // Relative to window
        
        int colwidth;// Will wrap if wider than (dumb: will split words, etc)
        
        uint16_t fg;
        uint16_t bg;
    };
    
    std::list<text> texts;
    
public:
    enum alignment // An alternative to manually setting x-position
    {
        CENTER,
        LEFT
    };
    


    // Manually positioned window constructor
    Window(int x, int y, int width, int height, int border_thickness, 
        uint32_t bch, uint16_t bfg, uint16_t bbg, 
        uint32_t cch, uint16_t cfg, uint16_t cbg) :
        Box(x, y, width, height, border_thickness, bch, bfg, bbg, cch, cfg, cbg)
        {
            assert(x > 0);
            assert(y > 0);
            assert(x + width <= game_width);
            assert(y + height <= game_height);
        }
    
    // Automatically positioned window constructor
    // Left padding only matters if alignment is LEFT
    Window(alignment align, int y, int width, int height, int border_thickness, 
        int left_padding, uint32_t bch, uint16_t bfg, uint16_t bbg, 
        uint32_t cch, uint16_t cfg, uint16_t cbg) :
        Box(0, y, width, height, border_thickness, bch, bfg, bbg, cch, cfg, cbg)
        {
            assert(y + height <= game_height);
            
            int x = 0;
            if(align == CENTER)
            {
                x = (game_width - width) / 2;
            }
            else if(align == LEFT)
            {
                x = 0 + left_padding;
            }
            move_to(x, y);
        }
    
    
    
    // y is relative to window, left_padding only matters if alignment is LEFT
    // Colwidth only matters if less than string length
    void add_string( alignment align, int rel_y, std::string str, int colwidth, 
        int left_padding, uint16_t fg, uint16_t bg);
    
    // x, y are relative to window
    void add_string(int rel_x, int rel_y, std::string str, int colwidth, 
        uint16_t fg, uint16_t bg);
    
    // Draws window and all text
    void draw_window();
    
    // Deletes all text
    void clear_text();
};

