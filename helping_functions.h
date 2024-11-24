

#ifndef A2_HELPING_FUNCTIONS_H
#define A2_HELPING_FUNCTIONS_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

inline void writeCSV(const std::vector<std::vector<float>>& data, const std::string& filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Eror while opening file: " << filename << std::endl;
        return;
    }

    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            file << static_cast<int>(row[i]);
            if (i < row.size() - 1) {
                file << ",";
            }
        }
        file << "\n";
    }

    file.close();
    std::cout << "CSV file saved: " << filename << std::endl;
}

template <typename T>
void printVector(const std::vector<T>& vec) {
    std::cout << "[ ";
    for (const auto& element : vec) {
        std::cout << element << " ";
    }
    std::cout << "]" << std::endl;
}

#endif //A2_HELPING_FUNCTIONS_H
