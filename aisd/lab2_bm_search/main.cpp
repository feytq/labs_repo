#include "BoyerMooreSearch.h"
#include <string>
#include <iostream>
#include <vector>

int main() {
    std::string text = "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator";
    std::string pattern = "tor";

    int firstIndex = findFirst(text, pattern);
    std::cout << "firstIndex: " << firstIndex << std::endl;

    std::vector<int> allIndex = findAll(text, pattern);
    std::cout << "allIndex: ";

    for (int index1 : allIndex) {
        std::cout << index1 << " ";
    }
    std::cout << std::endl;
    
    std::vector<int> diapIndex = findAll(text, pattern, 28, 36);
    std::cout << "diapIndex: ";

    for (int index2 : diapIndex) {
        std::cout << index2 << " ";
    }
    std::cout << std::endl;

    return 0;
}