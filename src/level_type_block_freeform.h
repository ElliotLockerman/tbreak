#include "level_abstract_block.h"


class Level_type_block_freeform : public Level_abstract_block
{
private:
    
public:
    Level_type_block_freeform(int points_for_life, int lives, int score, Json::Value config);
    
    Level_type_block_freeform(const Level_type_block_freeform&) = delete;

    static bool verify_level_json(Json::Value level_json);
};