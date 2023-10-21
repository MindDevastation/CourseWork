#include "train.h"

Train::Train()
{
    for (int i = 0; i < 4; i++){
        this->train.setHr(i, 5 + i*2) ;
        int k = 0;
        do{
            this ->train.setHr(i, this->train.getHr(i) - 24);
            k++;
        }while(this->train.getHr(i) >= 24);
        this->train.setMin(i, i + 5);
        this->train.setPeriod(i, 15);
    }
    this->train.name[0] = "New York - Dublin";
    this->train.name[1] = "Kiev - Lviv";
    this->train.name[2] = "Paris - Kioto";
    this->train.name[3] = "Praga - Madrid";
}
