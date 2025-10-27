#ifndef LETHALTILE_H
#define LETHALTILE_H
#include "Tile.h"
#include "Threat.h"

class LethalTile:public Tile, public Threat{
    
    public:
        LethalTile(int x,int y);
        void addPlayer(Player* player);
        int getDamage();
        bool harmPlayer(Player* player);

};

#endif