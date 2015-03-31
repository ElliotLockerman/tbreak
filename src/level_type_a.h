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
	Level_type_a(int lives, int level, int score);
    
	using Level::run;
	virtual Level_status run(); 
	
};