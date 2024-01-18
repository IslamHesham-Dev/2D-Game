//
// Created by Abdul Rahman on 12/12/2023.
//
#include <iostream>
#include "Gun.h"
#include "Hero.h"
using namespace std;

#ifndef GAME_RIFLE_H
#define GAME_RIFLE_H

class Rifle : public Gun {
public:
    Rifle() : Gun("Rifle", 30, 20, 4) {}
    void useSpecial ( Hero & h,Object* grid[15][15])override{
        int y = h.getPositionY()+1 , yv = h.getPositionY()-1 , x = h.getPositionX()-1 , hz = h.getPositionY() , vt=h.getPositionX() ,r = getRange();
        for(;y<15  && r>0;y++,r--){
            fireGun(grid[vt][y]);
        }
        for(;yv>=0 && r>0;yv--,r--){
            fireGun(grid[vt][yv]);
        }
        for(;x>=0 && r>0;x--,r--){
            fireGun(grid[vt][y]);
        }

    };


};
#endif //GAME_RIFLE_H
