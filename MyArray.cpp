#include <numeric>

#include "MyArray.h"

template<typename T>
void MyArray<T>::push_back(const T &value) {
    data.push_back(value);
    for(auto &sorting : sortings)
        for (size_t i = 0; i < sorting.indexes.size(); i++)
            if (sorting.comparator(value, data[sorting.indexes[i]])) {
                sorting.indexes.insert(sorting.indexes.begin() + i, data.size() - 1);
                break;
            }
}

template<typename T>
void MyArray<T>::pop_back() {
    data.pop_back();
    for(auto &sorting : sortings)
        sorting.indexes.erase(std::find(sorting.indexes.begin(), sorting.indexes.end(), data.size()));
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