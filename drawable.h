/*
Represents anything that can be drawn on the screen
*/

class Drawable
{
public:
	// Does the drawing (but does not call present())
	virtual void draw() = 0;
	
	// Returns true if the object has a character at the given point (Note: even if the character has been overwritten by another object's [which should be avoided])
	virtual bool contains_point(int x, int y) = 0;
};