#include "BoyerMooreSearch.h"
#include <string>
#include <iostream>
#include <vector>

int main() {
    std::string text = "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator";
    std::string pattern = "tor";

    int firstIndex = findFirst(text, pattern);
    std::cout << "firstIndex " << firstIndex;

    std::vector<int> allIndex = findAll(text, pattern);
    std::cout << " allIndex: ";

    for (int index : allIndex) {
        std::cout << index << " ";
    }

    return 0;
}