#ifndef PACIFIST_H
#define PACIFIST_H
#include "Player.h"
#include <string>
class Pacifist: public Player{
public:
    Pacifist(const std::string& username,int health);
    void interact(Player* otherPlayer);
};

#endif