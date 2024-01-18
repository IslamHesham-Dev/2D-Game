//
// Created by Abdul Rahman on 12/12/2023.
//
#include <iostream>
#include "Item.h"
using namespace std;

#ifndef GAME_POTION_H
#define GAME_POTION_H

class Potion : public Item {
private:
    int healingAmount;
public:
    Potion(int ha) : Item('P'), healingAmount(ha) {}

    int getHealingAmount() const {
        return healingAmount;
    }
};

#endif //GAME_POTION_H
