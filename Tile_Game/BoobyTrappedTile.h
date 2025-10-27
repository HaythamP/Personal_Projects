#ifndef BOOBYTRAPPEDTILE_H
#define BOOBYTRAPPEDTILE_H
#include "Tile.h"
#include "Threat.h"

class BoobyTrappedTile:public Tile, public Threat{
    private:
        int damageReduction;
    public:
        BoobyTrappedTile(int x,int y,int damage);
        void addPlayer(Player* player);
        int getDamage();
        bool harmPlayer(Player* player);

};

#endif