#include "ShellSort.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<int> data = {9, 8, 3, 7, 5, 6, 4, 1, -5, 0, 12};

    std::cout << "Before sorting: ";
    for (int x : data) {
        std::cout << x << " ";
    }
    std::cout << "\nIs sorted? " << (isSorted(data) ? "Yes" : "No") << "\n\n";

    shellSort(data);

    std::cout << "After sorting:  ";
    for (int x : data) {
        std::cout << x << " ";
    }
    std::cout << "\nIs sorted? " << (isSorted(data) ? "Yes" : "No") << "\n";

    return 0;
}