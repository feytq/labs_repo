#include "ShellSort.h"
#include <iostream>
#include <vector>

void testSort(const std::string& name, std::vector<int> arr, const std::vector<int>& gaps) {
    shellSort(arr, gaps);
    std::cout << name << " sort result: " << (isSorted(arr) ? "PASSED" : "FAILED") << "\n";
}

int main() {
    std::vector<int> sample = {15, 3, 2, 56, 12, -4, 0, 8, 33, 1, 9, 21};
    int n = static_cast<int>(sample.size());

    testSort("Shell", sample, getShellGaps(n));
    testSort("Hibbard", sample, getHibbardGaps(n));
    testSort("Knuth", sample, getKnuthGaps(n));

    return 0;
}