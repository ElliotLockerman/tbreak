#include <iostream>
#include <fstream>
#include <string>

#include "../external/jsoncpp/json/json.h"

#include "default_levels.h"
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
	// TODO: Parse json to data structure before starting up game 
	
	
	
	// Initialize
	int init_status = tb_init();
	if(init_status != 0)
	{ 
		std::cerr << "tb_init() failed with error code " << init_status << std::endl; 
		return 1;
	}
	
	
	Game_main game(level_root);
	game.run();

	tb_shutdown();
	
}