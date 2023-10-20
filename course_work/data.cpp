#include "data.h"

data::data()
{
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


void data::setHr(unsigned short position, unsigned short value){
    if(position >= this->sizeHr){
        vector->push_back_double(hr, this->sizeHr);
    }
    vector->fillArr(hr, position, value);
}

void data::setMin(unsigned short position, unsigned short value){
    if(position >= this->sizeMin){
        vector->push_back_double(min, this->sizeMin);
    }
    vector->fillArr(min, position, value);
}

void data::setPeriod(unsigned short position, unsigned short value){
    if(position >= this->sizePeriod){
        vector->push_back_double(period, this->sizePeriod);
    }
    vector->fillArr(period, position, value);
}

void data::setName(unsigned short position, std::string* variable){
    if(position >= this->sizeName){
        vector->push_back_double(name, this->sizeName);

    }
    vector->fillArr(name, position, variable);

}

