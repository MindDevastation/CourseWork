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
        this->train.setMin(i, i + 1);
        this->train.setPeriod(i, 15);
    }
//    this->train.setName(0, "New York - Dublin", this->train.size);
//    this->train.setName(1, "Kiev - Lviv", this->train.size);
//    this->train.setName(2, "Paris - Kioto", this->train.size);
//    this->train.setName(3, "Praga - Madrid", this->train.size);
}
