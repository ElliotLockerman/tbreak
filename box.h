class Box
{
private:
	int x, y, width, height, thickness;
	tb_cell cell;

public:
	Box(int x, int y, int width, int height, int thickness, uint32_t ch, uint16_t fg, uint16_t bg);
	
	void draw();
	bool contains_point(int x, int y);

};
