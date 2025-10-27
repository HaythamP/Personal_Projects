#include "Player.h"
#include <iostream>
#include <string>
#include "Threat.h"
#include <sstream>
int Player::numAlivePlayers=0;
    //Function 1
    Player::Player(const std::string& username,int health){
        this->username=username;
        this->x=-1;
        this->y=-1;
        if(health<0){
            this->health=50;
        }else if(health>100){
            this->health=100;
        }else{
            this->health=health;
        }
        numAlivePlayers++;
    }
    //Function 2
    Player::~Player(){}


    //Function 3
    std::string Player::getUsername() const{
        return username;
    }
    //Function 4
    int Player::getHealth() const{
        return health;
    }
    //Function 5
    int Player::getX() const{
        return x;
    }
    //Function 6
    int Player::getY() const{
            return y;
    }
    //Function 7
    void Player::setPosition(int x, int y){
        this->x=x;
        this->y=y;
    }
    //Function 8
    std::string Player::toString() const{
       std::stringstream ss;
       ss<<"Username: "<<username<<std::endl;
       ss<<"Health: "<<health<<std::endl;
       ss<<"Position: ("<<x<<","<<y<<")"<<std::endl;
        return ss.str();
    }
    //Function 10
    bool Player::takeDamage(Threat* threat){
        if(threat==NULL){
            return false;
        }
        int damage=threat->getDamage();
        health=health-damage;

        if(health<0){
            health=0;
        }
        if(health==0){
            std::cout<<username<<" has perished"<<std::endl;
            numAlivePlayers--;
            return true;
        }else{
            std::cout<<username<<" took "<<damage<<" damage and now has "<< health<<" health"<<std::endl;
            return false;
        }
    }