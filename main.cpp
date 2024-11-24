#include "array_generator.h"
#include "sort_tester.h"
#include <iostream>
#include "helping_functions.h"

int main() {
    std::vector<float> merge_sort_rnd_arr_timings;
    std::vector<float> merge_sort_rev_arr_timings;
    std::vector<float> merge_sort_near_sorted_arr_timings;\

    std::vector<float> merge_insertion_sort_rnd_arr_timings;
    std::vector<float> merge_insertion_sort_rev_arr_timings;
    std::vector<float> merge_insertion_sort_near_sorted_arr_timings;

    //подготовка массивов
    for (int size = 500; size <= 10000; size += 100) {

        std::vector<int> randomArray = ArrayGenerator::generateRandomArray(size);
        std::vector<int> reverseArray = ArrayGenerator::generateReverseSortedArray(size);
        std::vector<int> nearlySortedArray = ArrayGenerator::generateNearlySortedArray(size);

        merge_sort_rnd_arr_timings.push_back(0);
        merge_sort_rev_arr_timings.push_back(0);
        merge_sort_near_sorted_arr_timings.push_back(0);

        merge_insertion_sort_rnd_arr_timings.push_back(0);
        merge_insertion_sort_rev_arr_timings.push_back(0);
        merge_insertion_sort_near_sorted_arr_timings.push_back(0);
    }

    int n = 10;
    for(int i=0; i<=n; i++){
        for (int size = 500; size <= 10000; size += 100) {
            std::cout << "Testing size: " << size << std::endl;

            // Генерация массивов
            std::vector<int> randomArray = ArrayGenerator::generateRandomArray(size);
            std::vector<int> reverseArray = ArrayGenerator::generateReverseSortedArray(size);
            std::vector<int> nearlySortedArray = ArrayGenerator::generateNearlySortedArray(size);

            // Тестирование
            merge_sort_rnd_arr_timings[(size-500)/100] += SortTester::testQuickSort(randomArray);
            merge_sort_rev_arr_timings[(size-500)/100] += SortTester::testQuickSort(reverseArray);
            merge_sort_near_sorted_arr_timings[(size-500)/100] += SortTester::testQuickSort(nearlySortedArray);

            // Тестирование
            merge_insertion_sort_rnd_arr_timings[(size-500)/100] += SortTester::testIntroSort(randomArray);
            merge_insertion_sort_rev_arr_timings[(size-500)/100]+= SortTester::testIntroSort(reverseArray);
            merge_insertion_sort_near_sorted_arr_timings[(size-500)/100] +=SortTester::testIntroSort(nearlySortedArray);
        }
    }

    for (int size = 500; size <= 10000; size += 100) {
        merge_sort_rnd_arr_timings[(size-500)/100] /=n;
        merge_sort_rev_arr_timings[(size-500)/100] /=n;
        merge_sort_near_sorted_arr_timings[(size-500)/100] /=n;

        merge_insertion_sort_rnd_arr_timings[(size-500)/100] /=n;
        merge_insertion_sort_rev_arr_timings[(size-500)/100] /=n;
        merge_insertion_sort_near_sorted_arr_timings[(size-500)/100] /=n ;
    }

    std::vector<std::vector<float>> vec;
    vec.push_back(merge_sort_rnd_arr_timings);
    vec.push_back(merge_sort_rev_arr_timings);
    vec.push_back(merge_sort_near_sorted_arr_timings);
    vec.push_back(merge_insertion_sort_rnd_arr_timings);
    vec.push_back(merge_insertion_sort_rev_arr_timings);
    vec.push_back(merge_insertion_sort_near_sorted_arr_timings);

    writeCSV(vec, "output.csv");

    return 0;
}


/*
#include <iostream>
#include <vector>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>

inline void insertionSort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

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

inline void heapSort(std::vector<int>& arr, int left, int right) {
    for (int i = (right / 2) - 1; i >= left; --i) {
        heapify(arr, right + 1, i);
    }
    for (int i = right; i > left; --i) {
        std::swap(arr[left], arr[i]);
        heapify(arr, i, left);
    }
}

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

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    introSort(arr);
    for (const int& num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
*/