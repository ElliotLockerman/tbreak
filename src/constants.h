#pragma once

// Time
static const unsigned int tick = 75; // Delay between event loop cycles
static const int peek_time = 20; // Time waiting for event per cycle


// Screensize
static const int full_width = 80;
static const int full_height = 24; 


// Game
static const int starting_lives = 3;
static const int starting_score = 0;
static const int score_per_block = 10;

enum Level_result{OUT_OF_LIVES, WON};

struct Level_status
{
	int lives;
	int score;
	Level_result result;
};
