#include <string>

#include "termbox.h"


void draw_string(int x, int y, int colwidth, std::string str, uint16_t fg, uint16_t bg)
{
	// TODO: Bounds checking
	// TODO: Try to break between words
	
	for(unsigned int i = 0; i < str.length(); i++)
	{
		tb_change_cell(x + (i % colwidth), y + (i / colwidth), (uint32_t)str[i], fg, bg);
	}
	
}

