#include "Arena.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "Tile.h"
#include "BoobyTrappedTile.h"
#include "LethalTile.h"
#include "TileException.h"
#include "EndTile.h"
//Function 1
Arena::Arena(const std::string& arenaFileName){
    std::ifstream input(arenaFileName.c_str());
    std::string line;
    std::getline(input,line);
    std::stringstream ss(line);
    ss>>size;
    tiles=new Tile**[size];
    numPlayers=0;
    players=new Player*[0];
    for (int i = 0; i < size; i++)
    {
        tiles[i]=new Tile*[size];
        std::getline(input,line);
        for(int j=0;j<size;j++){
            char c=line[j];

            if(c=='s'){
                startX=i;
                startY=j;
                tiles[i][j]=new Tile(i,j,true,false,'s');

            }else if(c=='e'){
                endX=i;
                endY=j;
                tiles[i][j]=new EndTile(i,j);
            }else if(c=='x'){
                tiles[i][j]=new BoobyTrappedTile(i,j,20);

            }else if(c=='#'){
                tiles[i][j]= new LethalTile(i,j);


            }else{

                tiles[i][j]=new Tile(i,j,false,false,'+');
            }
        }
    }
    
    input.close();
}

//Function 2
Arena::~Arena(){
    if(tiles!=NULL){
        for (int i = 0; i < size; i++)
    {
        for(int j=0;j<size;j++){
           tiles[i][j]->removePlayer();
        }
        
    }
    }

    if(players != NULL)
    {
        for(int i=0;i<numPlayers;i++)
        {
            delete players[i];
        }
        delete[] players;
    }
    if(tiles != NULL)
    {
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                delete tiles[i][j];
            }
            delete[] tiles[i];
        }
        delete[] tiles;
    }
    
    
}
//Function 3
int Arena::getSize() const{
    return size;
}
//Function 4
int Arena::getNumPlayers() const{
    int count=0;
    for(int i=0;i<numPlayers;i++){
        if(players[i]->getHealth()>0&&players[i]->getX()>=0){
            count++;
        }
    }
    return count;
}
//Function 5
bool Arena::isValidPosition(int x,int y) const{
    return (x>=0&&x<size&&y>=0&&y<size);
}
//Function 6
void Arena::addPlayer(Player* newPlayer){

    if(newPlayer==NULL||newPlayer->getX()!=-1){
        return;
    }
    try
    {
        tiles[startX][startY]->addPlayer(newPlayer);
        Player** temp=new Player*[numPlayers+1];
        for(int i=0;i<numPlayers;i++){
            temp[i]=players[i];
        }
        temp[numPlayers]=newPlayer;
        delete[] players;
        players=temp;
        numPlayers++;
    }
    catch(TileException e)
    {
        std::cout<<e.getMessage()<<std::endl;
    }
    

}
//Function 7
void Arena::movePlayer(Player* player,const string& direction){
    if (player==NULL||player->getX()==-1)
    {
        return;
    }
    
    int xNew=player->getX();
    int yNew=player->getY();



        if (direction == "up"){
        xNew--;
    }
        else if (direction == "down") {
            xNew++;
        }else if (direction == "left") {
            yNew--;
        }else if (direction == "right") {
            yNew++;
        }
        else {
            return;
        }

      if(!isValidPosition(xNew,yNew)){
       std::cout<<"Invalid Position"<<std::endl;
       return;
        
      }
      Tile* oldTile=tiles[player->getX()][player->getY()];
      try
      {
        oldTile->removePlayer();
        tiles[xNew][yNew]->addPlayer(player);
      }
      catch(TileException& e)
      {
        std::cout << e.getMessage() <<std::endl;
        oldTile->addPlayer(player);
      }
      


}
//Function 8
void Arena::print() const{
    std::cout<<numPlayers<<" players entered the Arena\n"<<Player::numAlivePlayers<<" alive players\n\n-Player info-\n\n";
    for(int i=0;i<numPlayers;i++){
        
        std::cout<<players[i]->toString();
    }
    for (int i = 0; i < size; i++)
    {
        for(int j=0;j<size;j++){
            std::cout<<tiles[i][j]->toChar();
        }
        std::cout<<std::endl;
    }
    
}