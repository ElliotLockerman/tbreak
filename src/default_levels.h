#import <string>

std::string default_level =
R"(
{
	"starting_lives": 3,
	
    "levels": 
	[
		{
			"name": "Test Name Really Long",
            "type": "block_grid",
            
            "block_width": 6,
            "block_height": 2,
			"block_default_char": "%",
            "block_string": "|\"\"\"\"||____|",
			
            "number_of_columns": 13,
            "number_of_rows": 4,
			"points_per_block": 10,
			
            "starting_x": 1,
            "starting_y": 3,
            "top_padding": 0,
			"left_padding": 0
        },
		{
			"name": "Level 2",
            "type": "block_grid",

            "block_width": 6,
            "block_height": 2,
			"block_default_char": "%",
            "block_string": "%%%%%%%%%%%%",
			
            "number_of_columns": 13,
            "number_of_rows": 5,
            "points_per_block": 10,
			
            "starting_x": 1,
            "starting_y": 3,
			"top_padding": 0,
            "left_padding": 0
            
        },
		{
			"name": "Level 3",
            "type": "block_grid",
			
            "block_width": 6,
            "block_height": 2,
			"block_default_char": "%",
            "block_string": "%%%%%%%%%%%%",
			
            "number_of_columns": 11,
            "number_of_rows": 3,
            "points_per_block": 10,
			
            "starting_x": 1,
            "starting_y": 3,
            "top_padding": 1,
            "left_padding": 1
        }
	]
}
)";