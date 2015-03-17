#include <iostream>
#include <time.h>
#include <string>

#include "termbox.h"


const unsigned int tick = 75; // Delay between event loop cycles
const int peek_time = 20; // Time waiting for event per cycle
 
 




 
void draw_string(int x, int y, int width, std::string str, uint16_t fg, uint16_t bg)
{
	// TODO: Bounds checking
	// TODO: Try to break between words
	
	for(int i = 0; i < str.length(); i++)
	{
		tb_change_cell(x + (i % width), y + (i / width), (uint32_t)str[i], fg, bg);
	}
	tb_present();
}





 
class Box
{
private:
	int x, y, width, height, thickness;
	tb_cell cell;

public:
	Box(int x, int y, int width, int height, int thickness, uint32_t ch, uint16_t fg, uint16_t bg);
	
	void draw();
	bool contains_point(int x, int y);

};


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




 
 
void sleep(unsigned int miliseconds)
{
	unsigned int micro = 1000 * miliseconds;
    clock_t goal = micro + clock();
    while (clock() < goal);
}







int main()
{
	// Initialize
	int init_status = tb_init();
	if(init_status != 0)
	{ 
		std::cerr << "tb_init() failed with error code " << init_status << std::endl; 
		return 1;
	}
	

	//draw_string(3, 5, 20, "THIS IS A TEST STRING, TEST STRING, TEST STRING", TB_DEFAULT, TB_DEFAULT);
	
	
	tb_clear();
	std::auto_ptr<Box> border(new Box(0, 0, tb_width(), tb_height(), 1, '#', TB_DEFAULT, TB_DEFAULT));
	border->draw();
	tb_present();
	
	
	// Event loop
	while(true)
	{
		
		
		
		
		struct tb_event ev;
		int status = tb_peek_event(&ev, peek_time);
		
		if(status > 0)
		{
			switch (ev.type) 
			{
			case TB_EVENT_KEY:
				switch (ev.key) 
				{
					case TB_KEY_ESC:
						goto quit;
						break;
				}
				break;
			}
		}
		sleep(tick);
	}
	
	
	
quit:
	tb_shutdown();
	
	return 0;
 	
}