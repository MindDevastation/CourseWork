#include "train.h"

Train::Train()
{
    for (int i = 0; i < 4; i++){
        this->train.hr[i] = 5 + i*13;
        int k = 0;
        do{
            this ->train.hr[i] -= 24;
            k++;
        }while(this->train.hr[i] >= 24);
        this->train.min[i] = i + 1;
        this->train.period[i] = 20;
    }
    this->train.name[0] = "New York - Dublin";
    this->train.name[1] = "Kiev - Lviv";
    this->train.name[2] = "Paris - Kioto";
    this->train.name[3] = "Praga - Madrid";


}
