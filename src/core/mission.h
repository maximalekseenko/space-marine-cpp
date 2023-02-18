#pragma once

#include "attrclass.h"
#include "entity.h"
#include "tile.h"

#include <vector>



class mission : attrClass{
    private:
        int free_entity_id = 0;
        int free_tile_id = 0;
        std::vector<entity> entities;
        std::vector<tile> tiles;
    public:

        void New_Entity();
        entity* Get_Entity(int __id);
        void Rem_Entity(int __id);

        void New_Tile();
        tile* Get_Tile(int __id);
        void Rem_Tile(int __id);

        mission* Load();
};