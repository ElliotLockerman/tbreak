#include "termbox.h"

#include "box.h"


// ********************************************************
// Constructors 

// Border only
Box::Box(int x, int y, int width, int height, int border_thickness, uint32_t ch, uint16_t fg, uint16_t bg)
{
	// TODO: Bounds checking
	
	if(border_thickness < 1) border_thickness = 1;

	has_border = true;
	has_center = false;
	
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->border_thickness = border_thickness;
	
	this->border_wrap.cell.ch = ch;
	this->border_wrap.cell.fg = fg;
	this->border_wrap.cell.bg = bg;

	
	initialize_matrix();
}


// Center only
Box::Box(int x, int y, int width, int height, uint32_t cch, uint16_t cfg, uint16_t cbg)
{
	// TODO: Bounds checking
	
	has_border = false;
	has_center = true;
	
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	
	this->center_wrap.cell.ch = cch;
	this->center_wrap.cell.fg = cfg;
	this->center_wrap.cell.bg = cbg;
	
	
	initialize_matrix();
}



// Border and center
Box::Box(int x, int y, int width, int height, int border_thickness, uint32_t bch, uint16_t bfg, uint16_t bbg, uint32_t cch, uint16_t cfg, uint16_t cbg)
{
	// TODO: Bounds checking
	
	if(border_thickness > 0)
	{
		has_border = true;
		this->border_thickness = border_thickness;
	}
	
	has_center = true;
	
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	
	this->center_wrap.cell.ch = cch;
	this->center_wrap.cell.fg = cfg;
	this->center_wrap.cell.bg = cbg;
	
	
	this->border_wrap.cell.ch = bch;
	this->border_wrap.cell.fg = bfg;
	this->border_wrap.cell.bg = bbg;
	
	
	initialize_matrix();
}

// End constructors
// ********************************************************



void Box::initialize_matrix()
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
	
	
	std::vector<char_wrap*> inner(height, &empty_wrap);
	matrix.assign(width, inner);
	

	if(has_center)
	{
		for(int i = 0; i < width; i++)
			for(int j = 0; j < height; j++)
				matrix[i][j] = &center_wrap;
	}
	if(has_border)
	{
		//Top border
		for(int i = 0; i < width; i++)
			for(int j = 0; j < border_thickness; j++)
				matrix[i][j] = &border_wrap;
		

		//Bottom border
		for(int i = 0; i < width; i++)
			for(int j = 0; j < border_thickness; j++)
				matrix[i][height - 1 - j] = &border_wrap;
			

		// Left border
		for(int i = 0; i < height; i++)
			for(int j = 0; j < border_thickness; j++)
				matrix[j][i] = &border_wrap;
					

		//Right border
		for(int i = 0; i < height; i++)
			for(int j = 0; j < border_thickness; j++)
				matrix[width - 1 - j][i] = &border_wrap;
	}
		
}




void Box::replace_char(int x, int y, uint32_t ch, uint16_t fg, uint16_t bg)
{
	if(x < width && x >= 0 && y < height && y >= 0)
	{
		tb_cell new_cell =
		{
			.ch = ch,
			.fg = fg,
			.bg = bg
		};
	
		char_wrap new_special_wrap = 
		{			
			.cell = new_cell,
			.empty = false
		};
	
		specials.push_back(new_special_wrap);
	
		matrix[x][y] = &specials.back();
	}
	
}



void Box::remove_char(int x, int y)
{
	if(x < width && x >= 0 && y < height && y >= 0)
		matrix[x][y] = &empty_wrap;
}





// ********************************************************
// Drawable methods

void Box::draw()
{
	
	// Draw center
	if(has_center)
	{
		for(int i = 0; i < width; i++)
		{
			for(int j = 0; j < height; j++)
			{
				if(!matrix[i][j]->empty)
				{
					tb_put_cell(x + i, y + j, &(matrix[i][j]->cell));
				}
			}
		}
	}
	// Draw borders, but only if there's no center (the border is inside)
	else if(has_border)
	{
		//Top border
		for(int i = 0; i < width; i++)
		{
			for(int j = 0; j < border_thickness; j++)
			{
				if(!matrix[i][j]->empty)
				{
					tb_put_cell(x + i, y + j, &(matrix[i][j]->cell));
				}
			}
		}



		//Bottom border
		for(int i = 0; i < width; i++)
		{
			for(int j = 0; j < border_thickness; j++)
			{
				if(!matrix[i][height - 1 - j]->empty)
				{
					tb_put_cell(x + i, y + height - 1 - j, &(matrix[i][height - 1 - j]->cell));
				}
			}
		}
			

		// Left border
		for(int i = 0; i < height; i++)
		{
			for(int j = 0; j < border_thickness; j++)
			{
				if(!matrix[j][i]->empty)
				{
					tb_put_cell(x + j, y + i, &(matrix[j][i]->cell));
				}
			}
		}
					

		//Right border
		for(int i = 0; i < height; i++)
		{
			for(int j = 0; j < border_thickness; j++)
			{
				if(!matrix[width - 1 - j][i]->empty)
				{
					tb_put_cell(x + width - 1 - j, y + i, &(matrix[width - 1 - j][i]->cell));
				}
			}
		}
	}
}




bool Box::contains_point(int x, int y)
{
	// Don't want to index out of bounds
	if(x < this->x || x >= this->x + this->width || y < this-> y || y > this->y + this->height)
		return false;
	

	if(!matrix[x - this->x][y - this->y]->empty)
		return true;
	
	return false;
}




void Box::move_to(int x, int y)
{
	this->x = x;
	this->y = y;
	
	return;
}

// End drawables
// ********************************************************
