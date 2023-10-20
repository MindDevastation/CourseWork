#include "data.h"

data::data()
{
}

void data::qwe(){
}


//method to change hr and min into hr.min type
double data::decTOsix(double hr, double min){
    double time = 0, temp = 0;
    int count = 0;
    if (min < 60){
        time = static_cast<double>(hr) + static_cast<double> (min) * 0.01;
    }
    else {
        temp = min;
        do{
            count++;
            temp -= 60;
        } while (temp>=60);
        //count = static_cast <int> (min) % 60;
        time = static_cast<double>(hr + 1*count)+static_cast<double> (min-60*count) * 0.01;
        if (time >= 24){
            time = time - 24;
        }
    }
    return time;
}


void data::setHr(unsigned short k, unsigned short m){
    unsigned short ArrSize = (sizeof(this->hr)/sizeof(unsigned short));
    if(k >= ArrSize){
        vector->push_back_double_unsignedShort(hr, ArrSize);
    }
    vector->fillArr(hr, k, m);
}
