#ifndef DATA_H
#define DATA_H
#include "My_Lib.h"
#include <string>
#include <stdlib.h>
#include <vector>

class data
{
private:

public:
    My_Lib::MyVector *vector;
    data();
    ~data();
private:

    std::string *transport = new std::string [4]{"Bus", "Ship", "Plane", "Train"};  //Transport types
    unsigned short *min = new unsigned short[sizeMin]{};      //Start in minutes
    unsigned short *period = new unsigned short[sizePeriod]{} ;  //Period between stops
    unsigned short *hr = new unsigned short[sizeHr] {};      //Start in hours
    unsigned short transportIndex = 4;    //Transport type

public:
    unsigned short sizeMin = 4, sizePeriod = 4, sizeHr = 4, sizeName = 4;  //sizes of arrays
    std::string *name = new std::string[sizeName]{};   //Transport name
    std::string *tempName = new std::string [1] {};     //Temp buffer for transport names
    double decTOsix(double, double);  //method to change hr and min into hr.min type
    std::string getTransport (int k) {return *(transport+k);}  //get transport types

    unsigned short getHr (int position){return *(hr+position);}  //get hours
    void setHr(unsigned short position, unsigned short value);  //set hours
    void delHr(unsigned short position);    //delete hours

    unsigned short getMin (int position){return *(min+position);}  //get minutes
    void setMin(unsigned short position, unsigned short value);  //set minutes
    void delMin(unsigned short position);   //delete minutes

    unsigned short getPeriod (int position){return *(period+position);}  //get Period between stops
    void setPeriod(unsigned short position, unsigned short value);  //set Period between stops
    void delPeriod(unsigned short position);    //delte period  between stops

    std::string getName (int position){return *(name+position);}  //get transport numbers
    void setName(unsigned short position, std::string *variable);  //set transport numbers
    void delName(unsigned short position);  //delete transport numbers


    //methods for changing transport types
    unsigned short getTransportIndex (){return transportIndex;}
    void setTransportIndexIncr(){transportIndex++;}
    void setTransportIndexDecr(){transportIndex--;}
};

#endif // DATA_H
