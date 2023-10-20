#include "ship.h"

Ship::Ship()
{
    for (int i = 0; i < 4; i++){
        this->ship.hr[i] = 5 + i*2;
        int k = 0;
        do{
            this ->ship.hr[i] -= 24;
            k++;
        }while(this->ship.hr[i] >= 24);
        this->ship.min[i] = i + 7;
        this->ship.period[i] = 10;
    }
    this->ship.name[0] = "Ticktonick";
    this->ship.name[1] = "Crimson Heart";
    this->ship.name[2] = "Dead Island";
    this->ship.name[3] = "Iceburg";
}
