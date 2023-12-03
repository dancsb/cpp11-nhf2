#include <numeric>

#include "MyArray.h"

template<typename T>
void MyArray<T>::push_back(const T &value) {
    data.push_back(value);
    sort();
}

template<typename T>
void MyArray<T>::pop_back() {
    data.pop_back();
    sort();
}

template<typename T>
T MyArray<T>::operator[](int index) {
    if(selectedSorting == 0)
        return data[index];
    return data[sortings[selectedSorting - 1].indexes[index]];
}

template<typename T>
void MyArray<T>::setSorting(int s) {
    selectedSorting = s;
}

template<typename T>
int MyArray<T>::createSorting(std::function<bool(T, T)> f) {
    std::vector<int> sorting(data.size());
    std::iota(sorting.begin(), sorting.end(), 0);
    std::sort(sorting.begin(), sorting.end(), [this, &f](const int &a, const int &b) {
        return f(data[a], data[b]);
    });
    sortings.push_back({f, sorting});

    selectedSorting = sortings.size();
    return sortings.size();
}

template<typename T>
void MyArray<T>::sort() {
    for(auto &sorting : sortings)
        std::sort(sorting.indexes.begin(), sorting.indexes.end(), [this, &sorting](const int &a, const int &b) {
            return sorting.comparator(data[a], data[b]);
        });
}