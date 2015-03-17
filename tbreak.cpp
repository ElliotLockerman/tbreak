#include <iostream>
#include <time.h>
#include <string>

#include "termbox.h"

#include "box.h"

const unsigned int tick = 75; // Delay between event loop cycles
const int peek_time = 20; // Time waiting for event per cycle
 
const int console_width = 80;
const int console_height = 24; 




/* 
Draws a string str starting at x, y. If longer than max_width, it wraps to the next line (without regard for word breaks, etc)
For information on fg and bg, see termbox.h
*/
void draw_string(int x, int y, int max_width, std::string str, uint16_t fg, uint16_t bg)
{
	// TODO: Bounds checking
	// TODO: Try to break between words
	// TODO: Option to center text
	
	for(int i = 0; i < str.length(); i++)
	{
		tb_change_cell(x + (i % max_width), y + (i / max_width), (uint32_t)str[i], fg, bg);
	}
	
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
	
	
	
	tb_clear();
	draw_string(30, 5, 40, "Terminal Breakout", TB_DEFAULT | TB_BOLD, TB_DEFAULT);
	draw_string(28, 7, 40, "Elliot.Lockerman.info", TB_DEFAULT, TB_DEFAULT);
	draw_string(34, 12, 40, "Controls", TB_DEFAULT | TB_BOLD, TB_DEFAULT);
	draw_string(25, 13, 40, "Space: Start/Launch new ball", TB_DEFAULT, TB_DEFAULT);
	draw_string(24, 14, 40, "Left/Right Arrows: Move paddle", TB_DEFAULT, TB_DEFAULT);
	draw_string(34, 15, 40, "ESC: Quit", TB_DEFAULT, TB_DEFAULT);
	
	
	
	
	Box border(0, 0, console_width, console_height, 1, '#', TB_DEFAULT, TB_DEFAULT);
	border.draw();
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