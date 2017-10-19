CXX = clang++
CXXFLAGS = -c -Wall -std=c++11 -O2 -I /usr/local/include
LDFLAGS = -L /usr/local/lib -ltermbox -lsfml-window

SRC = src
OBJ = obj
EXT = external
PREFIX ?= /usr/local

EXECUTABLE = termbreak



OBJS = $(OBJ)/main.o $(OBJ)/ball.o $(OBJ)/box.o $(OBJ)/draw_string.o $(OBJ)/game_main.o $(OBJ)/level_type_block_grid.o $(OBJ)/level_abstract_block.o $(OBJ)/level_type_block_freeform.o $(OBJ)/paddle.o $(OBJ)/utility.o $(OBJ)/window.o $(OBJ)/jsoncpp.o

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





$(OBJ)/main.o: $(SRC)/main.cpp $(SRC)/game_main.h $(SRC)/utility.h $(SRC)/default_levels.h $(SRC)/level.h
	$(CXX) $(CXXFLAGS) -o $@ $<

$(OBJ)/game_main.o: $(SRC)/game_main.cpp $(SRC)/game_main.h $(SRC)/constants.h $(SRC)/draw_string.h $(SRC)/utility.h  $(SRC)/window.h
	$(CXX) $(CXXFLAGS) -o $@  $<

$(OBJ)/draw_string.o: $(SRC)/draw_string.cpp $(SRC)/draw_string.h $(SRC)/constants.h
	$(CXX) $(CXXFLAGS) -o $@  $<

$(OBJ)/utility.o: $(SRC)/utility.cpp $(SRC)/utility.h $(SRC)/window.h
	$(CXX) $(CXXFLAGS) -o $@ $<

$(OBJ)/window.o: $(SRC)/window.cpp $(SRC)/window.h $(SRC)/box.h $(SRC)/constants.h
	$(CXX) $(CXXFLAGS) -o $@ $<

$(OBJ)/box.o: $(SRC)/box.cpp $(SRC)/box.h $(SRC)/drawable.h $(SRC)/constants.h
	$(CXX) $(CXXFLAGS) -o $@ $<

$(OBJ)/level_abstract_block.o: $(SRC)/level_abstract_block.cpp $(SRC)/level_abstract_block.h $(SRC)/constants.h $(SRC)/level.h $(SRC)/draw_string.h $(SRC)/window.h $(SRC)/paddle.h $(SRC)/utility.h
	$(CXX) $(CXXFLAGS) -o $@ $<

$(OBJ)/level_type_block_grid.o: $(SRC)/level_type_block_grid.cpp $(SRC)/level_type_block_grid.h $(SRC)/level_abstract_block.h $(SRC)/constants.h $(SRC)/level.h $(SRC)/draw_string.h $(SRC)/window.h $(SRC)/paddle.h $(SRC)/utility.h
	$(CXX) $(CXXFLAGS) -o $@ $<
	
$(OBJ)/level_type_block_freeform.o: $(SRC)/level_type_block_freeform.cpp $(SRC)/level_type_block_freeform.h $(SRC)/level_abstract_block.h $(SRC)/constants.h $(SRC)/level.h $(SRC)/draw_string.h $(SRC)/window.h $(SRC)/paddle.h $(SRC)/utility.h
	$(CXX) $(CXXFLAGS) -o $@ $<

$(OBJ)/ball.o: $(SRC)/ball.cpp $(SRC)/ball.h $(SRC)/drawable.h
	$(CXX) $(CXXFLAGS) -o $@ $<
	
$(OBJ)/paddle.o: $(SRC)/paddle.cpp $(SRC)/paddle.h $(SRC)/box.h
	$(CXX) $(CXXFLAGS) -o $@ $<
	



$(OBJ)/jsoncpp.o: $(EXT)/jsoncpp/jsoncpp.cpp $(EXT)/jsoncpp/json/json.h $(EXT)/jsoncpp/json/json-forwards.h
	$(CXX) $(CXXFLAGS) -o $@ $<