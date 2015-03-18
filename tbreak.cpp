#include <iostream>
#include <time.h>

#include "termbox.h"

#include "box.h"
#include "draw_string.h"

const unsigned int tick = 75; // Delay between event loop cycles
const int peek_time = 20; // Time waiting for event per cycle
 
const int full_width = 80;
const int full_height = 24; 




 
 
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
	
	
	Box border(0, 0, full_width, full_height, 1, '#', TB_DEFAULT, TB_DEFAULT);
	border.draw();
	

	
	draw_string(30, 5, 40, "Terminal Breakout", TB_DEFAULT | TB_BOLD, TB_DEFAULT);
	draw_string(28, 7, 40, "Elliot.Lockerman.info", TB_DEFAULT, TB_DEFAULT);
	draw_string(34, 12, 40, "Controls", TB_DEFAULT | TB_BOLD, TB_DEFAULT);
	draw_string(25, 13, 40, "Space: Start/Launch new ball", TB_DEFAULT, TB_DEFAULT);
	draw_string(24, 14, 40, "Left/Right Arrows: Move paddle", TB_DEFAULT, TB_DEFAULT);
	draw_string(34, 15, 40, "ESC: Quit", TB_DEFAULT, TB_DEFAULT);

	
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