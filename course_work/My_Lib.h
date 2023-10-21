#ifndef MY_LIB_H
#define MY_LIB_H
#include<iostream>
#include<stdlib.h>

namespace My_Lib {

class MyVector {
public:
    void push_back_double(int*& arr, unsigned short & size);   //increace size of int array
    void push_back_double(unsigned short*& arr, unsigned short & size);  //increace size of unsigned short array
    void push_back_double(std::string*& arr, unsigned short& size);  //increace size of string array
    void push_back_double(wchar_t*& arr, unsigned short& size);  //increace size of wchar_t array
    void pop_back(unsigned short*& arr, unsigned short & size, int point);
    void pop_back(std::string*& arr, unsigned short &size, int point);
    void fillArr(std::string*& arr, unsigned short pointInArr, std::string *value); //fill string array
    void fillArr(int*& arr, int pointInArr, int value);  //fill int array
    void fillArr(unsigned short*& arr, unsigned short pointInArr, unsigned short value); //fill unsigned short array
    void fillArr(wchar_t*& arr, unsigned short pointInArr, wchar_t value); //fill wchar_t array


};


}




#endif // MY_LIB_H
