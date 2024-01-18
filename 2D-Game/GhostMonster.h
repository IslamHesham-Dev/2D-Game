//
// Created by Abdul Rahman on 12/12/2023.
//
#include <iostream>
#include "Monster.h"
using namespace std;

#ifndef GAME_GHOSTMONSTER_H
#define GAME_GHOSTMONSTER_H

class GhostMonster : public Monster {
private:
    bool isVisible;
public:
    GhostMonster(char t, int x, int y, int hp) : Monster(t, x, y, hp), isVisible(true) {}

    bool isVisibleOnMap() const {
        return isVisible;
    }
    void setVisible(bool vis){
        isVisible = vis ;
    }
};
#endif //GAME_GHOSTMONSTER_H
