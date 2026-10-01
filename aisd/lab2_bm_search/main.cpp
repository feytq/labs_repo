#include "BoyerMooreSearch.h"
#include <string>
#include <iostream>
#include <vector>

void printVector(const std::string& text, const std::vector<int>& vector) {
    std::cout << text << ": ";
    for (int index : vector) {
        std::cout << index << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::string text = "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator";
    std::string pattern = "tor";

    std::cout << "findFirst: " << findFirst(text, pattern) << std::endl; // 15

    printVector("findAll(allIndices)", findAll(text, pattern)); // 15 30 38 89

    printVector("findAll(0, 91)", findAll(text, pattern, 0, 91)); // 15 30 38 89
    printVector("findAll(17, 91)", findAll(text, pattern, 17, 91)); // 30 38 89
    printVector("findAll(28, 36)", findAll(text, pattern, 28, 36)); // 30

    return 0;
}