#include "level_type_block_grid.h"


Level_type_block_grid::Level_type_block_grid(int lives, int score, 
    Json::Value config)
{
    
    this->level_status.lives = lives,
    this->level_status.score = score,
    this->level_status.result = OUT_OF_LIVES; // Just so its not uninitialized. It should be set before its read
    

    this->name = config["name"].asString();
    ball_in_play = false;
    
    
    
    for(int i = 0; i < config["number_of_rows"].asInt(); i++)
    {
        for(int j = 0; j < config["number_of_columns"].asInt(); j++)
        {
            int x = (j * (config["block_width"].asInt() 
                + config["left_margin"].asInt())) 
                + config["starting_x"].asInt();
            int y = (i * (config["block_height"].asInt()
                + config["top_margin"].asInt())) 
                + config["starting_y"].asInt();
    
            Block* block = new Block(x, y, config["block_width"].asInt(), 
                config["block_height"].asInt(), 
                config["points_per_block"].asInt(),
                config["block_default_char"].asString()[0], TB_DEFAULT, TB_DEFAULT);
    
            if(config.isMember("block_string"))
            {               
                block->replace_string(0, 0, config["block_width"].asInt(), 
                    config["block_string"].asString(), TB_DEFAULT, TB_DEFAULT);
            }

            this->blocks.push_back(std::shared_ptr<Block>(block));
            
        }
    }
    


    border.reset(new Box(0, 0, game_width, game_height, 1, 
        '#', TB_DEFAULT, TB_DEFAULT));
        
    paddle.reset(new Paddle(32, 20, 13, 1, '=', TB_DEFAULT, TB_DEFAULT));
    
    ball.reset(new Ball(3, 22, 1, -1, 'o', TB_DEFAULT, TB_DEFAULT));
    
}






bool Level_type_block_grid::verify_level_json(Json::Value json_level)
{
    std::vector<std::string> required_str = 
    {
        "block_default_char"

    };
    
    for(int i = 0; i < static_cast<int>(required_str.size()); i++)
    {
        if(!json_level.isMember(required_str[i]))
        {
            std::cerr << "Level parsing error:" << std::endl;
            std::cerr << json_level["name"].asString() << " must have a key \"" 
                << required_str[i] << "\"" << std::endl;
            return false;
        }
        if(!json_level[required_str[i]].isString())
        {
            std::cerr << "Level parsing error:" << std::endl;
            std::cerr << json_level["name"].asString() << "'s " 
                << required_str[i] <<" value must be a string" << std::endl; 
            return false;
        }
    }
    
    
    
    
    
    
    std::vector<std::string> optional_strings =
    {
        "block_string"
    };


    for(int i = 0; i < static_cast<int>(optional_strings.size()); i++)
    {
        if(json_level.isMember(optional_strings[i])
            && !json_level[optional_strings[i]].isString())
        {
            std::cerr << "Level parsing error:" << std::endl;
            std::cerr << json_level["name"].asString() << "'s " 
                << optional_strings[i] <<" value must be a string" << std::endl;
            return false;
        }
    }

    
    
    
    
    
    
    std::vector<std::string> required_nums = 
    {
        "block_width",
        "block_height",
        "number_of_columns",
        "number_of_rows",
        "points_per_block",

        "starting_x",
        "starting_y"

    };
    
    for(int i = 0; i < static_cast<int>(required_nums.size()); i++)
    {
        if(!json_level.isMember(required_nums[i]))
        {
            std::cerr << "Level parsing error:" << std::endl;
            std::cerr << json_level["name"].asString() << " must have a key \"" 
                << required_nums[i] << "\"" << std::endl;
            return false;
        }
        if(!json_level[required_nums[i]].isNumeric())
        {
            std::cerr << "Level parsing error:" << std::endl;
            std::cerr << json_level["name"].asString() << "'s " 
                << required_nums[i] <<" value must be a number" << std::endl; 
            return false;
        }
    }
    
    
    
    
    
    
    std::vector<std::string> optional_nums =
    {
        "top_margin",
        "left_margin"
    };
    
    for(int i = 0; i < static_cast<int>(optional_nums.size()); i++)
    {
        if(json_level.isMember(optional_nums[i])
            && !json_level[optional_nums[i]].isNumeric())
        {
            std::cerr << "Level parsing error:" << std::endl;
            std::cerr << json_level["name"].asString() << "'s " 
                << optional_nums[i] <<" value must be a number" << std::endl; 
            return false;
        }
    }
    
    
    
    
    
    return true;
}