
#import "game_main.h"
 





void Game_main::run()
{
	
	
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

	


		Box title_background(19, 4, 41, 17, 1, '*', TB_DEFAULT, TB_DEFAULT, ' ', TB_DEFAULT, TB_DEFAULT);
		title_background.draw();
	
		draw_string(32, 6, 40, "Terminal Breakout", TB_DEFAULT | TB_BOLD, TB_DEFAULT);
		draw_string(30, 8, 40, "Elliot.Lockerman.info", TB_DEFAULT, TB_DEFAULT);
	
		draw_string(36, 12, 40, "Controls", TB_DEFAULT | TB_BOLD, TB_DEFAULT);
		draw_string(26, 13, 40, "Space: Start/Launch new ball", TB_DEFAULT, TB_DEFAULT);
		draw_string(25, 14, 40, "Left/Right Arrows: Move paddle", TB_DEFAULT, TB_DEFAULT);

		draw_string(35, 16, 40, "p: Pause", TB_DEFAULT, TB_DEFAULT);
		draw_string(35, 17, 40, "ESC: Quit", TB_DEFAULT, TB_DEFAULT);

	
	
	
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
					return; // Quits
			}	

			sleep(tick);
		}
	
	
		lives = starting_lives;
		score = starting_score;
		
		// There's only 1 level so far, so loop level 1;
		while(true)
		{
			Level_1 level_1(lives, score);
			status = level_1.run();
			if(status == WON)
			{
				lives = level_1.get_lives();
				score = level_1.get_score();
			}
			else
			{
				lives = starting_lives;
				score = starting_score;
			}
		}
	
	
};






