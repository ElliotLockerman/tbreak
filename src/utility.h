#include <ctime>
#include <cstdlib>

#include "termbox.h"

#include "window.h"


void sleep(unsigned int miliseconds);

// Immediatly quits
void quit();

// Immediatly quits with status and error message
void quit(int status, std::string error);


// Window asking if sure, if so calls quit()
void quit_window();

void pause_window();

