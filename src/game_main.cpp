
#import "game_main.h"
 





Level_status Game_main::run()
{

		lives = starting_lives;
		score = starting_score;


	
		// Draw title screen
		tb_clear();
	
		Box border(0, 0, full_width, full_height, 1, '#', TB_DEFAULT, TB_DEFAULT);
		border.draw();
				

		draw_string(20, 1, 10, "Lives: " + std::to_string(lives), TB_DEFAULT, TB_DEFAULT);
		draw_string(50, 1, 10, "Score: " + std::to_string(score), TB_DEFAULT, TB_DEFAULT);
	

	
		for(int i = 0; i < 13; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				int x = (i * 6) + 1;
				int y = (j * 2) + 3;
			
				Box block(x, y, 6, 2, '%', TB_DEFAULT, TB_DEFAULT);
			
	
				block.replace_char(0, 0, '|', TB_DEFAULT, TB_DEFAULT);	
				block.replace_char(0, 1, '|', TB_DEFAULT, TB_DEFAULT);
				block.replace_char(5, 1, '|', TB_DEFAULT, TB_DEFAULT);
				block.replace_char(5, 0, '|', TB_DEFAULT, TB_DEFAULT);
                 
				block.replace_char(1, 0, '"', TB_DEFAULT, TB_DEFAULT);
				block.replace_char(2, 0, '"', TB_DEFAULT, TB_DEFAULT);
				block.replace_char(3, 0, '"', TB_DEFAULT, TB_DEFAULT);
				block.replace_char(4, 0, '"', TB_DEFAULT, TB_DEFAULT);
                 
				block.replace_char(1, 1, '_', TB_DEFAULT, TB_DEFAULT);
				block.replace_char(2, 1, '_', TB_DEFAULT, TB_DEFAULT);
				block.replace_char(3, 1, '_', TB_DEFAULT, TB_DEFAULT);
				block.replace_char(4, 1, '_', TB_DEFAULT, TB_DEFAULT);
	
				block.draw();
			}
		}

	
		
		
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
	

	
	
		// Title screen event loop
	
		while(true)
		{	
			int status = tb_peek_event(&ev, peek_time);
		
			if(status > 0 && ev.type == TB_EVENT_KEY) 
			{
				if(ev.key == TB_KEY_SPACE) 
					break; 
				else if(ev.key == TB_KEY_ESC)
					quit();
			}	

			sleep(tick);
		}

		
		
		
		
		// Level 1
		Level_a_1 level_a_1(lives, 1, score);
		status = level_a_1.run();
		if(status == WON)
		{
			lives = level_a_1.get_lives();
			score = level_a_1.get_score();
		}
		else
		{
			return status;
		}
		
		
		
		
		
		
		// Level 2
		Level_a_2 level_a_2(lives, 2, score);
		status = level_a_2.run();
		if(status == WON)
		{
			lives = level_a_2.get_lives();
			score = level_a_2.get_score();
		}
		else
		{
			return status;
		}
		
		
		
		
		
		// Level 3
		Level_a_3 level_a_3(lives, 3, score);
		status = level_a_3.run();
		if(status == WON)
		{
			lives = level_a_3.get_lives();
			score = level_a_3.get_score();
		}
		else
		{
			return status;
		}
	
	
	
	
		tb_clear();
	
		border.draw();
	
		// End screen
		Window end_win(Window::CENTER, 4, 40, 10, 1, 3, '*', TB_DEFAULT, TB_DEFAULT,  ' ', TB_DEFAULT, TB_DEFAULT);
		
		end_win.add_string(Window::CENTER, 2, "The End!", 20, 0, TB_DEFAULT | TB_BOLD, TB_DEFAULT);
		end_win.add_string(Window::CENTER, 4, "That's all there is so far,", 80, 0, TB_DEFAULT, TB_DEFAULT);
		end_win.add_string(Window::CENTER, 5, "but there's more to come soon!", 80, 0, TB_DEFAULT, TB_DEFAULT);
		end_win.add_string(Window::CENTER, 7, "Esc to quit", 80, 0, TB_DEFAULT, TB_DEFAULT);
		
		end_win.draw_window();
	
		tb_present();
		

		
		while(true)
		{
			int status = tb_peek_event(&ev, peek_time);
			
			if(status > 0 && ev.type == TB_EVENT_KEY)
			{
				if(ev.key == TB_KEY_ESC)
					quit();
			}
			sleep(tick);
		}
	
};






