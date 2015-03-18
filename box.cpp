#include "termbox.h"

#include "box.h"


// ********************************************************
// Constructors 

// Border only, discrete arguments
Box::Box(int x, int y, int width, int height, int border_thickness, uint32_t ch, uint16_t fg, uint16_t bg)
{
	// TODO: Bounds checking
	
	has_border = true;
	has_center = false;
	
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->border_thickness = border_thickness;
	
	this->border_cell.ch = ch;
	this->border_cell.fg = fg;
	this->border_cell.bg = bg;

}


// Center only, discrete arguments
Box::Box(int x, int y, int width, int height, uint32_t cch, uint16_t cfg, uint16_t cbg)
{
	// TODO: Bounds checking
	
	has_border = false;
	has_center = true;
	
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	
	this->center_cell.ch = cch;
	this->center_cell.fg = cfg;
	this->center_cell.bg = cbg;
}



// Border and center, discrete arguments
Box::Box(int x, int y, int width, int height, int border_thickness, uint32_t cch, uint16_t cfg, uint16_t cbg, uint32_t bch, uint16_t bfg, uint16_t bbg)
{
	// TODO: Bounds checking
	
	has_border = true;
	has_center = true;
	
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->border_thickness = border_thickness;
	
	this->center_cell.ch = cch;
	this->center_cell.fg = cfg;
	this->center_cell.bg = cbg;
	
	
	this->border_cell.ch = bch;
	this->border_cell.fg = bfg;
	this->border_cell.bg = bbg;
}

// ********************************************************


void Box::draw()
{
	// Draw center
	if(has_center)
	{
	for(int i = 0; i < width; i++)
		for(int j = 0; j < height; j++)
			tb_put_cell(x + i, y + j, &center_cell);
	}
	
	
	// Draw borders
	if(has_border)
	{
		//Top border
		for(int i = 0; i < width; i++)
			for(int j = 0; j < border_thickness; j++)
				tb_put_cell(x + i, y + j, &border_cell);
		

		//Bottom border
		for(int i = 0; i < width; i++)
			for(int j = 0; j < border_thickness; j++)
				tb_put_cell(x + i, y + height - 1 - j, &border_cell);
			

		// Left border
		for(int i = 0; i < height; i++)
			for(int j = 0; j < border_thickness; j++)	
				tb_put_cell(x + j, y + i, &border_cell);
					

		//Right border
		for(int i = 0; i < height; i++)
			for(int j = 0; j < border_thickness; j++)
				tb_put_cell(x + width - 1 - j, y + i, &border_cell);
	}
		
}




bool Box::contains_point(int x, int y)
{
	return false;
}




void Box::move_to(int x, int y)
{
	this->x = x;
	this->y = y;
	
	return;
}