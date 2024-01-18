//
// Created by Abdul Rahman on 12/12/2023.
//
#include <iostream>
#include "Item.h"
using namespace std;

#ifndef GAME_AMMO_H
#define GAME_AMMO_H

class Ammo : public Item {
private:
    int bullets;
public:
    Ammo(int b) : Item('A'), bullets(b) {}

    int getBullets() const {
        return bullets;
    }
};

#endif //GAME_AMMO_H
