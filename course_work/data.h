#ifndef DATA_H
#define DATA_H
#include "MyLib.h"
#include <string>
#include <stdlib.h>

class data
{
private:

public:
    MyLib::Vector *vector;
    data();
    //private
    std::string *transport = new std::string [4]{"Bus", "Ship", "Plane", "Train"};  //Transport types
    unsigned short *min = new unsigned short[4]{};      //Start in minutes
    unsigned short *period = new unsigned short[4]{} ;  //Period betwee stops
    unsigned short *hr = new unsigned short[4] {};      //Start in hours
    std::string *name = new std::string[4]{};           //Transport name
    void qwe(); //trst
    double decTOsix(double, double);  //method to change hr and min into hr.min type
    int k1; //test
    //public
    std::string getTransport (int k) {return *(transport+k);}  //get transport types
    //void setTransport(std::string *){}
    unsigned short getHr (int position){return *(hr+position);}  //get hours
    void setHr(unsigned short position, unsigned short value);  //set hours
};

#endif // DATA_H
