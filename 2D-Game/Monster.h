//
// Created by Abdul Rahman on 12/12/2023.
//
#include <iostream>
#include "Character.h"

using namespace std;

#ifndef GAME_MONSTER_H
#define GAME_MONSTER_H
#include "Gun.h"
// Monster class
class Gun;
class Monster : public Character {
public:
    Monster(char t, int x, int y, int hp) : Character(t, x, y, hp) {}
    friend ostream& operator<< (ostream& os , Monster& m){
        string monType = m.type=='T' ? "Tank Monster" : "Ghost Monster" ;
        return os << monType << endl << "HP : " << m.getHealthPoints() << endl;
    };

};
#endif //GAME_MONSTER_H
