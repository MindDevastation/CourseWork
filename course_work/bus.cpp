#include "bus.h"

Bus::Bus()
{
    for (int i = 0; i < 4; i++){
        this->bus.setHr(i, 5 + i*2) ;
        int k = 0;
        do{
            this ->bus.setHr(i, this->bus.getHr(i) - 24);
            k++;
        }while(this->bus.getHr(i) >= 24);
        this->bus.setMin(i, i + 1);
        this->bus.setPeriod(i, 15);
    }
    std::string *tempName = new std::string [1] {"tt123"};
    //this->bus.name[0] = "A30";
    this->bus.setName(0, tempName);
    this->bus.name[1] = "A31";
    this->bus.name[2] = "A32";
    this->bus.name[3] = "A311";
    this->bus.setName(4, tempName);
    //this->bus.setPeriod(4, 25);
}
