#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../external/jsoncpp/json/json.h"

#include "default_levels.h"
#include "level.h"
#include "game_main.h"

/*
 * Handles comand line arguments, initializes termbox and starts the game
 *
 */

int main(int argc, char* argv[])
{
    // Get the json of levels
    
    std::string level_json;
    std::string line;
    
    if(argc > 1)
    {
        std::ifstream ifile(argv[1]);
        if(ifile.is_open())
        {
            while(getline(ifile, line))
            {
                level_json.append(line);
            }
            ifile.close();
        }
        else
        {
            std::cerr << "The specified file could not be found" << std::endl;
            return 1;
        }
    }
    else
    {
        level_json = default_level;
    }
    


    // Parse json of levels
    Json::Value level_root;
    Json::Reader reader;
    if(!reader.parse(level_json, level_root))
    {
        std::cerr << "Parser Error" << std::endl
                 << reader.getFormattedErrorMessages();
        return EXIT_FAILURE;
    }
    
    
    
    int points_for_life = -1;
    if(level_root.isMember("points_for_life"))
    {
        if(!level_root["points_for_life"].isNumeric())
        {
            std::cerr << "Level parsing error:" << std::endl;
            std::cerr << "\"points_for_life\" must be number" <<std::endl;
            return EXIT_FAILURE;
        }
        points_for_life = level_root["points_for_life"].asInt();
    }
    

    
    int starting_lives = default_starting_lives;
    if(level_root.isMember("starting_lives"))
    {
        if(!level_root["starting_lives"].isNumeric())
        {
            std::cerr << "Level parsing error:" << std::endl;
            std::cerr << "\"starting_lives\" must be number" <<std::endl;
            return EXIT_FAILURE;
        }
        starting_lives = level_root["starting_lives"].asInt();
    }
   
   
    Json::Value json_levels = level_root["levels"];
    std::vector<Json::Value> levels;

    
    for(int i = 0; i < static_cast<int>(json_levels.size()); i++)
    {
    
        if(!json_levels[i].isMember("name"))
        {
            std::cerr << "Level parsing error:" << std::endl;
            std::cerr << "Level " << i + 1 << "must have a key \"name\"" 
                << std::endl;
            return EXIT_FAILURE;
        }
        if(!json_levels[i]["name"].isString())
        {
            std::cerr << "Level parsing error:" << std::endl;
            std::cerr << "Level " << i + 1 
                << "'s \"name\" value must be a string" << std::endl;
            return EXIT_FAILURE;
        }
    
        
        
        
        if(!json_levels[i].isMember("type"))
        {
            std::cerr << "Level parsing error:" << std::endl;
            std::cerr << json_levels[i]["name"]  << " must have a key \"type\"" 
                << std::endl;
            return EXIT_FAILURE;
        }
        if(!json_levels[i]["type"].isString())
        {
            std::cerr << "Level parsing error:" << std::endl;
            std::cerr << json_levels[i]["name"] 
                << "'s \"type\" value must be a string" << std::endl;
            return EXIT_FAILURE;
        }
        
        
        
            
        
        if(json_levels[i]["type"].asString() == "block_grid")
        {
            if(Level_type_block_grid::verify_level_json(json_levels[i]))
                levels.push_back(json_levels[i]);
            else
                return EXIT_FAILURE;
        }
        else if (json_levels[i]["type"].asString() == "block_freeform")
        {
            if(Level_type_block_freeform::verify_level_json(json_levels[i]))
                levels.push_back(json_levels[i]);
            else
                return EXIT_FAILURE;
        }
        else
        {
            std::cerr << "Error: The only level types currently available are " 
                "\"block_grid\" and \"block_freeform\"" << std::endl;
            return EXIT_FAILURE;
        }       
    }



    
    
    // Initialize termbox
    int init_status = tb_init();
    if(init_status != 0)
    { 
        std::cerr << "tb_init() failed with error code " << init_status 
            << std::endl; 
        return EXIT_FAILURE;
    }
    
    if(tb_height() < game_height || tb_width() < game_width)
    {
        tb_shutdown();
        std::cerr << "Error: Please resize terminal to at least 80x24 (WxH)" 
                  << std::endl;
        return EXIT_FAILURE;
    }
    
    
    
    // Start the game
    Game_main game(points_for_life, starting_lives, levels);
    game.run();

    tb_shutdown();
    return EXIT_SUCCESS;
}