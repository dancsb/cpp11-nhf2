#ifndef NHF2_MYARRAY_H
#define NHF2_MYARRAY_H

#include <vector>
#include <functional>

template <typename T>
class MyArray{
private:
    struct Sorting{
        std::function<bool(T, T)> comparator;
        std::vector<int> indexes;
    };
    std::vector<T> data;
    std::vector<Sorting> sortings;
    int selectedSorting = 0;
    void sort();
public:
    void push_back(const T& value);
    void pop_back();
    T operator[](int index);
    void setSorting(int s);
    int createSorting(std::function <bool(T, T)> f);
};

#endif //NHF2_MYARRAY_H
