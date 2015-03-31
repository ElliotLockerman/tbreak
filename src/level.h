#include <list>
#include <set>
#include <cstdlib>
#include <string>

#include "constants.h"
#include "utility.h"
#include "box.h"
#include "paddle.h"
#include "ball.h"
#include "drawable.h"

#pragma once

class Level
{
private:
	
	
protected:
	tb_event ev;
	
	Level_status level_status; 
	
	std::string name;
	bool ball_in_play;
	
	std::list<std::shared_ptr<Box> > blocks;
	std::list<std::shared_ptr<Box> >::iterator blocks_it;
	
	std::set<std::shared_ptr<Box> > hit_blocks;
	std::set<std::shared_ptr<Box> >::iterator hit_it;
	
		
	std::shared_ptr<Box> border;
	std::shared_ptr<Paddle> paddle;
	std::shared_ptr<Ball> ball;
	
	
	// Tells you whether object will hit anything if at x,y (assuming that that is its next position). Pointers to blocks that are hit will be coppied to hit_blocks
	virtual bool will_collide(std::shared_ptr<Drawable> object, int x, int y) = 0;
	
	// Deletes all hit_blocks
	virtual void delete_hit() = 0;
	
	
public:		
	virtual Level_status run() = 0;

};