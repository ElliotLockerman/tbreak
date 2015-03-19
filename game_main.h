class Game_main
{
private:
	const unsigned int tick = 75; // Delay between event loop cycles
	const int peek_time = 20; // Time waiting for event per cycle
 
	const int full_width = 80;
	const int full_height = 24; 

	struct tb_event ev;
	
	void quit();
	void sleep(unsigned int miliseconds);
	
public:
	
	void run();
	
	
}