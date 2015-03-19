#import "drawable.h"
#import "box.h"

class Collision_tester
{
private:
	set<Box*> blocks;
	Box* border;
	Paddle* paddle;
	
public:
	void draw_all();
	virtual void push(Drawable item);
	virtual void delete(Drawable item);
	
	bool test_collision(int x, int x);
	virtual drawable retrieve_collided();
};