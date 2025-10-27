#include "Pacifist.h"
#include "Player.h"
#include <iostream>
#include <string>

Pacifist::Pacifist(const std::string& username,int health):Player(username,health){
}
void Pacifist::interact(Player* otherPlayer){
if(otherPlayer==NULL||otherPlayer==this){
    return;
}
std::cout<<this->getUsername()<<" waved at "<<otherPlayer->getUsername()<<std::endl;

}