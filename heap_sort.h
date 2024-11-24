#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <vector>
#include <algorithm>

inline void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}


inline void heapSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

inline void heapSort(std::vector<int>& arr, int left, int right) {
    for (int i = (right / 2) - 1; i >= left; --i) {
        heapify(arr, right + 1, i);
    }
    for (int i = right; i > left; --i) {
        std::swap(arr[left], arr[i]);
        heapify(arr, i, left);
    }
}

#endif // HEAP_SORT_H
