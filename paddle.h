#import "drawable.h"

class Paddle: public Box
{
private:
	bool ball;
	
public:
	// For launching a new ball
	void show_ball();
	void hide_ball();
}