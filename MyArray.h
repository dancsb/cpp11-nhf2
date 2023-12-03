#ifndef NHF2_MYARRAY_H
#define NHF2_MYARRAY_H

#include <vector>

template <typename T>
class MyArray{
private:
    std::vector<T> data;
    int sorting;
public:
    void push_back(const T& value);
    void pop_back();
    T operator[](int index);
};

#endif //NHF2_MYARRAY_H
