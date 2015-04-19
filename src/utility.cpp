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
	
	while(true)
	{
						
		pause_win.draw_window();
		tb_present();


		if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
			return false;
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			if(quit_window())return true;
		}
		
		
	}
}



bool quit_window()
{
	Window quit_win(Window::CENTER, 4, 26, 7, 1, 0, '*', TB_DEFAULT, TB_DEFAULT,  ' ', TB_DEFAULT, TB_DEFAULT);
	quit_win.add_string(Window::CENTER, 2, "Quit?", 20, 0, TB_DEFAULT | TB_BOLD, TB_DEFAULT);
	quit_win.add_string(Window::CENTER, 4, "y/n", 20, 0, TB_DEFAULT, TB_DEFAULT);
	
	while(true)
	{		
		quit_win.draw_window();
		tb_present();
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::N))
			return false;
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
			return true;
	
	}
}