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
        this->ship.setMin(i, i + 1);
        this->ship.setPeriod(i, 15);
    }
//    this->ship.setName(0, "Ticktonick", this->ship.size);
//    this->ship.setName(1, "Crimson Heart", this->ship.size);
//    this->ship.setName(2, "Dead Island", this->ship.size);
//    this->ship.setName(3, "Iceburg", this->ship.size);
}
