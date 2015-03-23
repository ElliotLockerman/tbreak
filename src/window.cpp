#include "window.h"


void Window::add_string(int rel_y, std::string str, alignment align, int colwidth, int left_padding, uint16_t fg, uint16_t bg)
{
	int rel_x = 0;
	if(align == CENTER)
	{
		rel_x = ((width - (2 * border_thickness)) - str.length()) / 2;
	}
	else if(align == LEFT)
	{
		rel_x = border_thickness + left_padding;
	}
	
	add_string(rel_x, rel_y, str, colwidth, fg, bg);
}


void Window::add_string(int rel_x, int rel_y, std::string str, int colwidth, uint16_t fg, uint16_t bg)
{
	text new_text =
	{
		.str = str,
		.rel_x = x,
		.rel_y = y,
		.colwidth = colwidth,
		.fg = fg,
		.bg = bg
	};
	
	texts.push_back(new_text);
}

void Window::draw_window()
{
	draw(); // Calls Box's draw for the background
	
	for(std::list<text>::iterator it = texts.begin(); it != texts.end(); it++)
	{
		for(int i = 0; i < it->str.length(); i++)
		{
			tb_change_cell(it->rel_x + x + (i % it->colwidth), y + it->rel_y + (i / it->colwidth), (uint32_t)it->str[i], it->fg, it->bg);
		}
	}
}