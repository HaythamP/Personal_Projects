#ifndef ARENA_H
#define ARENA_H
#include <string>

using namespace std;
// PLEASE DO NOT ALTER THE NEXT 2 LINES
class Tile;
class Player;

class Arena {
private:
    int size,startX,startY,endX,endY,numPlayers;
    Tile*** tiles;
    Player** players;

public:
Arena(const string& arenaFileName);
~Arena();
int getSize() const;
int getNumPlayers() const;
bool isValidPosition(int x,int y) const;
void addPlayer(Player* newPlayer);
void movePlayer(Player* player,const string& direction);
void print() const;
};


#endif //ARENA_H