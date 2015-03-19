#import "termbox.h"

#import "box.h"



class Paddle : public Box
{
private:
	bool ball;
	
public:
	
	Paddle(int x, int y, int width, int height, uint32_t cch, uint16_t cfg, uint16_t cbg) : 
		Box(x, y, width, height, cch, cfg, cbg)
		{
		}
	
	
	
	// Moving paddle
	void move_left();
	void move_right();
	
	// For launching a new ball
	void show_ball();
	void hide_ball();
};
