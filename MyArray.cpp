#include <iostream>
#include "MyArray.h"

template<typename T>
void MyArray<T>::push_back(const T &value) {
    data.push_back(value);
    std::cout << "xd" << std::endl;
}

template<typename T>
void MyArray<T>::pop_back() {
    data.pop_back();
}

template<typename T>
T MyArray<T>::operator[](int index) {
    return data[index];
}