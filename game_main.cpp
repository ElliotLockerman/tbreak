#import <iostream>

#import "game_main.h"

 
void Game_main::sleep(unsigned int miliseconds)
{
	unsigned int micro = 1000 * miliseconds;
    clock_t goal = micro + clock();
    while (clock() < goal);
}




int Game_main::run()
{
	
	
	// Draw title screen
	tb_clear();
	
	
	Box border(0, 0, full_width, full_height, 1, '#', TB_DEFAULT, TB_DEFAULT);
	this->border = &border;
	border.draw();
	
	lives = 3;
	score = 0;
	
	draw_string(20, 1, 10, "Lives: " + std::to_string(lives), TB_DEFAULT, TB_DEFAULT);
	draw_string(50, 1, 10, "Score: " + std::to_string(score), TB_DEFAULT, TB_DEFAULT);
	
	
	
	
	
	for(int i = 0; i < 13; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			int x = (i * 6) + 1;
			int y = (j * 2) + 3;
			
			Box* block = new Box(x, y, 6, 2, '%', TB_DEFAULT, TB_DEFAULT);
			
	
			block->replace_char(0, 0, '|', TB_DEFAULT, TB_DEFAULT);	
			block->replace_char(0, 1, '|', TB_DEFAULT, TB_DEFAULT);
			block->replace_char(5, 1, '|', TB_DEFAULT, TB_DEFAULT);
			block->replace_char(5, 0, '|', TB_DEFAULT, TB_DEFAULT);
                 
			block->replace_char(1, 0, '"', TB_DEFAULT, TB_DEFAULT);
			block->replace_char(2, 0, '"', TB_DEFAULT, TB_DEFAULT);
			block->replace_char(3, 0, '"', TB_DEFAULT, TB_DEFAULT);
			block->replace_char(4, 0, '"', TB_DEFAULT, TB_DEFAULT);
                 
			block->replace_char(1, 1, '_', TB_DEFAULT, TB_DEFAULT);
			block->replace_char(2, 1, '_', TB_DEFAULT, TB_DEFAULT);
			block->replace_char(3, 1, '_', TB_DEFAULT, TB_DEFAULT);
			block->replace_char(4, 1, '_', TB_DEFAULT, TB_DEFAULT);
	
			blocks.push_back(block);
		}
	}

	for(blocks_it = blocks.begin(); blocks_it != blocks.end(); blocks_it++)
	{
		(*blocks_it)->draw();
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
				return 0; // Quits
		}	

		sleep(tick);
	}
	
	
	
	
	




	// Prepare game
	Paddle paddle(33, 20, 13, 1, '=', TB_DEFAULT, TB_DEFAULT);
	this->paddle = &paddle;
	
	Ball ball(3, 22, 1, -1, 'o', TB_DEFAULT, TB_DEFAULT);
	this->ball = &ball;
	
	// Game event loop	
	while(true)
	{	
		
		tb_clear();
		
		border.draw();
		
		draw_string(20, 1, 10, "Lives: " + std::to_string(lives), TB_DEFAULT, TB_DEFAULT);
		draw_string(50, 1, 15, "Score: " + std::to_string(score), TB_DEFAULT, TB_DEFAULT);
		
		paddle.draw();
		border.draw();
		
		for(blocks_it = blocks.begin(); blocks_it != blocks.end(); blocks_it++)
		{
			(*blocks_it)->draw();
		}
		
		ball.draw();
		
		tb_present();
		
		
		
		
		
		int status = tb_peek_event(&ev, peek_time);
		
		if(status > 0 && ev.type == TB_EVENT_KEY) 
		{
			if(ev.key == TB_KEY_ARROW_LEFT)
			{
				// Check if we can move two (prefered), one or zero spaces
				bool left_collide_1 = will_collide(&paddle, paddle.get_x() - 1, paddle.get_y(), false);
				bool left_collide_2 = will_collide(&paddle, paddle.get_x() - 2, paddle.get_y(), false);
			
				
				if(!(left_collide_1 || left_collide_2))
					paddle.move_left(2);
				else if(!left_collide_1)
					paddle.move_left(1);
			}
			else if(ev.key == TB_KEY_ARROW_RIGHT)
			{
				// Check if we can move two (prefered), one or zero spaces
				bool right_collide_1 = will_collide(&paddle, paddle.get_x() + paddle.get_width(), paddle.get_y(), false);
				bool right_collide_2 = will_collide(&paddle, paddle.get_x() + paddle.get_width() + 1, paddle.get_y(), false);
				
				if(!(right_collide_1 || right_collide_2))
					paddle.move_right(2);
				else if(!right_collide_1)
					paddle.move_right(1);
			}
			if(ev.ch == 'p')
			{
				while(true)
				{
					
					Box title_background(27, 4, 26, 7, 1, '*', TB_DEFAULT, TB_DEFAULT, ' ', TB_DEFAULT, TB_DEFAULT);
					title_background.draw();
					
					draw_string(37, 6, 40, "Paused", TB_DEFAULT | TB_BOLD, TB_DEFAULT);
					
					tb_present();
					
					
					int status = tb_poll_event(&ev);
					if(status > 0 && ev.type == TB_EVENT_KEY)
					{
						if(ev.ch == 'p')
							break;
						if(ev.key == TB_KEY_ESC)
							return 0;
					}
				}
				
			}
			else if(ev.key == TB_KEY_ESC)
			{
				while(true)
				{
					
					Box title_background(27, 4, 26, 7, 1, '*', TB_DEFAULT, TB_DEFAULT, ' ', TB_DEFAULT, TB_DEFAULT);
					title_background.draw();
					
					draw_string(35, 6, 40, "Quit? (y/n)", TB_DEFAULT | TB_BOLD, TB_DEFAULT);
					
					tb_present();
					
					
					int status = tb_poll_event(&ev);
					if(status > 0 && ev.type == TB_EVENT_KEY)
					{
						if(ev.ch == 'n')
							break;
						if(ev.ch == 'y')
							return 0;
					}
				}
			}
		}


		// Ball collsion
		// First find out if it will collide at all
		if(will_collide(&ball, ball.get_x() + ball.dx, ball.get_y() + ball.dy, false))
		{
			bool hor_wall = false;
			bool ver_wall = false;
			
			//Then figure out what the angle is
			// Check if its a horizontal wall, above or below
			if(will_collide(&ball, ball.get_x(), ball.get_y() + ball.dy, false))
				hor_wall = true;
			
			// next, a ver wall, left or right
			if(will_collide(&ball, ball.get_x() + ball.dx, ball.get_y(), false))
				ver_wall = true;
			
			// If its a wall, delete it
			will_collide(&ball, ball.get_x() + ball.dx, ball.get_y() + ball.dy, true);
			
			
			// if its a corner (inside or outside), reverse both
			if((hor_wall && ver_wall) || (!hor_wall && !ver_wall))
			{
				ball.dx *= -1;
				ball.dy *= -1;
			}
			else if(hor_wall) // A horizontal wall (ball moving up or down to), reverse dy
			{
				ball.dy *= -1;
			}
			else if(ver_wall) // A ver wall (ball moving left or right to), reverse dy
			{
				ball.dx *= -1;
			}
			
		
		}
		ball.move(); // Does not re-draw untill top of next loop


		sleep(tick);
	}
	
};

bool Game_main::will_collide(Drawable* object, int x, int y, bool and_delete)
{
	if(object != paddle && paddle->contains_point(x, y))
		return true;
	
	if(object != ball && ball->contains_point(x, y))
		return true;
	
	
	if(border->contains_point(x, y))
		return true;
	
	
	for(blocks_it = blocks.begin(); blocks_it != blocks.end(); blocks_it++)
	{
		if((*blocks_it)->contains_point(x,y))
		{
			if(and_delete)
			{
				score += 10;
				blocks.remove(*blocks_it);
			}
			return true;
		}
	}
	
	return false;
};