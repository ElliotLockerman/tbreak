#pragma once

// Time
static const unsigned int tick = 75; // Delay between event loop cycles
static const int peek_time = 20; // Time waiting for event per cycle


// Screensize
static const int full_width = 80;
static const int full_height = 24; 


// Game

enum Level_result{OUT_OF_LIVES, WON, QUIT};

struct Level_status
{
	int lives;
	int score;
	Level_result result;
};
