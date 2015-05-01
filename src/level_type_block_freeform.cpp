#include "level_type_block_freeform.h"

Level_type_block_freeform::Level_type_block_freeform(int points_for_life, int 
    lives, int score, Json::Value config)
{
    this->points_for_life = points_for_life;
    
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




bool Level_type_block_freeform::verify_level_json(Json::Value json_level)
{
    
    for(int j = 0; j < json_level["blocks"].size(); j++)
    {        
        Json::Value block = json_level["blocks"][j];
        
        
        std::vector<std::string> required_str = 
        {
            "block_default_char"

        };
    
        for(int i = 0; i < static_cast<int>(required_str.size()); i++)
        {
            if(!block.isMember(required_str[i]))
            {
                std::cerr << "Level parsing error:" << std::endl;
                std::cerr << json_level["name"].asString() << " block " 
                    << j+1 << " must have a key \""  << required_str[i] 
                    << "\"" << std::endl;
                return false;
            }
            if(!block[required_str[i]].isString())
            {
                std::cerr << "Level parsing error:" << std::endl;
                std::cerr << json_level["name"].asString() << " block " << j+1 
                    << "'s \"" << required_str[i] << "\" value must be a string" 
                    << std::endl; 
                return false;
            }
        }
    
    
        
        
        
        
        
        
        
        std::vector<std::string> optional_strings =
        {
            "block_string"
        };


        for(int i = 0; i < static_cast<int>(optional_strings.size()); i++)
        {
            if(block.isMember(optional_strings[i])
                && !block[optional_strings[i]].isString())
            {
                std::cerr << "Level parsing error:" << std::endl;
                std::cerr << json_level["name"].asString() << " block " << j+1 
                    << "'s \"" << optional_strings[i] <<"\" value must be a string" << std::endl;
                return false;
            }
        }

    
    
    
    
    
    
        std::vector<std::string> required_nums = 
        {
            "block_width",
            "block_height",
            "points_per_block",

            "x",
            "y",

        };
    
        for(int i = 0; i < static_cast<int>(required_nums.size()); i++)
        {
            if(!block.isMember(required_nums[i]))
            {
                std::cerr << "Level parsing error:" << std::endl;
                std::cerr << json_level["name"].asString() << " block " 
                    << j+1 <<  " must have a key \"" << required_nums[i] << "\"" 
                    << std::endl;
                return false;
            }
            if(!block[required_nums[i]].isNumeric())
            {
                std::cerr << "Level parsing error:" << std::endl;
                std::cerr << json_level["name"].asString() << " block " << j+1 
                    << "'s \"" <<  required_nums[i] <<"\" value must be a number" 
                    << std::endl; 
                return false;
            }
        }
    
    
    
    }
    
    return true;
}