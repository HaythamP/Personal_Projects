#include "Tile.h"
#include "TileException.h"

//Function 1
Tile::Tile(int x,int y,bool isStart,bool isEnd,char symbol){
    this->x=x;
    this->y=y;
    this->isStart=isStart;
    this->isEnd=isEnd;
    this->symbol=symbol;
    if(isStart){
        this->symbol='s';
    }
    this->player=NULL;
}
//Function 2
Tile::~Tile(){
    delete player;
    
}
//Function 3
char Tile::getSymbol() const{
    return symbol;
}
//Function 4
int Tile::getX() const{
    return x;
}
//Function 5
int Tile::getY() const{
    return y;
}
//Function 6
bool Tile::getIsStart() const{
    return isStart;
}
//Function 7
bool Tile::getIsEnd() const{
    return isEnd;
}
//Function 8
Player* Tile::getPlayer() const{
    return player;
}
//Function 9
void Tile::addPlayer(Player* player){
    if(player==NULL){
        throw TileException("Player is NULL");
    }
    if(this->player!=NULL){
        throw TileException("Tile is occupied");
    }
    this->player=player;
    player->setPosition(x,y);


}
//Function 10
void Tile::removePlayer(){
    this->player=NULL;
}
//Function 11
char Tile::toChar() const{
    if(this->player==NULL){
        return symbol;
    }
    return player->getUsername()[0];
}