#include <numeric>

#include "MyArray.h"

template<typename T>
void MyArray<T>::push_back(const T &value) {
    data.push_back(value);
}

template<typename T>
void MyArray<T>::pop_back() {
    data.pop_back();
}

template<typename T>
T MyArray<T>::operator[](int index) {
    if(selectedSorting == 0)
        return data[index];
    return data[sortings[selectedSorting - 1][index]];
}

template<typename T>
void MyArray<T>::setSorting(int s) {
    selectedSorting = s;
}

template<typename T>
int MyArray<T>::createSorting(std::function<bool(T, T)> f) {
    sortingFunctions.push_back(f);

    std::vector<int> sorting(data.size());
    std::iota(sorting.begin(), sorting.end(), 0);
    std::sort(sorting.begin(), sorting.end(), [this, &f](const int &a, const int &b) {
        return f(data[a], data[b]);
    });
    sortings.push_back(sorting);

    selectedSorting = sortings.size();
    return sortings.size();
}