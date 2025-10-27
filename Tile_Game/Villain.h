#ifndef VILLAIN_H
#define VILLAIN_H
#include "Player.h"
#include "Threat.h"

class Villain: public Player,public Threat{
private:
    int numRocks;
public:
    Villain(const std::string& username,int health,int numRocks);
    std::string toString() const;
    void interact(Player* otherPlayer);
    int getDamage();
    bool harmPlayer(Player* player);


};

#endif