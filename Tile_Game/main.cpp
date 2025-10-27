#include "Villain.h"
#include "Arena.h"
#include "TileException.h"
#include "Pacifist.h"
#include <iostream>
#include <fstream>
int main() {

    Arena arena("arena.txt");
    arena.print();

    Villain* v1 = new Villain("Bob", 80, 5);
    Pacifist* p1 = new Pacifist("Tom", 60);


    arena.addPlayer(v1);
    arena.addPlayer(p1);

    arena.print();
    arena.movePlayer(v1, "up");
    arena.movePlayer(p1, "down");


    arena.print();

    
    return 0;
}
