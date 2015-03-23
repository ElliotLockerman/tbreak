#include "level_a_2.h"

Level_a_2::Level_a_2(int lives, int score)
{
	this->lives = lives;
	this->score = score;
	
	ball_in_play = false;
	level_status = OUT_OF_LIVES; // Just so its not uninitialized
	
	
	border.reset(new Box(0, 0, full_width, full_height, 1, '#', TB_DEFAULT, TB_DEFAULT));
	paddle.reset(new Paddle(32, 20, 13, 1, '=', TB_DEFAULT, TB_DEFAULT));
	ball.reset(new Ball(3, 22, 1, -1, 'o', TB_DEFAULT, TB_DEFAULT));

	
		
	// Draw blocks
	for(int i = 0; i < 13; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			int x = (i * 6) + 1;
			int y = (j * 2) + 3;
		
			Box* block = new Box(x, y, 6, 2, '%', TB_DEFAULT, TB_DEFAULT);

			blocks.push_back(std::shared_ptr<Box>(block));
		}
	}
		
}
