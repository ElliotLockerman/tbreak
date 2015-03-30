#include <string>

#include "termbox.h"

#include "level.h"
#include "draw_string.h"
#include "window.h"


#pragma once

class Level_type_a : public Level
{
private:
	
protected:
	using Level::will_collide;
	virtual bool will_collide(std::shared_ptr<Drawable> object, int x, int y);
	
	using Level::delete_hit;
	virtual void delete_hit();
	
		
	
	
	
public:	
	Level_type_a(int lives, int level, int score)
    {
    	this->lives = lives;
    	this->level = level;
    	this->score = score;
	
    	ball_in_play = false;
    	level_status = OUT_OF_LIVES; // Just so its not uninitialized
	
	
    	border.reset(new Box(0, 0, full_width, full_height, 1, '#', TB_DEFAULT, TB_DEFAULT));
    	paddle.reset(new Paddle(32, 20, 13, 1, '=', TB_DEFAULT, TB_DEFAULT));
    	ball.reset(new Ball(3, 22, 1, -1, 'o', TB_DEFAULT, TB_DEFAULT));
    }
    
	using Level::run;
	virtual Level_status run(); 
	
	using Level::get_lives;
	virtual int get_lives();
	
	using Level::get_score;
	virtual int get_score();
	
	
};