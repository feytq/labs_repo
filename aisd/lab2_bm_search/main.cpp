#include "BoyerMooreSearch.h"
#include <string>
#include <iostream>

int main() {
    std::string text = "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator";
    std::string pattern = "tor";

    int firstIndex = findFirst(text, pattern);
    std::cout << "firstIndex " << firstIndex;
    return 0;
}