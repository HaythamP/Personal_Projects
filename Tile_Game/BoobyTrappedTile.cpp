#include "BoobyTrappedTile.h"
#include "Tile.h"
#include "Threat.h"
#include "TileException.h"

//Function 1
BoobyTrappedTile::BoobyTrappedTile(int x,int y,int damage):Tile(x,y,false,false,'x'),Threat(damage){
    damageReduction=0;
}
//Function 2
void BoobyTrappedTile::addPlayer(Player* player) {
    try
    {
        Tile::addPlayer(player);
        harmPlayer(player);
        
        if(player->getHealth()==0){
            removePlayer();
        }

    }
    catch(TileException& e)
    {
        std::cout<<"Failed to harm player"<<std::endl;
    }
    
}

    
//Function 3
int BoobyTrappedTile::getDamage(){
    int out;
    out=damage-damageReduction;
    damageReduction=damageReduction+10;
    return out;

}
//Function 4
bool BoobyTrappedTile::harmPlayer(Player* player){
    
return player->takeDamage(this);
}