class Drawable
{
public:
	virtual void draw() = 0;
	virtual bool contains_point(int x, int y) = 0;
};