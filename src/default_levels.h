#include <string>

std::string default_level =
R"(
{
    "starting_lives": 3,
    
    "levels": 
    [   
        {
            "type": "block_grid",
            "name": "Level 1",
        
            "block_width": 8,
            "block_height": 3,
            "block_default_char": "%",
            "block_string": "|\"\"\"\"\"\"||      ||______|",
        
            "number_of_columns": 9,
            "number_of_rows": 3,
            "points_per_block": 10,
        
            "starting_x": 3,
            "starting_y": 3
        },
        {
            "type": "block_freeform",
            "name": "Level 2",
            "blocks":
            [
                {
                    "x": 36,
                    "y": 1,
                    "block_width": 8,
                    "block_height": 3,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"\"\"||      ||______|",
        
                    "points_per_block": 10
                },
                {
                    "x": 20,
                    "y": 2,
                    "block_width": 8,
                    "block_height": 3,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"\"\"||      ||______|",
        
                    "points_per_block": 10
                },
                {
                    "x": 28,
                    "y": 2,
                    "block_width": 8,
                    "block_height": 3,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"\"\"||      ||______|",
        
                    "points_per_block": 10
                },
                {
                    "x": 44,
                    "y": 2,
                    "block_width": 8,
                    "block_height": 3,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"\"\"||      ||______|",
        
                    "points_per_block": 10
                },
                {
                    "x": 52,
                    "y": 2,
                    "block_width": 8,
                    "block_height": 3,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"\"\"||      ||______|",
        
                    "points_per_block": 10
                },
                {
                    "x": 9,
                    "y": 5,
                    "block_width": 8,
                    "block_height": 3,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"\"\"||      ||______|",
        
                    "points_per_block": 10
                },
                {
                    "x": 17,
                    "y": 5,
                    "block_width": 8,
                    "block_height": 3,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"\"\"||      ||______|",
        
                    "points_per_block": 10
                },
                {
                    "x": 55,
                    "y": 5,
                    "block_width": 8,
                    "block_height": 3,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"\"\"||      ||______|",
        
                    "points_per_block": 10
                },
                {
                    "x": 63,
                    "y": 5,
                    "block_width": 8,
                    "block_height": 3,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"\"\"||      ||______|",
        
                    "points_per_block": 10
                },
                {
                    "x": 1,
                    "y": 8,
                    "block_width": 8,
                    "block_height": 3,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"\"\"||      ||______|",
        
                    "points_per_block": 10
                },
                {
                    "x": 9,
                    "y": 8,
                    "block_width": 8,
                    "block_height": 3,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"\"\"||      ||______|",
        
                    "points_per_block": 10
                },
                {
                    "x": 63,
                    "y": 8,
                    "block_width": 8,
                    "block_height": 3,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"\"\"||      ||______|",
        
                    "points_per_block": 10
                },
                {
                    "x": 71,
                    "y": 8,
                    "block_width": 8,
                    "block_height": 3,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"\"\"||      ||______|",
        
                    "points_per_block": 10
                },
                {
                    "x": 1,
                    "y": 11,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 7,
                    "y": 11,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 13,
                    "y": 11,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 19,
                    "y": 11,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 25,
                    "y": 11,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 31,
                    "y": 11,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 37,
                    "y": 11,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 43,
                    "y": 11,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 49,
                    "y": 11,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 55,
                    "y": 11,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 61,
                    "y": 11,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 67,
                    "y": 11,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 73,
                    "y": 11,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                }
            ]
        },
        {
            "type": "block_grid",
            "name": "Level 3",
            
            "block_width": 6,
            "block_height": 2,
            "block_default_char": "%",
            "block_string": "|\"\"\"\"||____|",
            
            "number_of_columns": 13,
            "number_of_rows": 4,
            "points_per_block": 5,
            
            "starting_x": 1,
            "starting_y": 3
        },
        {
            "type": "block_freeform",
            "name": "Level 4",
            "blocks":
            [
                {
                    "x": 1,
                    "y": 2,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 37,
                    "y": 2,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 73,
                    "y": 2,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 4,
                    "y": 4,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 34,
                    "y": 4,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 40,
                    "y": 4,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 70,
                    "y": 4,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 1,
                    "y": 6,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 7,
                    "y": 6,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 31,
                    "y": 6,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 37,
                    "y": 6,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 43,
                    "y": 6,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 67,
                    "y": 6,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 73,
                    "y": 6,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 4,
                    "y": 8,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 10,
                    "y": 8,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 28,
                    "y": 8,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 34,
                    "y": 8,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 40,
                    "y": 8,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 46,
                    "y": 8,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 64,
                    "y": 8,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 70,
                    "y": 8,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 1,
                    "y": 10,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 7,
                    "y": 10,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 13,
                    "y": 10,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 25,
                    "y": 10,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 31,
                    "y": 10,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 37,
                    "y": 10,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 43,
                    "y": 10,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 49,
                    "y": 10,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 61,
                    "y": 10,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 67,
                    "y": 10,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 73,
                    "y": 10,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 4,
                    "y": 12,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 10,
                    "y": 12,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 16,
                    "y": 12,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 22,
                    "y": 12,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 28,
                    "y": 12,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 34,
                    "y": 12,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 40,
                    "y": 12,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 46,
                    "y": 12,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 52,
                    "y": 12,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 58,
                    "y": 12,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 64,
                    "y": 12,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                },
                {
                    "x": 70,
                    "y": 12,
                    "block_width": 6,
                    "block_height": 2,
                    "block_default_char": "%",
                    "block_string": "|\"\"\"\"||____|",
        
                    "points_per_block": 5
                }
            ]
        },
        {
            "type": "block_grid",
            "name": "Level 5",

            "block_width": 6,
            "block_height": 2,
            "block_default_char": "%",
            
            "number_of_columns": 13,
            "number_of_rows": 5,
            "points_per_block": 7,
            
            "starting_x": 1,
            "starting_y": 3
        },
        {
            "type": "block_grid",
            "name": "Level 6",
            
            "block_width": 6,
            "block_height": 2,
            "block_default_char": "%",
            
            "number_of_columns": 11,
            "number_of_rows": 3,
            "points_per_block": 10,
            
            "starting_x": 1,
            "starting_y": 3,
            "top_margin": 1,
            "left_margin": 1
        },
        {
            "type": "block_grid",
            "name": "Level 7",
            
            "block_width": 4,
            "block_height": 2,
            "block_default_char": "%",
            "block_string": "|^^||__|",
            
            "number_of_columns": 19,
            "number_of_rows": 4,
            "points_per_block": 3,
            
            "starting_x": 1,
            "starting_y": 3
        }
    ]
}
)";