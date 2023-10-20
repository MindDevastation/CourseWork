#ifndef MY_LIB_H
#define MY_LIB_H
#include<iostream>
#include<stdlib.h>

namespace My_Lib {

class MyVector {
public:
    void push_back_double(int*&, unsigned short &);   //increace size of int array
    void push_back_double(unsigned short*&, unsigned short&);  //increace size of unsigned short array
    void push_back_double(std::string*& arr, unsigned short& size);  //increace size of string array
    void push_back_double(wchar_t*& arr, unsigned short& size);  //increace size of wchar_t array
    void fillArr(std::string*& arr, unsigned short pointInArr, std::string *value); //fill string array
    void fillArr(int*&, int, int);  //fill int array
    void fillArr(unsigned short*&, unsigned short, unsigned short); //fill unsigned short array
    //void fillArr(std::string*& arr, unsigned short pointInArr, std::string *value); //fill wchar_t array


};


}




#endif // MY_LIB_H
