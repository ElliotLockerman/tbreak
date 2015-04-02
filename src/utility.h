#include <ctime>
#include <cstdlib>

#include "termbox.h"

#include "window.h"


void sleep(unsigned int miliseconds);

// Immediatly quits
void quit();

// Window asking if sure, if so calls quit()
void quit_window();

void pause_window();

