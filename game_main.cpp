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
	
	Box blocks(1, 3, 78, 6, '=', TB_DEFAULT, TB_DEFAULT);
	blocks.draw();

	Box title_background(21, 4, 38, 15, 1, '*', TB_DEFAULT, TB_DEFAULT, ' ', TB_DEFAULT, TB_DEFAULT);
	title_background.draw();
	
	draw_string(32, 6, 40, "Terminal Breakout", TB_DEFAULT | TB_BOLD, TB_DEFAULT);
	draw_string(30, 8, 40, "Elliot.Lockerman.info", TB_DEFAULT, TB_DEFAULT);
	
	draw_string(36, 12, 40, "Controls", TB_DEFAULT | TB_BOLD, TB_DEFAULT);
	draw_string(26, 13, 40, "Space: Start/Launch new ball", TB_DEFAULT, TB_DEFAULT);
	draw_string(25, 14, 40, "Left/Right Arrows: Move paddle", TB_DEFAULT, TB_DEFAULT);
	draw_string(35, 15, 40, "ESC: Quit", TB_DEFAULT, TB_DEFAULT);

	
	
	
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
	
	// Game event loop	
	while(true)
	{	
		
		tb_clear();
		
		border.draw();
		blocks.draw();
		paddle.draw();
		
		tb_present();
		
		
		
		
		
		int status = tb_peek_event(&ev, peek_time);
		
		if(status > 0 && ev.type == TB_EVENT_KEY) 
		{
			if(ev.key == TB_KEY_ARROW_LEFT)
			{
				if(!is_collision(paddle.get_x() - 1, paddle.get_y()))
					paddle.move_left();
			}
			else if(ev.key == TB_KEY_ARROW_RIGHT)
			{
				if(!is_collision(paddle.get_x() + paddle.get_width(), paddle.get_y()))
					paddle.move_right();
			}
			else if(ev.key == TB_KEY_ESC)
			{
				return 0; // Quits
			}
		}	

		sleep(tick);
	}
	
};

bool Game_main::is_collision(int x, int y)
{
	
	if(border->contains_point(x, y))
		return true;
	
	
	
	return false;
}