
#include "game_main.h"
 

bool Game_main::new_game()
{
    Box border(0, 0, full_width, full_height, 1, '#', TB_DEFAULT, TB_DEFAULT);

	this->level_status.lives = starting_lives;
	this->level_status.score = 0;
	this->level_status.result = OUT_OF_LIVES;


	for(unsigned int i = 0; i < levels.size(); i++)
	{		
		if(levels[i].type == "block_grid")
		{
			
			
			Level_type_block_grid level(level_status.lives, level_status.score, levels[i]);
			level_status = level.run();
			
			if(level_status.result == QUIT)
			{
				return true;
			}
			if(i < levels.size() - 1 && after_level_window()) return true;
			if(level_status.result == OUT_OF_LIVES)
			{
				return false;
			}
			
		}
			
	}
	





	// Draw end of game screen
	tb_clear();

	border.draw();

	// End screen
	Window end_win(Window::CENTER, 4, 40, 10, 1, 3, '*', TB_DEFAULT, TB_DEFAULT,  ' ', TB_DEFAULT, TB_DEFAULT);
	
	end_win.add_string(Window::CENTER, 2, "You Won!", 20, 0, TB_DEFAULT | TB_BOLD, TB_DEFAULT);
	end_win.add_string(Window::CENTER, 3, "The End!", 20, 0, TB_DEFAULT | TB_BOLD, TB_DEFAULT);
	end_win.add_string(Window::CENTER, 5, "That's all there is so far,", 80, 0, TB_DEFAULT, TB_DEFAULT);
	end_win.add_string(Window::CENTER, 6, "but there's more to come soon!", 80, 0, TB_DEFAULT, TB_DEFAULT);
	end_win.add_string(Window::CENTER, 8, "Space to return to start", 80, 0, TB_DEFAULT, TB_DEFAULT);
	
	end_win.draw_window();

	tb_present();
	

	// End of game event loop
	while(true)
	{		
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			return false;
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			if(quit_window()) return true;
		
		sleep(tick);
	}
}





bool Game_main::after_level_window()
{
	Window end(Window::CENTER, 4, 40, 8, 1, 3, '*', TB_DEFAULT, TB_DEFAULT,  ' ', TB_DEFAULT, TB_DEFAULT);


	if(level_status.result == WON)
	{	
		end.add_string(Window::CENTER, 2, "You Won!", 40, 0, TB_DEFAULT | TB_BOLD, TB_DEFAULT);
		end.add_string(Window::CENTER, 4, "Press space to play next level", 40, 0, TB_DEFAULT, TB_DEFAULT);
	}
	else
	{
		end.add_string(Window::CENTER, 2, "Game Over", 40, 0, TB_DEFAULT | TB_BOLD, TB_DEFAULT);
		end.add_string(Window::CENTER, 4, "Press space to return to title", 40, 0, TB_DEFAULT, TB_DEFAULT);
	}



	// Ending screen event loop
	while(true)
	{	
		
		end.draw_window();
		tb_present();
		
	
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			return false;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			if(quit_window()) return true;	
		}

		sleep(tick);

	}
}



void Game_main::run()
{
	while(true)
	{
	
		// Draw title screen
		tb_clear();

		Box border(0, 0, full_width, full_height, 1, '#', TB_DEFAULT, TB_DEFAULT);
		border.draw();
			
		
		
		if(levels[0].type == "block_grid")
		{
			for(int i = 0; i < levels[0].number_of_rows; i++) // < 13
			{
				for(int j = 0; j < levels[0].number_of_columns; j++) // < 4
				{
					int x = (j * (levels[0].block_width + levels[0].left_padding)) + levels[0].starting_x;
					int y = (i * (levels[0].block_height + levels[0].top_padding)) + levels[0].starting_y;
	
					Box block(x, y, levels[0].block_width, levels[0].block_height, levels[0].block_default_char, TB_DEFAULT, TB_DEFAULT);
	
					block.replace_string(0, 0, levels[0].block_width, levels[0].block_string, TB_DEFAULT, TB_DEFAULT);

					block.draw();
				
			
				}
			}
		}
		
		
		


	
		// Title screen instructions
		Window intro(Window::CENTER, 4, 40, 16, 1, 3, '*', TB_DEFAULT, TB_DEFAULT,  ' ', TB_DEFAULT, TB_DEFAULT);
	
		intro.add_string(Window::CENTER, 2, "Terminal Breakout", 40, 0, TB_DEFAULT | TB_BOLD, TB_DEFAULT);
		intro.add_string(Window::CENTER, 4, "Elliot.Lockerman.info", 40, 0, TB_DEFAULT, TB_DEFAULT);
		intro.add_string(Window::CENTER, 8, "Controls", 40, 0, TB_DEFAULT | TB_BOLD, TB_DEFAULT);
		intro.add_string(Window::CENTER, 9, "Space: Start/Launch new ball", 40, 0, TB_DEFAULT, TB_DEFAULT);
		intro.add_string(Window::CENTER, 10, "Left/Right Arrows: Move paddle", 40, 0, TB_DEFAULT, TB_DEFAULT);
		intro.add_string(Window::CENTER, 11, "p: Pause", 40, 0, TB_DEFAULT, TB_DEFAULT);
		intro.add_string(Window::CENTER, 12, "ESC: Quit", 40, 0, TB_DEFAULT, TB_DEFAULT);
		
		intro.draw_window();


		tb_present();



		bool space_been_released = false;
		while(true)
		{	
			if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				space_been_released = true;
			}
	
			if(space_been_released
				&& sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) 
			{	
				space_been_released = false;
				if(new_game()) return;
				break;
			}
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				return;
			}
				

			sleep(tick);
		}
	
	
	
	};
};
