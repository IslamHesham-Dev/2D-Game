//
// Created by Abdul Rahman on 12/12/2023.
//
#include <iostream>
#include "Monster.h"
using namespace std;

#ifndef GAME_TANKMONSTER_H
#define GAME_TANKMONSTER_H
class TankMonster : public Monster  {
private:
    int shield;
public:
    TankMonster(char t, int x, int y, int hp, int s) : Monster(t, x, y, hp), shield(s) {}

    int getShield() const {
        return shield;
    }

};
#endif //GAME_TANKMONSTER_H
