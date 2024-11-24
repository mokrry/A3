#include "array_generator.h"
#include <random>
#include <algorithm>

std::vector<int> ArrayGenerator::generateRandomArray(int size, int minValue, int maxValue) {
    std::vector<int> array(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minValue, maxValue);

    for (int i = 0; i < size; ++i) {
        array[i] = dis(gen);
    }
    return array;
}

std::vector<int> ArrayGenerator::generateReverseSortedArray(int size) {
    std::vector<int> array(size);
    for (int i = 0; i < size; ++i) {
        array[i] = size - i;
    }
    return array;
}

std::vector<int> ArrayGenerator::generateNearlySortedArray(int size, int swaps) {
    std::vector<int> array = generateRandomArray(size);
    std::sort(array.begin(), array.end());

    for (int i = 0; i < swaps; ++i) {
        int index1 = rand() % size;
        int index2 = rand() % size;
        std::swap(array[index1], array[index2]);
    }
    return array;
}