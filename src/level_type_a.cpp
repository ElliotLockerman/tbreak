#include "level_type_a.h"



Level_status Level_type_a::run()
{
	Window pause_win(Window::CENTER, 4, 26, 7, 1, 0, '*', TB_DEFAULT, TB_DEFAULT,  ' ', TB_DEFAULT, TB_DEFAULT);
	
	pause_win.add_string(Window::CENTER, 2, "Paused", 20, 0, TB_DEFAULT | TB_BOLD, TB_DEFAULT);
	pause_win.add_string(Window::CENTER, 4, "Press p to unpause", 20, 0, TB_DEFAULT, TB_DEFAULT);
	
	
	
	Window quit_win(Window::CENTER, 4, 26, 7, 1, 0, '*', TB_DEFAULT, TB_DEFAULT,  ' ', TB_DEFAULT, TB_DEFAULT);
	quit_win.add_string(Window::CENTER, 2, "Quit?", 20, 0, TB_DEFAULT | TB_BOLD, TB_DEFAULT);
	quit_win.add_string(Window::CENTER, 4, "y/n", 20, 0, TB_DEFAULT, TB_DEFAULT);
	
	

	// Game event loop	
	while(true)
	{	

		tb_clear();

		border->draw();

		draw_string(20, 1, 10, "Lives: " + std::to_string(lives), TB_DEFAULT, TB_DEFAULT);
		draw_string(35, 1, 10, "Level: " + std::to_string(level), TB_DEFAULT, TB_DEFAULT);
		draw_string(50, 1, 15, "Score: " + std::to_string(score), TB_DEFAULT, TB_DEFAULT);

		paddle->draw();
		border->draw();

		for(blocks_it = blocks.begin(); blocks_it != blocks.end(); blocks_it++)
			(*blocks_it)->draw();
	

		if(ball_in_play)
			ball->draw();

		tb_present();





		int status = tb_peek_event(&ev, peek_time);

		if(status > 0 && ev.type == TB_EVENT_KEY) 
		{
			// Launch ball
			if(ev.key == TB_KEY_SPACE)
			{
				if(!ball_in_play)
				{
					srand (time(NULL));
					int ran = rand() % 100;
			
					int dx;
					if(ran > 50)
						dx = 1;
					if(ran <= 50)
						dx = -1;
								
					ball->dx = dx;
					ball->dy = -1;
				
					paddle->ball = false;
					ball_in_play = true;
					ball->move_to(paddle->ball_x(), paddle->get_y());
				}
		
			}
			// Move paddle left
			else if(ev.key == TB_KEY_ARROW_LEFT)
			{
				// Check if we can move two (prefered), one or zero spaces
				bool left_collide_1 = will_collide(paddle, paddle->get_x() - 1, paddle->get_y());
				bool left_collide_2 = will_collide(paddle, paddle->get_x() - 2, paddle->get_y());
	
		
				if(!(left_collide_1 || left_collide_2))
					paddle->move_left(2);
				else if(!left_collide_1)
					paddle->move_left(1);
			}
			// Move paddle right
			else if(ev.key == TB_KEY_ARROW_RIGHT)
			{
				// Check if we can move two (prefered), one or zero spaces
				bool right_collide_1 = will_collide(paddle, paddle->get_x() + paddle->get_width(), paddle->get_y());
				bool right_collide_2 = will_collide(paddle, paddle->get_x() + paddle->get_width() + 1, paddle->get_y());
		
				if(!(right_collide_1 || right_collide_2))
					paddle->move_right(2);
				else if(!right_collide_1)
					paddle->move_right(1);
			}
			// Pause
			if(ev.ch == 'p')
			{
				while(true)
				{
									
					pause_win.draw_window();
					tb_present();
			
			
					int status = tb_poll_event(&ev);
					if(status > 0 && ev.type == TB_EVENT_KEY)
					{
						if(ev.ch == 'p')
							break;
						if(ev.key == TB_KEY_ESC)
						{
							while(true)
							{		
								quit_win.draw_window();
								tb_present();
			
								int status = tb_poll_event(&ev);
								if(status > 0 && ev.type == TB_EVENT_KEY)
								{
									if(ev.ch == 'n')
										break;
									if(ev.ch == 'y')
										quit();
								}
							}
						}
						
					}
				}
		
			}
			// Quit
			else if(ev.key == TB_KEY_ESC)
			{
				while(true)
				{
					
					quit_win.draw_window();
					tb_present();
				
					int status = tb_poll_event(&ev);
					if(status > 0 && ev.type == TB_EVENT_KEY)
					{
						if(ev.ch == 'n')
							break;
						if(ev.ch == 'y')
							quit();
					}
				}
			}
		}


		// Ball collsion
		bool hor_wall = false;
		bool ver_wall = false;

		// Check if its a horizontal wall, above or below
		if(will_collide(ball, ball->get_x(), ball->get_y() + ball->dy))
			hor_wall = true;
	
		// next, a ver wall, left or right
		if(will_collide(ball, ball->get_x() + ball->dx, ball->get_y()))
			ver_wall = true;
	
		// A colission is one directly forwards or both hor and ver
		if(will_collide(ball, ball->get_x() + ball->dx, ball->get_y() + ball->dy) || (ver_wall && hor_wall))
		{
			// Delete all hit blocks, also incriments score
			delete_hit();
	
		
			// if its a corner (inside or outside), reverse both
			if((hor_wall && ver_wall) || (!hor_wall && !ver_wall))
			{
				ball->dx *= -1;
				ball->dy *= -1;
			}
			else if(hor_wall) // A horizontal wall (ball moving up or down to), reverse dy
			{
				ball->dy *= -1;
			}
			else if(ver_wall) // A ver wall (ball moving left or right to), reverse dy
			{
				ball->dx *= -1;
			}
		}
		else
			{
				// If case there wasn't a collision, clear the hit blocks
				hit_blocks.clear();
			}
	
		// Now check if it will hit the bottom
		if(ball_in_play && ball->get_y() == 22)
		{
			paddle->ball = true;
			ball_in_play = false;
			lives--;
			if(lives == 0)	
			{
				level_status = OUT_OF_LIVES;
				break;
			}
		}




		if(ball_in_play)
			ball->move(); // Does not re-draw untill top of next loop


		// Check if the game was won
		if(blocks.size() == 0)
		{
			level_status = WON;
			break;
		}

		sleep(tick);
	}







	// Ending screen

	Window end(Window::CENTER, 4, 40, 8, 1, 3, '*', TB_DEFAULT, TB_DEFAULT,  ' ', TB_DEFAULT, TB_DEFAULT);
	/*
	Box title_background(22, 5, 37, 8, 1, '*', TB_DEFAULT, TB_DEFAULT, ' ', TB_DEFAULT, TB_DEFAULT);
	title_background.draw();*/

	if(level_status == WON)
	{	
		end.add_string(Window::CENTER, 2, "You Won!", 40, 0, TB_DEFAULT | TB_BOLD, TB_DEFAULT);
		end.add_string(Window::CENTER, 4, "Press space to play next level", 40, 0, TB_DEFAULT, TB_DEFAULT);
		/*draw_string(36, 7, 40, "You Won!", TB_DEFAULT | TB_BOLD, TB_DEFAULT);
		draw_string(25, 10, 40, "Press space to play next level", TB_DEFAULT, TB_DEFAULT);*/
	}
	else
	{
		end.add_string(Window::CENTER, 2, "Game Over", 40, 0, TB_DEFAULT | TB_BOLD, TB_DEFAULT);
		end.add_string(Window::CENTER, 4, "Press space to return to title", 40, 0, TB_DEFAULT, TB_DEFAULT);
		/*draw_string(36, 7, 40, "Game Over", TB_DEFAULT | TB_BOLD, TB_DEFAULT);
		draw_string(28, 10, 40, "Press space to play again", TB_DEFAULT, TB_DEFAULT);*/
	}
	//draw_string(34, 8, 40, std::to_string(score) + " points", TB_DEFAULT, TB_DEFAULT);


	// Ending screen event loop

	while(true)
	{	
		tb_clear();
		
		draw_string(20, 1, 10, "Lives: " + std::to_string(lives), TB_DEFAULT, TB_DEFAULT);
		draw_string(35, 1, 10, "Level: " + std::to_string(level), TB_DEFAULT, TB_DEFAULT);
		draw_string(50, 1, 15, "Score: " + std::to_string(score), TB_DEFAULT, TB_DEFAULT);
		
		paddle->draw();
		border->draw();

		for(blocks_it = blocks.begin(); blocks_it != blocks.end(); blocks_it++)
			(*blocks_it)->draw();


		end.draw_window();
		
		tb_present();
		
		
		
		int status = tb_peek_event(&ev, peek_time);

		if(status > 0 && ev.type == TB_EVENT_KEY) 
		{
			if(ev.key == TB_KEY_SPACE)
				return level_status;	
			// Quit
			while(true)
			{

				quit_win.draw_window();
				tb_present();
		
		
				int status = tb_poll_event(&ev);
				if(status > 0 && ev.type == TB_EVENT_KEY)
				{
					if(ev.ch == 'n')
						break;
					if(ev.ch == 'y')
						quit();
				}
			}		
		}	

	}

};


bool Level_type_a::will_collide(std::shared_ptr<Drawable> object, int x, int y)
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
			hit_blocks.insert(*blocks_it);
			
			return true;
		}
	}
	
	return false;
};




void Level_type_a::delete_hit()
{
	for(hit_it = hit_blocks.begin(); hit_it != hit_blocks.end(); hit_it++)
	{
		score += score_per_block;	
		blocks.remove(*hit_it);		
	}
	hit_blocks.clear();
};

int Level_type_a::get_lives(){return lives;};

int Level_type_a::get_score(){return score;};