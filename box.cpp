#include "termbox.h"

#include "box.h"


Box::Box(int x, int y, int width, int height, int thickness, uint32_t ch, uint16_t fg, uint16_t bg)
{
	// TODO: Bounds checking
	
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->thickness = thickness;
	this->cell = cell;
	
	this->cell.ch = ch;
	this->cell.fg = fg;
	this->cell.bg = bg;
	
}


void Box::draw()
{

	//Top border
	for(int i = 0; i < width; i++)
		for(int j = 0; j < thickness; j++)			
			tb_put_cell(x + i, y + j, &cell);
		

	//Bottom border
	for(int i = 0; i < width; i++)
		for(int j = 0; j < thickness; j++)
			tb_put_cell(x + i, y + height - 1 - j, &cell);


	// Left border
	for(int i = 0; i < height; i++)
		for(int j = 0; j < thickness; j++)			
			tb_put_cell(x + j, y + i, &cell);


	//Right border
	for(int i = 0; i < height; i++)
		for(int j = 0; j < thickness; j++)
			tb_put_cell(x + width - 1 - j, y + i, &cell);
	
	tb_present();
}


bool Box::contains_point(int x, int y)
{
	return false;
}