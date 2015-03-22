all:
	g++ src/tbreak.cpp src/utility.cpp src/game_main.cpp src/level_1.cpp src/box.cpp src/draw_string.cpp src/paddle.cpp  src/ball.cpp -o tbreak -ltermbox