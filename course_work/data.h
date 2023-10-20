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
private:

    std::string *transport = new std::string [4]{"Bus", "Ship", "Plane", "Train"};  //Transport types
    unsigned short *min = new unsigned short[sizeMin]{};      //Start in minutes
    unsigned short *period = new unsigned short[sizePeriod]{} ;  //Period between stops
    unsigned short *hr = new unsigned short[sizeHr] {};      //Start in hours
               //Transport name

public:
    unsigned short sizeMin = 4, sizePeriod = 4, sizeHr = 4, sizeName = 4;
    std::string *name = new std::string[sizeName]{};
     //std::vector<std::string> name;
    double decTOsix(double, double);  //method to change hr and min into hr.min type
    std::string getTransport (int k) {return *(transport+k);}  //get transport types
    //void setTransport(std::string *){}
    unsigned short getHr (int position){return *(hr+position);}  //get hours
    void setHr(unsigned short position, unsigned short value);  //set hours

    unsigned short getMin (int position){return *(min+position);}  //get minutes
    void setMin(unsigned short position, unsigned short value);  //set minutes

    unsigned short getPeriod (int position){return *(period+position);}  //get Period between stops
    void setPeriod(unsigned short position, unsigned short value);  //set Period between stops

    std::string getName (int position){return *(name+position);}  //get Period between stops
    void setName(unsigned short position, std::string *variable);  //set Period between stops


    //unsigned short getSize(){return size;}
    //wchar_t getName (int position){return *(name+position);}  //get Period between stops
   // void setName(unsigned short position, wchar_t *value);  //set Period between stops

};

#endif // DATA_H
