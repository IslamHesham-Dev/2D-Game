
#include <iostream>
#include "Hero.h"
#include "Gun.h"
using namespace std;

#ifndef GAME_MEDIC_H
#define GAME_MEDIC_H

class MedicHero : public Hero {
private:
    int healingAmount;
    bool healed;


public:
    MedicHero(char t, int x, int y, int hp,int ha) : Hero(t, x, y, hp), healingAmount(ha) {
        healed=false;
    }
    void setWeaponTwo(Gun* g) override{}

    int getHealingAmount()  {
        return healingAmount;
    }
    void useSpecial ()override{
        if (!healed) {
            healthPoints += healingAmount;
            healed = true;
        }
        else
            cout<<"Special ability already used !"<<endl;
    }
    virtual ostream& getInfo( ostream& os  ) override{
        return  os << "Hero type : "<< type << endl << "Location : [ X : " << positionX << " , Y : " << positionY << " ]\nHP : " << healthPoints << endl << "Healing amount : " << healingAmount  << endl << "Gun : " << endl << *weapon << endl ;
    };


};
ostream& operator<< (ostream& os , MedicHero& h){
    return h.getInfo(os);
};

#endif //GAME_MEDIC_H
