#include "plane.h"

Plane::Plane()
{
    for (int i = 0; i < 4; i++){
        this->plane.hr[i] = 5 + i*2;
        int k = 0;
        do{
            this ->plane.hr[i] -= 24;
            k++;
        }while(this->plane.hr[i] >= 24);
        this->plane.min[i] = i + 7;
        this->plane.period[i] = 10;
    }
    this->plane.name[0] = "Airobus 001";
    this->plane.name[1] = "Airobus 151";
    this->plane.name[2] = "Airobus 821";
    this->plane.name[3] = "Airobus 08128";
}
