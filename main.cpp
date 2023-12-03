#include <iostream>

#include "MyArray.h"
#include "MyArray.cpp"

int main() {
    MyArray<int> myArray{};
    myArray.push_back(2);
    myArray.push_back(3);
    myArray.push_back(1);

    std::cout << "--------------------" << std::endl;

    std::cout << myArray[0] << std::endl;
    std::cout << myArray[1] << std::endl;
    std::cout << myArray[2] << std::endl;

    std::cout << "--------------------" << std::endl;

    myArray.createSorting(std::less<>());

    std::cout << myArray[0] << std::endl;
    std::cout << myArray[1] << std::endl;
    std::cout << myArray[2] << std::endl;

    std::cout << "--------------------" << std::endl;

    myArray.createSorting(std::greater<>());

    std::cout << myArray[0] << std::endl;
    std::cout << myArray[1] << std::endl;
    std::cout << myArray[2] << std::endl;

    std::cout << "--------------------" << std::endl;

    myArray.setSorting(0);

    std::cout << myArray[0] << std::endl;
    std::cout << myArray[1] << std::endl;
    std::cout << myArray[2] << std::endl;
    return 0;
}
