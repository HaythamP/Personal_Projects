#include "LethalTile.h"
#include "Tile.h"
#include "Threat.h"

//Function 1
LethalTile::LethalTile(int x,int y):Tile(x,y,false,false,'#'),Threat(200){}
//Function 2
void LethalTile::addPlayer(Player* player){
    Tile::addPlayer(player);
    harmPlayer(player);
    if(player->getHealth()==0){
        removePlayer();
    }
}
//Function 3
int LethalTile::getDamage(){
    return damage;
}
//Function 4
bool LethalTile::harmPlayer(Player* player){
   return player->takeDamage(this);
}