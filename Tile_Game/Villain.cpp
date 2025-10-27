#include "Villain.h"
#include <sstream>

//Function 1
Villain::Villain(const std::string& username,int health,int numRocks):Player(username,health),Threat(10){
    this->numRocks=numRocks;
}
//Function 2
std::string Villain::toString() const{
    std::stringstream ss;
    
    ss<<Player::toString()<<"Rocks: "<<numRocks<<"\nDamage: "<<damage<<std::endl;
    
    
    return ss.str();
}
//Function 3
void Villain::interact(Player* otherPlayer){
    if(otherPlayer==NULL||otherPlayer==this){
        return;
    }
    harmPlayer(otherPlayer);

}
//Function 4
int Villain::getDamage(){
    return damage;
}
//Function 5
bool Villain::harmPlayer(Player* player){
   if(player->getHealth()<=10||numRocks<=0){
    return false;
   }
   numRocks--;
   return player->takeDamage(this);

}