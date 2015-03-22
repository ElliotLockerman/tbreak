#import "utility.h"

void sleep(unsigned int miliseconds)
{
	unsigned int micro = 1000 * miliseconds;
    clock_t goal = micro + clock();
    while (clock() < goal);
}