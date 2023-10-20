#ifndef MYLIB_H
#define MYLIB_H
#include<iostream>
#include<stdlib.h>

namespace MyLib {

class Vector {
public:
    void push_back_double_int(int*&, int&);
    void push_back_double_unsignedShort(unsigned short*&, unsigned short&);
    void fillArr(int* const, int const, int const);
    void fillArr(unsigned short* const, unsigned short const, unsigned short const);


};

void Vector::push_back_double_int(int*& arr, int& size) {
    int* newArr = new int[size * 2];

    for (int i = 0; i < size; i++) {
        *(newArr+i) = *(arr+i);
    }

    size *= 2;

    delete arr;

    arr = newArr;
}

void Vector::push_back_double_unsignedShort(unsigned short*& arr, unsigned short& size) {
    unsigned short* newArr = new unsigned short[size * 2];

    for (int i = 0; i < size; i++) {
        *(newArr+i) = *(arr+i);
    }

    size *= 2;

    delete arr;

    arr = newArr;
}

void Vector::fillArr(int* const arr, int const point, int const value){
    *(arr+point) = value;
}

void Vector::fillArr(unsigned short* const arr, unsigned short const point, unsigned short const value){
    *(arr+point) = value;
}


}




#endif // MYLIB_H
