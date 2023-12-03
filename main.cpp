#include <iostream>

#include "MyArray.h"
#include "MyArray.cpp"

int main() {
    MyArray<int> myArray{};
    myArray.push_back(1);
    myArray.push_back(2);
    myArray.push_back(3);

    std::cout << myArray[0] << std::endl;
    std::cout << myArray[1] << std::endl;
    std::cout << myArray[2] << std::endl;

    myArray.pop_back();
    std::cout << myArray[0] << std::endl;
    std::cout << myArray[1] << std::endl;
    return 0;
}
