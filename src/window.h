#include <string>

#include "termbox.h"

#include "box.h"

class Window : public Box
{
private:
	enum alignment // An alternative to manually setting x-position
	{
		CENTER,
		LEFT
	};

	struct text
	{
		std::string str;
		
		int rel_x; // Relative to window
		int rel_y; // Relative to window
		
		int colwidth; // Will wrap if wider than (dumb wrap: will split words, etc)
		
		uint16_t fg;
		uint16_t bg;
	};
	
	std::list<text> texts;
	
public:
	Window(int x, int y, int width, int height, int border_thickness, uint32_t bch, uint16_t bfg, uint16_t bbg) :
	Box(x, y, width, height, border_thickness, bch, bfg, bbg)
	{
	}
	
	// y is relative to window
	void add_string(int rel_y, std::string str, alignment align, int colwidth, int left_padding, uint16_t fg, uint16_t bg);
	
	// x, y are relative to window
	void add_string(int rel_x, int rel_y, std::string str, int colwidth, uint16_t fg, uint16_t bg);
	
	void draw_window();
};

