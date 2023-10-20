#include "bus.h"

Bus::Bus()
{
    for (int i = 0; i < 4; i++){
        this->bus.hr[i] = 5 + i*2;
        int k = 0;
        do{
            this ->bus.hr[i] -= 24;
            k++;
        }while(this->bus.hr[i] >= 24);
        this->bus.min[i] = i + 1;
        this->bus.period[i] = 15;
    }
    this->bus.name[0] = "A30";
    this->bus.name[1] = "D15";
    this->bus.name[2] = "A1";
    this->bus.name[3] = "U71";
}
