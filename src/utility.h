#include <ctime>
#include <cstdlib>

#include "termbox.h"

#include "window.h"


void sleep(unsigned int miliseconds);



// Window asking if sure, if so calls quit()
// Returns true if quit, false if not quit
bool quit_window();

bool pause_window();

