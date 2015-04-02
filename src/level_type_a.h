#include <string>
#include <memory>

#include "termbox.h"

#include "level.h"
#include "draw_string.h"
#include "window.h"


#pragma once



/*
 * The first level type.
 * Blocks are each a box
 * You can create a level of this type with just a subclass header which calls this constructor and makes the blocks
 */


class Level_type_a : public Level
{
private:
	
protected:
	
	std::list<std::shared_ptr<Box> > blocks;
	std::list<std::shared_ptr<Box> >::iterator blocks_it;
	
	std::set<std::shared_ptr<Box> > hit_blocks;
	std::set<std::shared_ptr<Box> >::iterator hit_it;
	
	
	using Level::will_collide;
	virtual bool will_collide(std::shared_ptr<Drawable> object, int x, int y);
	
	using Level::delete_hit;
	virtual void delete_hit();
	
	void draw_data();
	
public:	
	Level_type_a(std::string name, int lives, int score);
    
	using Level::run;
	virtual Level_status run(); 
	
};