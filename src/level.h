#include <list>
#include <set>
#include <cstdlib>
#include <string>
#include <memory>

#include "constants.h"
#include "utility.h"
#include "box.h"
#include "paddle.h"
#include "ball.h"
#include "drawable.h"

#pragma once


/*
 * Abstract class for all levels
 *
 */


enum Level_result{OUT_OF_LIVES, WON, QUIT};

struct Level_status
{
	int lives;
	int score;
	Level_result result;
};



class Level
{
private:
	
	
protected:
	tb_event ev;
	
	Level_status level_status; 
	
	
	std::string name;
	bool ball_in_play;
	
		
	std::shared_ptr<Box> border;
	std::shared_ptr<Paddle> paddle;
	std::shared_ptr<Ball> ball;
	
	
	// Tells you whether object will hit anything if at x,y (assuming that that 
	// is its next position). Pointers to blocks that are hit will be coppied
	// to hit_blocks
	virtual bool will_collide(std::shared_ptr<Drawable> object, 
		int x, int y) = 0;
	
	// Deletes all hit_blocks
	virtual void delete_hit() = 0;
	
	
public:		
    
	virtual Level_status run() = 0;    

};