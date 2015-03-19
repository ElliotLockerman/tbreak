#import "termbox.h"
#import "box.h"

class Paddle: public Box
{
private:
	bool ball;
	
public:
	Paddle(int x, int y, int width, int height, int border_thickness, uint32_t ch, uint16_t fg, uint16_t bg) : Box(x, y, width, height, border_thickness, ch, fg, bg){}
	Paddle(int x, int y, int width, int height, uint32_t cch, uint16_t cfg, uint16_t cbg) : Box(x, y, width, height, cch, cfg, cbg){}
	Paddle(int x, int y, int width, int height, int border_thickness, uint32_t bch, uint16_t bfg, uint16_t bbg, uint32_t cch, uint16_t cfg, uint16_t cbg) : Box( x,  y,  width,  height,  border_thickness, bch, bfg, bbg, cch, cfg, cbg){}
	
	
	// Moving paddle
	void move_left();
	void move_right();
	
	// For launching a new ball
	void show_ball();
	void hide_ball();
};