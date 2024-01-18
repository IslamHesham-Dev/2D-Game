
#include <iostream>
#include "Object.h"
using namespace std;

#ifndef GAME_ITEM_H
#define GAME_ITEM_H
// Item class
class Item : public Object {
public:
    Item(char t) : Object(t) {}
};

#endif //GAME_ITEM_H
