#include <iostream>

#include "MyArray.h"
#include "MyArray.cpp"

template<typename T>
void print(MyArray<T> &myArray) {
    for (size_t i = 0; i < myArray.size(); i++)
        std::cout << myArray[i] << std::endl;

    std::cout << "--------------------" << std::endl;
}

int main() {
    MyArray<int> myArray{};
    myArray.push_back(2);
    myArray.push_back(4);
    myArray.push_back(1);
    print(myArray);

    myArray.createSorting(std::less<>());
    print(myArray);

    myArray.createSorting(std::greater<>());
    print(myArray);

    myArray.setSorting(0);
    print(myArray);

    myArray.push_back(3);

    myArray.setSorting(1);
    print(myArray);

    myArray.setSorting(2);
    print(myArray);

    myArray.pop_back();
    myArray.pop_back();

    myArray.setSorting(1);
    print(myArray);

    myArray.setSorting(2);
    print(myArray);

    return 0;
}
