#include "box.h"

/*
 * Block
 * Box plus points
 */

class Block : public Box
{
private:
    int points;
    
public:
    Block(int x, int y, int width, int height, int points,
    		uint32_t cch, uint16_t cfg, uint16_t cbg)
    : Box(x, y, width, height, cch, cfg, cbg)
    {
        this->points = points;
    }
    
    int get_points() {return points;};
};