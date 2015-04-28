# Terminal Breakout (termbreak)

Terminal Breakout is a Breakout clone that runs entirely in the terminal!


![Screenshot 1](https://raw.githubusercontent.com/ElliotLockerman/termbreak/master/img/img1.png)
![Screenshot 2](https://raw.githubusercontent.com/ElliotLockerman/termbreak/master/img/img2.png)


## Installation

### Dependencies

Termbreak requires [Termbox](https://github.com/nsf/termbox) and [SFML 2](http://www.sfml-dev.org/) to be installed first.  
Included with Termbreak is [jsoncpp](https://github.com/open-source-parsers/jsoncpp).

### Build and Install

Simply run

    make
    sudo make install

The default compiler is clang++/llvm; you can use g++ with CXX=g++
The default prefix is `/usr/local`; you can also set it manually with `prefix=your-prefix`


## Running

### Starting

The default level pack can be played by running `termbreak`.  
To run a level pack, specify the path to the pack as the first argument. See level_packs.md for information on making your own levels.   

### Controls

Space: Start/Launch new ball   
Left/Right Arrows: Move paddle  
p: Pause  
ESC: Quit