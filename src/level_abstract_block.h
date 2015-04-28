#include <string>

#include "termbox.h"
#include <SFML/Window/Keyboard.hpp>
#include "../external/jsoncpp/json/json.h"

#include "level.h"
#include "draw_string.h"
#include "window.h"
#include "block.h"

#pragma once




class Level_abstract_block : public Level
{
private:
    

    
protected:
    
    std::list<std::shared_ptr<Block> > blocks;
    std::list<std::shared_ptr<Block> >::iterator blocks_it;
    
    std::set<std::shared_ptr<Block> > hit_blocks;
    std::set<std::shared_ptr<Block> >::iterator hit_it;
        
    
    
    
    using Level::will_collide;
    virtual bool will_collide(std::shared_ptr<Drawable> object, int x, int y);
    
    using Level::delete_hit;
    virtual void delete_hit();
    
    void draw_data();
    
public:     
    
    using Level::run;
    virtual Level_status run(); 
    
    
};