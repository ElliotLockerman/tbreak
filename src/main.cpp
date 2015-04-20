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
	



	Json::Value level_root;
	Json::Reader reader;
	if(!reader.parse(level_json, level_root))
	{
		std::cerr << "Parser Error" << std::endl
			     << reader.getFormattedErrorMessages();
	}


	int starting_lives = level_root["starting_lives"].asInt();
	Json::Value json_levels = level_root["levels"];

	std::vector<Level::generic_level_config> levels;
	// levels.resize(json_levels.size());
	
	for(unsigned int i = 0; i < json_levels.size(); i++)
	{
		Level::generic_level_config config;
		if(json_levels[i]["type"].asString() == "block_grid")
		{
			config = 
			{	
				.name               = json_levels[i]["name"].asString(),
				.type               = json_levels[i]["type"].asString(),
				
				.block_width        = json_levels[i]["block_width"].asInt(),
				.block_height       = json_levels[i]["block_height"].asInt(),
				.block_default_char = json_levels[i]["block_default_char"].asString()[0],
				.block_string       = json_levels[i]["block_string"].asString(),
					
					
				.number_of_columns  = json_levels[i]["number_of_columns"].asInt(),
				.number_of_rows     = json_levels[i]["number_of_rows"].asInt(),
				.points_per_block   = json_levels[i]["points_per_block"].asInt(),

				.starting_x         = json_levels[i]["starting_x"].asInt(),
				.starting_y         = json_levels[i]["starting_y"].asInt(),
				.top_padding        = json_levels[i]["top_padding"].asInt(),
				.left_padding       = json_levels[i]["left_padding"].asInt()
			};
		}
			
		levels.push_back(config);	
	}


	std::cerr << "0th level type: " << levels[0].type << std::endl;
	

	
	// Initialize
	int init_status = tb_init();
	if(init_status != 0)
	{ 
		std::cerr << "tb_init() failed with error code " << init_status << std::endl; 
		return 1;
	}
	
	
	Game_main game(starting_lives, levels);
	game.run();

	tb_shutdown();
	
}