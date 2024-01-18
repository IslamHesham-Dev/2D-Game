//
// Created by Abdul Rahman on 12/12/2023.
//


#ifndef GAME_GUN_H
#define GAME_GUN_H
#include <iostream>
#include "Object.h"
#include "Monster.h"

using namespace std;

class Hero ;
class Monster;
class Gun  {
private:
    string name;
    int bullets;
    int damage;
    int range;

public:
    Gun( string n, int b, int d, int r) : name(n), bullets(b), damage(d), range(r) {}

    friend ostream& operator<< (ostream& os , Gun& g );


    string getName() {
        return name;
    }



    int getBullets()  {
        return bullets;
    }
    void setBullets(int b){
        bullets = b;
    }

    const int getDamage()  {
        return damage;
    }

    int getRange()  {
        return range;
    }
    virtual void useSpecial ( Hero & h,Object* grid[15][15]){};

    virtual void fireGun(Object* o){
        if (o->getType()=='T'||o->getType()=='G') {
            string nameM ;
            if(o->getType()=='T')
                nameM = "Tank Monster";
            else
                nameM = "Ghost Monster";
            cout << nameM << " health : " << ((Character* )o)->getHealthPoints() << endl;
            ((Character* )o)->setHealthPoints(((Character* )o)->getHealthPoints()-damage);
            cout << "Target hit with damage " << damage << " , Health : " << ((Character* )o)->getHealthPoints() << endl ;
        }
    };


};
ostream& operator<< (ostream& os , Gun& g ){
    os << "Name : "<< g.getName() << endl << "     Range : " << g.getRange() << endl << "     No. of Bullets : " << g.getBullets() << endl << "     Damage : " << g.getDamage() << endl ;
    return os ;
}


#endif //GAME_GUN_H
