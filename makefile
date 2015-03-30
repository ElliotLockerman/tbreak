CXX = g++
CXXFLAGS = -c -Wall
LDFLAGS = -ltermbox
DEBUG = -g

SRC = src
OBJ = obj
PREFIX? = /usr/local

EXECUTABLE = tbreak



OBJS = $(OBJ)/main.o $(OBJ)/ball.o $(OBJ)/box.o $(OBJ)/draw_string.o $(OBJ)/game_main.o $(OBJ)/level_a_1.o $(OBJ)/level_a_2.o $(OBJ)/level_a_3.o $(OBJ)/level_type_a.o $(OBJ)/paddle.o $(OBJ)/utility.o $(OBJ)/window.o

all: $(OBJS)
	$(CXX) $(LDFLAGS) -o $(EXECUTABLE) $(DEBUG) $(OBJS)





.PHONY: clean
clean:
	find . -name $(EXECUTABLE) -delete
	find . -name '*.o' -delete
 

.PHONY: install
install:
	mv $(EXECUTABLE) $(PREFIX)/bin

.PHONY: uninstall
uninstall:
	find $(PREFIX)/bin -name $(EXECUTABLE) -delete





$(OBJ)/main.o: $(SRC)/game_main.h $(SRC)/utility.h
	$(CXX) $(CXXFLAGS) -o $@ $(SRC)/main.cpp

$(OBJ)/game_main.o: $(SRC)/game_main.h $(SRC)/game_main.cpp $(SRC)/draw_string.h $(SRC)/utility.h  $(SRC)/window.h $(SRC)/level_a_1.h $(SRC)/level_a_2.h $(SRC)/level_a_3.h
	$(CXX) $(CXXFLAGS) -o $@  $(SRC)/game_main.cpp

$(OBJ)/draw_string.o: $(SRC)/draw_string.h $(SRC)/draw_string.cpp
	$(CXX) $(CXXFLAGS) -o $@  $(SRC)/draw_string.cpp

$(OBJ)/utility.o: $(SRC)/utility.h  $(SRC)/utility.cpp
	$(CXX) $(CXXFLAGS) -o $@  $(SRC)/utility.cpp

$(OBJ)/window.o: $(SRC)/window.h $(SRC)/window.cpp $(SRC)/box.h $(SRC)/constants.h
	$(CXX) $(CXXFLAGS) -o $@  $(SRC)/window.cpp

$(OBJ)/level_a_1.o: $(SRC)/level_a_1.h $(SRC)/level_type_a.h $(SRC)/level_type_a.h $(SRC)/draw_string.h $(SRC)/drawable.h
	$(CXX) $(CXXFLAGS) -o $@  $(SRC)/level_a_1.cpp

$(OBJ)/level_a_2.o: $(SRC)/level_a_2.h $(SRC)/level_type_a.h $(SRC)/draw_string.h $(SRC)/drawable.h
	$(CXX) $(CXXFLAGS) -o $@  $(SRC)/level_a_2.cpp

$(OBJ)/level_a_3.o: $(SRC)/level_a_3.h $(SRC)/level_type_a.h $(SRC)/level_type_a.h $(SRC)/draw_string.h $(SRC)/drawable.h
	$(CXX) $(CXXFLAGS) -o $@  $(SRC)/level_a_3.cpp

$(OBJ)/box.o: $(SRC)/box.h $(SRC)/drawable.h
	$(CXX) $(CXXFLAGS) -o $@  $(SRC)/box.cpp

$(OBJ)/level_type_a.o: $(SRC)/level_type_a.h $(SRC)/level.h $(SRC)/draw_string.h $(SRC)/window.h $(SRC)/paddle.h
	$(CXX) $(CXXFLAGS) -o $@  $(SRC)/level_type_a.cpp

$(OBJ)/ball.o:$(SRC)/ball.cpp $(SRC)/ball.h $(SRC)/drawable.h
	$(CXX) $(CXXFLAGS) -o $@  $(SRC)/ball.cpp
	
$(OBJ)/paddle.o:$(SRC)/paddle.cpp $(SRC)/paddle.h $(SRC)/box.h
	$(CXX) $(CXXFLAGS) -o $@  $(SRC)/paddle.cpp