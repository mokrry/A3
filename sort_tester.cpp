#include "sort_tester.h"
#include "insertion_sort.h"
#include "intro_sort.h"
#include <chrono>
#include <iostream>
#include "helping_functions.h"
#include "quick_sort.h"

float SortTester::testQuickSort(const std::vector<int>& array) {
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> arrCopy = array;  // Копируем массив
    quickSort(arrCopy);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    float msec = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
std::cout << "Quick Sort took " << msec << " microseconds." << std::endl;
    return msec;
}

float SortTester::testIntroSort(const std::vector<int>& array) {
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> arrCopy = array;  // Копируем массив
    introSort(arrCopy);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    float msec = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
    std::cout << "Intro Sort took " << msec << " microseconds." << std::endl;
    return msec;
}
