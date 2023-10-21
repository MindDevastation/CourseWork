#include "ship.h"

Ship::Ship()
{
    for (int i = 0; i < 4; i++){
        this->ship.setHr(i, 5 + i*2) ;
        int k = 0;
        do{
            this ->ship.setHr(i, this->ship.getHr(i) - 24);
            k++;
        }while(this->ship.getHr(i) >= 24);
        this->ship.setMin(i, i + 2);
        this->ship.setPeriod(i, 5);
    }
    this->ship.name[0] = "Ticktonick";
    this->ship.name[1] = "Crimson Heart";
    this->ship.name[2] = "Dead Island";
    this->ship.name[3] = "Iceburg";
}
