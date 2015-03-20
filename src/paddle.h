#import "termbox.h"

#import "box.h"



class Paddle : public Box
{
private:
	bool ball;
	tb_cell ball_cell;

public:
	
	Paddle(int x, int y, int width, int height, uint32_t cch, uint16_t cfg, uint16_t cbg) : 
		Box(x, y, width, height, cch, cfg, cbg)
		{
			ball = true;
			
			ball_cell.ch = 'o';
			ball_cell.fg = cfg;
			ball_cell.bg = cbg;
			
		}
	
	// Drawable implementations. See drawable.h
	using Drawable::draw;
	virtual void draw();
	
	// Get the ball's x position
	int ball_x();
	
	// To be called upon launching it
	void remove_ball();
	
	// Moving paddle
	void move_right(int dx);
	void move_left(int dx);
	
	// For launching a new ball
	void show_ball();
	void hide_ball();
};
