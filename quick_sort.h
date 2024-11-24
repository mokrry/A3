#ifndef A3_QUICK_SORT_H
#define A3_QUICK_SORT_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "helping_functions.h"

inline int partition(std::vector<int> &arr, int left, int right) {

    int pivotIndex = left + rand() % (right - left + 1);
    int pivotValue = arr[pivotIndex];
    std::swap(arr[pivotIndex], arr[right]);
    int i = left;
    for (int j = left; j < right; ++j) {
        if (arr[j] < pivotValue) {
            std::swap(arr[i], arr[j]);
            ++i;
        }
    }
    std::swap(arr[i], arr[right]);
    return i;
}

inline void quickSort(std::vector<int> &arr, int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

inline void quickSort(std::vector<int> &arr) {
    quickSort(arr, 0, arr.size() - 1);
}

#endif //A3_QUICK_SORT_H
