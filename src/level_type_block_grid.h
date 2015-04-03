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


class Level_type_block_grid : public Level
{
private:
	
protected:
	
	
	std::list<std::shared_ptr<Box> > blocks;
	std::list<std::shared_ptr<Box> >::iterator blocks_it;
	
	std::set<std::shared_ptr<Box> > hit_blocks;
	std::set<std::shared_ptr<Box> >::iterator hit_it;
	
	int points_per_block;
	
	
	
	
	using Level::will_collide;
	virtual bool will_collide(std::shared_ptr<Drawable> object, int x, int y);
	
	using Level::delete_hit;
	virtual void delete_hit();
	
	void draw_data();
	
public:	
	struct block_grid_config
	{
		int lives;
		int score;
		
		std::string name;
		
		int block_width;
		int block_height;
		char block_default_char;
		std::string block_string;
		
		int number_of_columns;
		int number_of_rows;
		int points_per_block;

		int starting_x;
		int starting_y;
		int top_padding;
		int left_padding;
	};
	
	
	Level_type_block_grid(block_grid_config config);
    
	using Level::run;
	virtual Level_status run(); 
	
};