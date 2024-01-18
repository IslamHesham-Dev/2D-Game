//
// Created by Abdul Rahman on 12/12/2023.
//
#include <iostream>
#include "Gun.h"

using namespace std;

#ifndef GAME_BAZOOKA_H
#define GAME_BAZOOKA_H
class Bazooka : public Gun  {
public:
    Bazooka() : Gun("Bazooka", 4, 150, 8) {}

    void useSpecial (Hero& h , Object* grid[15][15])override{
        int x = h.getPositionX();
        int y = h.getPositionY();
        int count = 0;

        for (int i = x+1, j=y+1 , k = y-1; i<15 && j<15 ; i++,j++,k--) {
            if (grid[i][j]->getType()=='T'||grid[i][j]->getType()=='G') {
                delete grid[i][j];
                grid[i][j] = new Object('.');
                count++;
            }
            if (grid[i][k]->getType()=='T'||grid[i][k]->getType()=='G') {
                delete grid[i][k];
                grid[i][k] = new Object('.');
                count++;
            }
        };
        for (int i = x-1, j=y-1 , k = y+1; i>=0 && j>=0 ; i--,j--,k++) {

            if (grid[i][j]->getType()=='T'||grid[i][j]->getType()=='G') {
                delete grid[i][j];
                grid[i][j] = new Object('.');
                count++;
            }
            if (grid[i][k]->getType()=='T'||grid[i][k]->getType()=='G') {
                delete grid[i][k];
                grid[i][k] = new Object('.');
                count++;
            }

        };
        cout <<count << " Monsters Killed !" << endl ;

    };
};
#endif //GAME_BAZOOKA_H
