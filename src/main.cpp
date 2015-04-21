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

	std::vector<Level::generic_level_config> levels;
	// levels.resize(json_levels.size());
	
	for(unsigned int i = 0; i < json_levels.size(); i++)
	{
		Level::generic_level_config config;
		
		
		
		
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
		config.name = json_levels[i]["name"].asString() ;
		
		
		
		
		
		if(!json_levels[i].isMember("type"))
		{
			std::cerr << "Level parsing error:" << std::endl;
			std::cerr << config.name << " must have a key \"type\"" 
				<< std::endl;
			return EXIT_FAILURE;
		}
		if(!json_levels[i]["type"].isString())
		{
			std::cerr << "Level parsing error:" << std::endl;
			std::cerr << config.name << "'s \"type\" value must be a string" 
				<< std::endl;
			return EXIT_FAILURE;
		}
		config.type = json_levels[i]["type"].asString();
		
		
		
	
	
		
		if(json_levels[i]["type"].asString() == "block_grid")
		{
			
			
			std::vector<std::string> required_strings =
			{
				"block_default_char",
				"block_string"
			};
		
		
			for(unsigned int j = 0; j < required_strings.size(); j++)
			{
				if(!json_levels[i].isMember(required_strings[j]))
				{
					std::cerr << "Level parsing error:" << std::endl;
					std::cerr << config.name << " must have a key \"" 
						<< required_strings[j] << "\""<< std::endl;
					return EXIT_FAILURE;
				}
				if(!json_levels[i][required_strings[j]].isString())
				{
					std::cerr << "Level parsing error:" << std::endl;
					std::cerr << config.name << "'s " << required_strings[j] 
						<<" value must be a string" << std::endl;
					return EXIT_FAILURE;
				}
			}
			config.block_default_char = 
				json_levels[i]["block_default_char"].asString()[0];
			config.block_string = json_levels[i]["block_string"].asString();
			
			
			
			
			
	
			
			
			
			
			std::vector<std::string> required_nums = 
			{
				"block_width",
			    "block_height",
				"number_of_columns",
				"number_of_rows",
				"points_per_block",

				"starting_x",
			    "starting_y",
			    "top_padding",
			    "left_padding"
			};
			
			for(unsigned int j = 0; j < required_nums.size(); j++)
			{
				if(!json_levels[i].isMember(required_nums[j]))
				{
					std::cerr << "Level parsing error:" << std::endl;
					std::cerr << config.name << " must have a key \"" 
						<< required_nums[j] << "\"" << std::endl;
					return EXIT_FAILURE;
				}
				if(!json_levels[i][required_nums[j]].isNumeric())
				{
					std::cerr << "Level parsing error:" << std::endl;
					std::cerr << config.name << "'s " << required_nums[j] 
						<<" value must be a number" << std::endl; 
					return EXIT_FAILURE;
				}
			}
			
			config.block_width        = json_levels[i]["block_width"].asInt();
			config.block_height       = json_levels[i]["block_height"].asInt();

			config.number_of_columns  = 
				json_levels[i]["number_of_columns"].asInt();
			config.number_of_rows     = 
				json_levels[i]["number_of_rows"].asInt();
			config.points_per_block   = 
				json_levels[i]["points_per_block"].asInt();
 
			config.starting_x         = json_levels[i]["starting_x"].asInt();
			config.starting_y         = json_levels[i]["starting_y"].asInt();
			config.top_padding        = json_levels[i]["top_padding"].asInt();
			config.left_padding       = json_levels[i]["left_padding"].asInt();
		
			
		}
		else
		{
			std::cerr << "The only level type currently available is " 
				"\"block_grid\"" << std::endl;
			return EXIT_FAILURE;
		}
			
		levels.push_back(config);	
	}


	

	
	
	
	
	
	
	// Initialize termbox
	int init_status = tb_init();
	if(init_status != 0)
	{ 
		std::cerr << "tb_init() failed with error code " << init_status 
			<< std::endl; 
		return 1;
	}
	
	if(tb_height() < full_height || tb_width() < full_width)
	{
		tb_shutdown();
		std::cerr << "Error: Please resize terminal to at least 80x24" 
				  << std::endl;
		return EXIT_FAILURE;
	}
	
	
	
	// Start the game
	Game_main game(starting_lives, levels);
	game.run();

	tb_shutdown();
	return EXIT_SUCCESS;
}