#include <ctime>
#include <cstdlib>

#include "termbox.h"
#include <SFML/Window/Keyboard.hpp>

#include "window.h"

#pragma once


// Window asking if sure, if so calls quit()
// Returns true if quit, false if not quit
bool quit_window();

bool pause_window();

void sleep(double miliseconds);

