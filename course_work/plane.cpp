#include "plane.h"

Plane::Plane()
{
    for (int i = 0; i < 4; i++){
        this->plane.setHr(i, 3 + i*2) ;
        int k = 0;
        do{
            this ->plane.setHr(i, this->plane.getHr(i) - 24);
            k++;
        }while(this->plane.getHr(i) >= 24);
        this->plane.setMin(i, i + 3);
        this->plane.setPeriod(i, 10);
    }
    this->plane.name[0] = "Airobus 0000";
    this->plane.name[1] = "Airobus 0120";
    this->plane.name[2] = "Airobus 1410";
    this->plane.name[3] = "Airobus 001230";
}
