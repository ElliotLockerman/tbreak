#include "level_abstract_block.h"



#pragma once



/*
 * The first level type.
 * Blocks are each a box
 * You can create a level of this type with just a subclass header which calls this constructor and makes the blocks
 */


class Level_type_block_grid : public Level_abstract_block
{
private:

	
public:		
	Level_type_block_grid(int lives, int score, Json::Value config);
    
    Level_type_block_grid(const Level_type_block_grid&) = delete;
	
	static bool verify_level_json(Json::Value level_json);
	
};