#include "EndTile.h"
#include "Tile.h"
#include <iostream>
#include <string>
//Function 1
EndTile::EndTile(int x,int y):Tile(x,y,false,true,'e'){}
//Function 2
EndTile::~EndTile(){
}
//Function 3
void EndTile::addPlayer(Player* player){
    Tile::addPlayer(player);
    player->setPosition(-1,-1);
    std::cout<<player->getUsername()<<" has escaped"<<std::endl;
    this->player=NULL;
}
//Function 4
char EndTile::toChar() const{
    return getSymbol();
}