#include "level_type_block_freeform.h"

Level_type_block_freeform::Level_type_block_freeform(int lives, int score, 
	Json::Value config)
{
	
	this->level_status.lives = lives,
	this->level_status.score = score,
	this->level_status.result = OUT_OF_LIVES; // Just so its not uninitialized. It should be set before its read
	

	this->name = config["name"].asString();
	ball_in_play = false;
	
    
    for(int i = 0; i < config["blocks"].size(); i++)
    {
		Block* block = new Block(config["blocks"][i]["x"].asInt(), 
            config["blocks"][i]["y"].asInt(), 
            config["blocks"][i]["block_width"].asInt(), 
            config["blocks"][i]["block_height"].asInt(), 
            config["blocks"][i]["points_per_block"].asInt(),
            config["blocks"][i]["block_default_char"].asString()[0], 
            TB_DEFAULT, TB_DEFAULT);
    
		if(config["blocks"][i].isMember("block_string"))
		{				
			block->replace_string(0, 0, 
                config["blocks"][i]["block_width"].asInt(), 
				config["blocks"][i]["block_string"].asString(), 
                TB_DEFAULT, TB_DEFAULT);
		}

		this->blocks.push_back(std::shared_ptr<Block>(block));
    }
    
    
	border.reset(new Box(0, 0, game_width, game_height, 1, 
		'#', TB_DEFAULT, TB_DEFAULT));
		
	paddle.reset(new Paddle(32, 20, 13, 1, '=', TB_DEFAULT, TB_DEFAULT));
	
	ball.reset(new Ball(3, 22, 1, -1, 'o', TB_DEFAULT, TB_DEFAULT));
    
}