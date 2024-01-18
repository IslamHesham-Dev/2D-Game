
#include <iostream>
#include "Object.h"
using namespace std;

#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H
// Character class
class Character : public Object {
protected:
    int positionX;
    int positionY;
    int healthPoints;
public:
    Character(char t, int x, int y, int hp) : Object(t), positionX(x), positionY(y), healthPoints(hp) {}

    const int getPositionX()  {
        return positionX;
    }

    const int getPositionY()  {
        return positionY;
    }

    int getHealthPoints()  {
        return healthPoints;
    }

    void setPosition(int x, int y) {
        positionX = x;
        positionY = y;
    }

    void setHealthPoints(int hp) {
        healthPoints = hp;
    }
};

#endif //GAME_CHARACTER_H
