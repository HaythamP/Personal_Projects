#ifndef ENDTILE_H
#define ENDTILE_H
#include "Tile.h"

class EndTile:public Tile{
    public:
        EndTile(int x,int y);
        ~EndTile();
        void addPlayer(Player* player);
        char toChar() const;

};


#endif