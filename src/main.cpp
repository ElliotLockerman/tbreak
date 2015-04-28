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
	}


	int starting_lives = level_root["starting_lives"].asInt();
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
		
		
		if(json_levels[i]["type"].asString() == "block_grid"
			&& Level_type_block_grid::verify_level_json(json_levels[i]))
		{
			
			levels.push_back(json_levels[i]);
		}
		else
		{
			std::cerr << "The only level type currently available is " 
				"\"block_grid\"" << std::endl;
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
	Game_main game(starting_lives, levels);
	game.run();

	tb_shutdown();
	return EXIT_SUCCESS;
}