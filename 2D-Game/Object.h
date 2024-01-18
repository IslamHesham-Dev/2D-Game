
#include <iostream>
using namespace std;

#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
// Object class
class Object {
protected:
    char type;
public:
    Object(char t) : type(t) {}

    char getType() const {
        return type;
    }
    friend ostream& operator<< (ostream& os ,Object& o ){
        os << "Type : "<< o.type << endl  ;
        return os ;
    }
};
#endif //GAME_OBJECT_H
