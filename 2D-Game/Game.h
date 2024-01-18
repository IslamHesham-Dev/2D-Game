
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "Rifle.h"
#include "Pistol.h"
#include "Object.h"
#include "Potion.h"
#include "Ammo.h"
#include "TankMonster.h"
#include "GhostMonster.h"
#include "DemolitionHero.h"
#include "Bazooka.h"
#include "MedicHero.h"

using namespace std;

#ifndef GAME_GAME_H
#define GAME_GAME_H
// Game class
struct Location {
    int posX,posY;
    Location():posX(0),posY(0){};
    Location(int x , int y ) : posX(x),posY(y){}
};


class Game  {
private:
    static const int rows = 15;
    static const int cols = 15;

    Hero* hero;
    Gun* gun1;
    Gun* gun2 ;


public:
    static int round ;
    Object* grid[rows][cols];

    Game() {
        hero = nullptr;
        // Initialize grid with empty objects
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                grid[i][j] = new Object('.');
            }
        }
    }

    ~Game() {
        // Deallocate memory for grid objects
        delete hero;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                delete grid[i][j];
            }
        }
        // Deallocate memory for hero object

    }




    Location checkLocation (Location oldLoc ,Location newLoc ){
        int  x = newLoc.posX , y = newLoc.posY;
        if (x>=0 && x< rows && y>=0 && y<cols){
            if(grid[x][y]->getType()=='.')
                return newLoc;

            else if (grid[x][y]->getType()=='T'||grid[x][y]->getType()=='G') {
                *hero - (*(Monster *) grid[x][y]);
                cout << *(Monster *) grid[x][y];
                return oldLoc;
            }
            else if (grid[x][y]->getType()=='P')
                *hero + (*(Potion *) grid[x][y]);

            else if (grid[x][y]->getType()=='A')
                *hero + (*(Ammo *) grid[x][y]);

            return newLoc;

        }
        else
            cout << "Out of Bounds !!" << endl ;
        return oldLoc;
    }



    void move (Hero& h , char direction){
        Location heroLoc (h.getPositionX(),h.getPositionY());
        Location moveLoc;
        switch (direction) {
            case 'w':
                moveLoc =checkLocation(heroLoc,Location(heroLoc.posX-1,heroLoc.posY));
                break;
            case 'a':
                moveLoc =checkLocation(heroLoc,Location(heroLoc.posX,heroLoc.posY-1));
                break;
            case 's':
                moveLoc =checkLocation(heroLoc,Location(heroLoc.posX+1,heroLoc.posY));
                break;
            case 'd':
                moveLoc =checkLocation(heroLoc,Location(heroLoc.posX,heroLoc.posY+1));
                break;
            default:
                break;
        }
        Hero* tmp = &h ;
        grid[tmp->getPositionX()][tmp->getPositionY()] = new Object('.');
        grid[moveLoc.posX][moveLoc.posY] = tmp ;
        h = *tmp ;
        tmp = nullptr;
        h.setPosition(moveLoc.posX,moveLoc.posY);

    }
    void generateMap() {
        srand(time(0));

        // Generate health potions
        for (int i = 0; i < 5; i++) {
            int healingAmount = rand() % 41 + 10;  // Random number between 10 and 50
            grid[rand() % rows][rand() % cols] = new Potion(healingAmount);
        }

        // Generate ammo
        for (int i = 0; i < 10; i++) {
            int bullets = rand() % 16 + 5;  // Random number between 5 and 20
            grid[rand() % rows][rand() % cols] = new Ammo(bullets);
        }

        // Generate monsters

        int monsterCount = 5;
        int monsterHPRange = 10;
        int monsterHPMin = 60;

        for (int j = 0; j < monsterCount; j++) {
            int hp = (rand() % monsterHPRange + 1) * monsterHPMin;  // Random multiple of 10 between 60 and 150
            grid[rand() % rows][rand() % cols] = new TankMonster('T', 0, 0, hp,hp);
        }

        for (int j = 0; j < monsterCount; j++) {
            int hp = (rand() % monsterHPRange + 1) * monsterHPMin;  // Random multiple of 10 between 60 and 150
            grid[rand() % rows][rand() % cols] = new GhostMonster('G', 0, 0, hp);
        }

    }
    static void clear(){
    #if defined (_WIN32)
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #elif defined (__APPLE__)
        system("clear");
    #endif
    }

    void updateMap(){
        round++;
        int monsterHPRange = 10;
        int monsterHPMin = 60;

        if (checkGameOver()==0){
            clear();
            cout << "Game Over , Your Hero is dead !!" << endl ;
        }
        else if (checkGameOver() == 1){
            clear();
            cout << "You Won !!" << endl ;
        }
        else if (checkGameOver()==-1) {
            clear();
            if(round%20==0){
                int x = rand()%rows;
                int y = rand()%cols;
                int hp = (rand() % monsterHPRange + 1) * monsterHPMin;  // Random multiple of 10 between 60 and 150
                int hp2 = (rand() % monsterHPRange + 1) * monsterHPMin;  // Random multiple of 10 between 60 and 150
                while ( grid[x][y]->getType()!='.') {
                    x = rand()%rows;
                    y = rand()%cols;
                }
                grid[x][y] = new TankMonster('T', 0, 0, hp, hp);
                while ( grid[x][y]->getType()!='.') {
                    x = rand()%rows;
                    y = rand()%cols;
                }
                grid[x][y] = new GhostMonster('G', 0, 0, hp2);

            }
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (grid[i][j]->getType() != '.' || grid[i][j] != nullptr) {
                        if (grid[i][j]->getType() == 'G' || grid[i][j]->getType() == 'T') {
                            if (((Monster *) grid[i][j])->getHealthPoints() <= 0) {
                                delete grid[i][j];
                                grid[i][j] = new Object('.');
                            }
                        }

                    }
                    if (grid[i][j]->getType() == 'G' ) {
                        if (((GhostMonster *) grid[i][j])->isVisibleOnMap() && round % 3 == 0) {
                            if (((GhostMonster *) grid[i][j])->isVisibleOnMap()) {
                                ((GhostMonster *) grid[i][j])->setVisible(false);
                                cout << '.' << "  ";
                            }
                        } else if (((GhostMonster *) grid[i][j])->isVisibleOnMap() ||(!((GhostMonster *) grid[i][j])->isVisibleOnMap())&& round%3!=0) {
                            ((GhostMonster *) grid[i][j])->setVisible(true);
                            cout << grid[i][j]->getType() << "  ";
                        }


                    }

                    if (grid[i][j]->getType() != 'G')
                        cout << grid[i][j]->getType() << "  ";
                }
                cout << endl;
            }


            cout << *hero  << endl;
            cout <<"Round : " <<round << endl;
            cout << "W A S D for movement , F for fire gun , X for special action , G for gun special action , Q to quit "<< endl << "> " ;
        }
    }


    void showMap()  {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << grid[i][j]->getType() << "  ";
            }
            cout << endl;
        }
    }

    int checkGameOver(){
        int monstersCount = 0;
        for(int i = 0 ; i< 15 ; i++){
            for (int j = 0; j < 15; j++) {
                if(grid[i][j]->getType()=='T'||grid[i][j]->getType()=='G')
                    monstersCount++;
            }
        }
        if(hero->getHealthPoints()<=0)
            return 0;

        else if ( monstersCount == 0)
            return 1;

        return -1;

    }

    virtual void fireGun(const char direction ){
        int i = hero->getPositionX();
        int j = hero->getPositionY();
        int range = hero->getCurrentWeapon()->getRange();
        switch (direction) {
            case 'W':
            case 'w':
                for(;i>=0 && range>0;i--,range--){
                    hero->getCurrentWeapon()->fireGun(grid[i][j]);
                }
                hero->getCurrentWeapon()->setBullets(hero->getCurrentWeapon()->getBullets()-1);
                break;
            case 'S':
            case 's':
                for(;i<15 && range>0;i++,range--){
                    hero->getCurrentWeapon()->fireGun(grid[i][j]);
                }
                hero->getCurrentWeapon()->setBullets(hero->getCurrentWeapon()->getBullets()-1);
                break;
            case 'A':
            case 'a':
                for(;j>=0 && range>0;j--,range--){
                    hero->getCurrentWeapon()->fireGun(grid[i][j]);
                }
                hero->getCurrentWeapon()->setBullets(hero->getCurrentWeapon()->getBullets()-1);
                break;
            case 'D':
            case 'd':
                for(;j<15 && range>0;j++,range--){
                    hero->getCurrentWeapon()->fireGun(grid[i][j]);
                }
                hero->getCurrentWeapon()->setBullets(hero->getCurrentWeapon()->getBullets()-1);
                break;
            default:
                cout << "Invalid Choice" << endl;
                break;
        }

    };

    void useGunSpecial(){
        string curr=hero->getCurrentWeapon()->getName();
        if((curr=="Pistol" && hero->getCurrentWeapon()->getBullets()<4)||(curr=="Bazooka" && hero->getCurrentWeapon()->getBullets()<3)){
            cout << "Insufficient resources !" << endl;
            return;
        }
        hero->getCurrentWeapon()->useSpecial(*hero,grid);
        if(curr=="Pistol")
            hero->getCurrentWeapon()->setBullets(hero->getCurrentWeapon()->getBullets()-4);
        else if(curr=="Rifle")
            hero->getCurrentWeapon()->setBullets(hero->getCurrentWeapon()->getBullets()-3);
        cout << "Gun Special Action used !" << endl ;
    }

    void startGame() {
        int heroType;
        int gunType,gun2type;



        cout << "Please enter 1 to choose Demolition or 2 to choose Medic: ";
        cin >> heroType;

        cout << "Please enter 1 for Pistol, 2 for Bazooka, or 3 for Rifle: ";
        cin >> gunType;

        if (heroType == 1) {
            hero = new DemolitionHero('D', 0, 0, 100);

            cout << "Please specify second weapon , enter 1 for Pistol, 2 for Bazooka, or 3 for Rifle: ";
            cin >> gun2type;
            if (gun2type == 1)
                gun2 = new Pistol();

            else if (gun2type == 2)
                gun2 = new Bazooka();

            else if (gun2type == 3)
                gun2 = new Rifle();


        } else if (heroType == 2) {
            hero = new MedicHero('M', 0, 0, 100,50);

        }
        if (gunType == 1)
            gun1 = new Pistol();

        else if (gunType == 2)
            gun1 = new Bazooka();

        else if (gunType == 3)
            gun1 = new Rifle();

        hero->setWeapon(gun1);
        hero->setWeaponTwo(gun2);

        generateMap();
        grid[0][0] = hero;
        updateMap();
//        showMap();
        char input ;
        while (checkGameOver()==-1){
            cin>> input;
            switch(input){
                case 'w' :
                case 'a':
                case 's':
                case 'd' :
                case 'W' :
                case 'A':
                case 'S':
                case 'D' :
                    move(*hero,input);
                    updateMap();
                    break;
                case 'q':
                case 'Q':
                    exit(0);
                case 'f':
                case 'F':
                    cout << "Which Direction : "<< endl;
                    cin >> input;
                    switch(input){
                        case 'w':
                        case 'a':
                        case 's':
                        case 'd' :
                        case 'W' :
                        case 'A':
                        case 'S':
                        case 'D' :
                            fireGun(input);
                            break;
                        default:
                            break;
                    }
                    updateMap();
                    break;
                case 'x':
                case 'X':
                    hero->useSpecial();
                    updateMap();
                    break;
                case 'g':
                case 'G':
                    useGunSpecial();
                    updateMap();
                    break;
                default:
                    cout << "Invalid key";
                    break;
            }
        }
    }


};


#endif //GAME_GAME_H
