#pragma once

/*
Represents anything that can be drawn on the screen
*/
class Drawable
{
private:
	
protected:
	int x, y;
	
public:

	// Does the drawing (but does not call present())
	virtual void draw() = 0;
	
	// Returns true if the object has a character at the given point (Note: even if the character has been overwritten by another object's [which should be avoided]) If you need to replace a portion of an object, call its remove_char() function on any points that will be covered up
	virtual bool contains_point(int x, int y) = 0;
	
	// Changes x and y. Updates on the next calls to tb_clear(), draw(), tb_present(). 
	virtual void move_to(int x, int y) = 0;

	virtual int get_x() = 0;
	virtual int get_y() = 0;
	
	// To be called when something collides with the object
	//virtual void collided() = 0;

};