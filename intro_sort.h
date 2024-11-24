#ifndef INTROSORT_UTIL_H
#define INTROSORT_UTIL_H

#include <vector>
#include <cmath>
#include <algorithm>
#include <random>
#include "insertion_sort.h"
#include "heap_sort.h"
#include "quick_sort.h"

inline void introSort(std::vector<int>& arr, int left, int right, int depth_limit) {
    int size = right - left + 1;

    if (size < 16) {
        insertionSort(arr, left, right);
    } else if (depth_limit == 0) {
        heapSort(arr, left, right);
    } else if (left < right) {
        int pivot = partition(arr, left, right);
        introSort(arr, left, pivot - 1, depth_limit - 1);
        introSort(arr, pivot + 1, right, depth_limit - 1);
    }
}


inline void introSort(std::vector<int>& arr) {
    int n = arr.size();
    int depth_limit = 2 * std::log2(n);
    introSort(arr, 0, n - 1, depth_limit);
}

#endif // INTROSORT_UTIL_H
