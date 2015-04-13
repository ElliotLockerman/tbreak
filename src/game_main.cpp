
#include "game_main.h"
 

bool Game_main::new_game()
{
    Box border(0, 0, full_width, full_height, 1, '#', TB_DEFAULT, TB_DEFAULT);

	this->level_status.lives = level_root["starting_lives"].asInt();
	this->level_status.score = 0;
	this->level_status.result = OUT_OF_LIVES;


	Json::Value levels = level_root["levels"];

	
	for(unsigned int i = 0; i < levels.size(); i++)
	{
		if(levels[i]["type"].asString() == "block_grid")
		{
			Level_type_block_grid::block_grid_config config = 
			{
				.lives              = level_status.lives,
				.score              = level_status.score,
				
				.name               = levels[i]["name"].asString(),
				
				.block_width        = levels[i]["block_width"].asInt(),
				.block_height       = levels[i]["block_height"].asInt(),
				.block_default_char = levels[i]["block_default_char"].asString()[0],
				.block_string       = levels[i]["block_string"].asString(),
					
					
				.number_of_columns  = levels[i]["number_of_columns"].asInt(),
				.number_of_rows     = levels[i]["number_of_rows"].asInt(),
				.points_per_block   = levels[i]["points_per_block"].asInt(),

				.starting_x         = levels[i]["starting_x"].asInt(),
				.starting_y         = levels[i]["starting_y"].asInt(),
				.top_padding        = levels[i]["top_padding"].asInt(),
				.left_padding       = levels[i]["left_padding"].asInt()
			};
			
			
			Level_type_block_grid level(config);
			level_status = level.run();
			
			if(level_status.result == QUIT)
			{
				return true;
			}
			if(i < levels.size() - 1) return after_level_window();
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
		int status = tb_peek_event(&ev, peek_time);
		
		if(status > 0 && ev.type == TB_EVENT_KEY)
		{   
            if(ev.key == TB_KEY_SPACE)
				return false;
			if(ev.key == TB_KEY_ESC)
				if(quit_window()) return true;
		}
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
		
		int status = tb_peek_event(&ev, peek_time);
		if(status > 0 && ev.type == TB_EVENT_KEY) 
		{
			if(ev.key == TB_KEY_SPACE)
				return false;	
			if(ev.key == TB_KEY_ESC)
				if(quit_window()) return true;	
		}	

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
			
		
		
		
		for(int i = 0; i < level_root["levels"][0]["number_of_rows"].asInt(); i++) // < 13
		{
			for(int j = 0; j < level_root["levels"][0]["number_of_columns"].asInt(); j++) // < 4
			{
				int x = (j * (level_root["levels"][0]["block_width"].asInt() + level_root["levels"][0]["left_padding"].asInt())) + level_root["levels"][0]["starting_x"].asInt();
				int y = (i * (level_root["levels"][0]["block_height"].asInt() + level_root["levels"][0]["top_padding"].asInt())) + level_root["levels"][0]["starting_y"].asInt();
	
				Box block(x, y, level_root["levels"][0]["block_width"].asInt(), level_root["levels"][0]["block_height"].asInt(), level_root["levels"][0]["block_default_char"].asString()[0], TB_DEFAULT, TB_DEFAULT);
	
				block.replace_string(0, 0, level_root["levels"][0]["block_width"].asInt(), level_root["levels"][0]["block_string"].asString(), TB_DEFAULT, TB_DEFAULT);

				block.draw();
				
			
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




		while(true)
		{	
			int level_status = tb_peek_event(&ev, peek_time);
	
			if(level_status > 0 && ev.type == TB_EVENT_KEY) 
			{
				if(ev.key == TB_KEY_SPACE) 
				{	
					if(new_game()) return;
					break;
				}
				else if(ev.key == TB_KEY_ESC)
					return;
			}	

			sleep(tick);
		}
	
	
	
	};
};
