#include <iostream>

#include "utility.h"

void sleep(unsigned int miliseconds)
{
	unsigned int micro = 1000 * miliseconds;
    clock_t goal = micro + clock();
    while (clock() < goal);
}








bool pause_window()
{
	Window pause_win(Window::CENTER, 4, 26, 7, 1, 0, '*', TB_DEFAULT, TB_DEFAULT,  ' ', TB_DEFAULT, TB_DEFAULT);
    
	pause_win.add_string(Window::CENTER, 2, "Paused", 20, 0, TB_DEFAULT | TB_BOLD, TB_DEFAULT);
	pause_win.add_string(Window::CENTER, 4, "Press p to unpause", 20, 0, TB_DEFAULT, TB_DEFAULT);
	
    tb_event ev;
	while(true)
	{
						
		pause_win.draw_window();
		tb_present();


		int status = tb_poll_event(&ev);
		if(status > 0 && ev.type == TB_EVENT_KEY)
		{
			if(ev.ch == 'p')
				return false;
			if(ev.key == TB_KEY_ESC)
			{
				if(quit_window())return true;
			}
			
		}
	}
}



bool quit_window()
{
	Window quit_win(Window::CENTER, 4, 26, 7, 1, 0, '*', TB_DEFAULT, TB_DEFAULT,  ' ', TB_DEFAULT, TB_DEFAULT);
	quit_win.add_string(Window::CENTER, 2, "Quit?", 20, 0, TB_DEFAULT | TB_BOLD, TB_DEFAULT);
	quit_win.add_string(Window::CENTER, 4, "y/n", 20, 0, TB_DEFAULT, TB_DEFAULT);
	
    tb_event ev;
	while(true)
	{		
		quit_win.draw_window();
		tb_present();

		int status = tb_poll_event(&ev);
		if(status > 0 && ev.type == TB_EVENT_KEY)
		{
			if(ev.ch == 'n')
				return false;
			if(ev.ch == 'y')
				return true;
		}
	}
}