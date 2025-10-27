#ifndef THREAT_H
#define THREAT_H
#include <iostream>
// PLEASE DO NOT ALTER THE NEXT LINE
class Player;

class Threat {
protected:
    int damage;
public:
    Threat(int damage);
    virtual ~Threat();
    virtual int getDamage()=0;
    virtual bool harmPlayer(Player* player)=0;
};


#endif //THREAT_H