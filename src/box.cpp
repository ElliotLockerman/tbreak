#include "box.h"


// ********************************************************
// Constructors 

// Border only
Box::Box(int x, int y, int width, int height, int border_thickness, 
    uint32_t ch, uint16_t fg, uint16_t bg)
{
    assert(x >= 0);
    assert(y >= 0);
    assert(x + width <= game_width);
    assert(y + height <= game_height);
    
    if(border_thickness < 1) border_thickness = 1;

    bool has_border = true;
    bool has_center = false;
    
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->border_thickness = border_thickness;
    
    this->border_wrap.cell.ch = ch;
    this->border_wrap.cell.fg = fg;
    this->border_wrap.cell.bg = bg;

    this->border_wrap.empty = false;
    
    initialize_matrix(has_border, has_center);
}


// Center only
Box::Box(int x, int y, int width, int height, 
    uint32_t cch, uint16_t cfg, uint16_t cbg)
{
    assert(x >= 0);
    assert(y >= 0);
    assert(x + width <= tb_width());
    assert(y + height <= tb_height());
    
    bool has_border = false;
    bool has_center = true;
    
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    
    this->center_wrap.cell.ch = cch;
    this->center_wrap.cell.fg = cfg;
    this->center_wrap.cell.bg = cbg;
    
    this->center_wrap.empty = false;
    
    
    initialize_matrix(has_border, has_center);
}



// Border and center
Box::Box(int x, int y, int width, int height, int border_thickness, 
    uint32_t bch, uint16_t bfg, uint16_t bbg, 
    uint32_t cch, uint16_t cfg, uint16_t cbg)
{
    assert(x >= 0);
    assert(y >= 0);
    assert(x + width <= game_width);
    assert(y + height <= game_height);
    
    
    bool has_border = false;
    
    if(border_thickness > 0)
    {
        has_border = true;
        this->border_thickness = border_thickness;
    }
    
    bool has_center = true;
    
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    
    
    this->center_wrap.cell.ch = cch;
    this->center_wrap.cell.fg = cfg;
    this->center_wrap.cell.bg = cbg;
    
    this->center_wrap.empty = false;
    
    
    this->border_wrap.cell.ch = bch;
    this->border_wrap.cell.fg = bfg;
    this->border_wrap.cell.bg = bbg;
    
    this->border_wrap.empty = false;
    
    initialize_matrix(has_border, has_center);
}

// End constructors
// ********************************************************



void Box::initialize_matrix(bool has_border, bool has_center)
{   
    // It should never be printed, but we should have something just in case
    tb_cell empty_cell =
    {
        .ch = ' ',
        .fg = TB_DEFAULT,
        .bg = TB_DEFAULT
    };
    
    empty_wrap.cell = empty_cell;
    empty_wrap.empty = true;
    
    
    std::vector<char_wrap> inner(height, empty_wrap);
    matrix.assign(width, inner);
    

    if(has_center)
    {
        for(int i = 0; i < width; i++)
            for(int j = 0; j < height; j++)
                matrix[i][j] = center_wrap;
    }
    if(has_border)
    {
        //Top border
        for(int i = 0; i < width; i++)
            for(int j = 0; j < border_thickness; j++)
                matrix[i][j] = border_wrap;
        

        //Bottom border
        for(int i = 0; i < width; i++)
            for(int j = 0; j < border_thickness; j++)
                matrix[i][height - 1 - j] = border_wrap;
            

        // Left border
        for(int i = 0; i < height; i++)
            for(int j = 0; j < border_thickness; j++)
                matrix[j][i] = border_wrap;
                    

        //Right border
        for(int i = 0; i < height; i++)
            for(int j = 0; j < border_thickness; j++)
                matrix[width - 1 - j][i] = border_wrap;
    }
        
}




void Box::replace_char(int x, int y, uint32_t ch, uint16_t fg, uint16_t bg)
{
    assert(x >= 0);
    assert(y >= 0);
    assert(x < width);
    assert(y < height);

    tb_cell new_cell =
    {
        .ch = ch,
        .fg = fg,
        .bg = bg
    };

    char_wrap new_wrap = 
    {           
        .cell = new_cell,
        .empty = false
    };
        

    matrix[x][y]= new_wrap;


    
}

void Box::replace_string(int x, int y, int colwidth, std::string str, 
    uint16_t fg, uint16_t bg)
{   
    assert(x >= 0);
    assert(y >= 0);
    assert(x < width);
    assert(y < height);

    if(colwidth <= 0) colwidth = 1;
    if(colwidth > width - x) colwidth = width - x;



    for(int i = 0; i < static_cast<int>(str.length()); i++)
    {           
        tb_cell new_cell =
        {
            .ch = static_cast<uint32_t>(str[i]),
            .fg = fg,
            .bg = bg
        };

        char_wrap new_wrap = 
        {           
            .cell = new_cell,
            .empty = false
        };


        assert(x + (i % colwidth) < width);
        assert(y + (i / colwidth) < height);


        matrix[x + (i % colwidth)][y + (i / colwidth)] = new_wrap;          
    }
    
    
}


void Box::remove_char(int x, int y)
{
    assert(x >= 0);
    assert(y >= 0);
    assert(x < width);
    assert(y < height);

    matrix[x][y] = empty_wrap;

}





// ********************************************************
// Drawable methods

void Box::draw()
{
    
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            if(!matrix[i][j].empty)
            {
                tb_put_cell(x + i, y + j, &(matrix[i][j].cell));
            }
        }
    }

}




bool Box::contains_point(int x, int y)
{
    if(x < this->x || x >= this->x + this->width 
        || y < this-> y || y >= this->y + this->height)
        return false;
    

    if(!matrix[x - this->x][y - this->y].empty)
        return true;
    
    return false;
}




void Box::move_to(int x, int y)
{
    assert(x >= 0);
    assert(y >= 0);
    assert(x + width <= game_width);
    assert(y + height <= game_height);
    
    this->x = x;
    this->y = y;
    
    return;
}

int Box::get_x(){return x;};

int Box::get_y(){return y;};


// End drawables
// ********************************************************
