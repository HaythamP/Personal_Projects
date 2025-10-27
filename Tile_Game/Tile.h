#ifndef TILE_H
#define TILE_H
#include "Player.h"
class Tile{
    private:
        int x,y;
        bool isStart,isEnd;
        char symbol;
    protected:
        Player* player;
    public:
        Tile(int x,int y,bool isStart=false,bool isEnd=false,char symbol='+');
        virtual ~Tile();
        char getSymbol() const;
        int getX() const;
        int getY() const;
        bool getIsStart() const;
        bool getIsEnd() const;
        Player* getPlayer() const;
        virtual void addPlayer(Player* player);
        virtual void removePlayer();
        virtual char toChar() const;
};



#endif