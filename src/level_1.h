#include <string>

#include "termbox.h"

#include "level.h"
#include "draw_string.h"

class Level_1 : public Level
{
private:
	
protected:
	using Level::will_collide;
	virtual bool will_collide(std::shared_ptr<Drawable> object, int x, int y);
	
	using Level::delete_hit;
	virtual void delete_hit();
	
		
	
	
	
public:	
	Level_1(int lives, int score);
	
	using Level::run;
	virtual Level_status run(); 
	
	using Level::get_lives;
	virtual int get_lives();
	
	using Level::get_score;
	virtual int get_score();
	
	
};