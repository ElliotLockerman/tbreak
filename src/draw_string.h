/* 
Draws a string str starting at x, y. If longer than max_width, it wraps to the next line (without regard for word breaks, etc)
For information on fg and bg, see termbox.h
*/
void draw_string(int x, int y, int colwidth, std::string str, uint16_t fg, uint16_t bg);