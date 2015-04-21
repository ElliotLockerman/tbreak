#include "window.h"



void Window::add_string(alignment align, int rel_y, std::string str, 
	int colwidth, int left_padding, uint16_t fg, uint16_t bg)
{
	int rel_x = 0;
	if(align == CENTER)
	{
		if(static_cast<int>(str.length()) < colwidth) 
		{
			colwidth = str.length();
		}
		
		rel_x = (width - colwidth) / 2;
	}
	else if(align == LEFT)
	{
		rel_x = left_padding;
	}
	
	add_string(rel_x, rel_y, str, colwidth, fg, bg);
}



void Window::add_string(int rel_x, int rel_y, std::string str, int colwidth, 
	uint16_t fg, uint16_t bg)
{
	text new_text =
	{
		.str = str,
		.rel_x = rel_x,
		.rel_y = rel_y,
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
		for(int i = 0; i < static_cast<int>(it->str.length()); i++)
		{			
			tb_change_cell(x + it->rel_x + (i % it->colwidth), 
				y + it->rel_y + (i / it->colwidth), 
				(uint32_t)it->str[i], it->fg, it->bg);
		}
		
	}
}

void Window::clear_text()
{
	texts.clear();
}