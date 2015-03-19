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
	
	Ball ball(3, 22, 1, -1, 'o', TB_DEFAULT, TB_DEFAULT);
	this->ball = &ball;
	
	// Game event loop	
	while(true)
	{	
		
		tb_clear();
		
		border.draw();
		paddle.draw();
		
		ball.draw();
		
		tb_present();
		
		
		
		
		
		int status = tb_peek_event(&ev, peek_time);
		
		if(status > 0 && ev.type == TB_EVENT_KEY) 
		{
			if(ev.key == TB_KEY_ARROW_LEFT)
			{
				if(!will_collide(&paddle, paddle.get_x() - 1, paddle.get_y()))
					paddle.move_left();
			}
			else if(ev.key == TB_KEY_ARROW_RIGHT)
			{
				if(!will_collide(&paddle, paddle.get_x() + paddle.get_width(), paddle.get_y()))
					paddle.move_right();
			}
			else if(ev.key == TB_KEY_ESC)
			{
				return 0; // Quits
			}
		}


		// Ball collsion
		// First find out if it will collide at all
		if(will_collide(&ball, ball.get_x() + ball.dx, ball.get_y() + ball.dy))
		{
			bool hor_wall = false;
			bool ver_wall = false;
			
			//Then figure out what the angle is
			// Check if its a horizontal wall, above or below
			if(will_collide(&ball, ball.get_x(), ball.get_y() + ball.dy))
				hor_wall = true;
			
			// next, a ver wall
			if(will_collide(&ball, ball.get_x() + ball.dx, ball.get_y()))
				ver_wall = true;
			
			
			// if its a corner (inside or outside), reverse both
			if(hor_wall && ver_wall)
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
		ball.move();


		sleep(tick);
	}
	
};

bool Game_main::will_collide(Drawable* object, int x, int y)
{
	
	if(object != border && border->contains_point(x, y))
		return true;
	
	if(object != paddle && paddle->contains_point(x, y))
		return true;
	
	if(object != ball && ball->contains_point(x, y))
		return true;
	
	return false;
};