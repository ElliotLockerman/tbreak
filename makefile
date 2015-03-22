all:
	g++ src/tbreak.cpp src/utility.cpp src/box.cpp src/draw_string.cpp src/paddle.cpp src/game_main.cpp src/ball.cpp -o tbreak -ltermbox