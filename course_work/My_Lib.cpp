#include "My_Lib.h"


void My_Lib::MyVector::push_back_double(unsigned short*& arr, unsigned short& size) {
    unsigned short* newArr = new unsigned short[size * 2];

    for (int i = 0; i < size; i++) {
        *(newArr+i) = *(arr+i);
    }

    size *= 2;

    delete arr;

    arr = newArr;
}

void My_Lib::MyVector::push_back_double(std::string *&arr, unsigned short& size){
    std::string* newArr = new std::string[size * 2];

    for (int i = 0; i < size; i++) {
        *(newArr+i) = *(arr+i);
    }

    size = size * 2;

    delete arr;

    arr = newArr;
}

void My_Lib::MyVector::push_back_double(int*& arr, unsigned short& size) {
    int* newArr = new int[size * 2];

    for (int i = 0; i < size; i++) {
        *(newArr+i) = *(arr+i);
    }

    size *= 2;

    delete arr;

    arr = newArr;
}

void My_Lib::MyVector::push_back_double(wchar_t*& arr, unsigned short& size) {
    wchar_t* newArr = new wchar_t[size * 2];

    for (int i = 0; i < size; i++) {
        *(newArr+i) = *(arr+i);
    }

    size *= 2;

    delete arr;

    arr = newArr;
}

void My_Lib::MyVector::fillArr(int*& arr, int point, int value){
    *(arr+point) = value;
}

void My_Lib::MyVector::fillArr(std::string*& arr, unsigned short pointInArr, std::string* value){
    *(arr+pointInArr) = *(value);
}

void My_Lib::MyVector::fillArr(unsigned short *&arr, unsigned short pointInArr, unsigned short value){
    *(arr+pointInArr) = value;
}

