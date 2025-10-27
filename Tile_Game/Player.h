#ifndef PLAYER_H
#define PLAYER_H
#include <string>

using namespace std;
// PLEASE DO NOT ALTER THE NEXT LINE
class Threat;

class Player {
private:
    std::string username;
    int health;
    int x;
    int y;
public:
    static int numAlivePlayers;
    Player(const std::string& username,int health);
    virtual ~Player();
    std::string getUsername() const;
    int getHealth() const;
    int getX() const;
    int getY() const;
    void setPosition(int x, int y);
    virtual std::string toString() const;
    virtual void interact(Player* otherPlayer)=0;
    virtual bool takeDamage(Threat* threat);
};


#endif //PLAYER_H