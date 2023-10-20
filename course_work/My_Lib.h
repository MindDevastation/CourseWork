#ifndef MY_LIB_H
#define MY_LIB_H
#include<iostream>
#include<stdlib.h>

namespace My_Lib {

class MyVector {
public:
    void push_back_double_int(int*&, int&);   //increace size of int array
    void push_back_double_unsignedShort(unsigned short*&, unsigned short&);  //increace size of unsigned short array
    void fillArr(int* const, int const, int const);  //fill int array
    void fillArr(unsigned short* const, unsigned short const, unsigned short const); //fill unsigned short array


};

void MyVector::push_back_double_int(int*& arr, int& size) {
    int* newArr = new int[size * 2];

    for (int i = 0; i < size; i++) {
        *(newArr+i) = *(arr+i);
    }

    size *= 2;

    delete arr;

    arr = newArr;
}

void MyVector::push_back_double_unsignedShort(unsigned short*& arr, unsigned short& size) {
    unsigned short* newArr = new unsigned short[size * 2];

    for (int i = 0; i < size; i++) {
        *(newArr+i) = *(arr+i);
    }

    size *= 2;

    delete arr;

    arr = newArr;
}

void MyVector::fillArr(int* const arr, int const point, int const value){
    *(arr+point) = value;
}

void MyVector::fillArr(unsigned short* const arr, unsigned short const point, unsigned short const value){
    *(arr+point) = value;
}


}




#endif // MY_LIB_H
