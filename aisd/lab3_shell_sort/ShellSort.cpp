#include "ShellSort.h"
#include <algorithm>

namespace {

void reverseVector(std::vector<int>& vec) {
    int start = 0;
    int end = static_cast<int>(vec.size()) - 1;
    while (start < end) {
        std::swap(vec[start], vec[end]);
        start++;
        end--;
    }
}

} // anonymous namespace

bool isSorted(const std::vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

void shellSort(std::vector<int>& arr, const std::vector<int>& gaps) {
    int n = static_cast<int>(arr.size());

    for (int gap : gaps) {
        for (int i = gap; i < n; i++) {
            int currentVal = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > currentVal) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = currentVal;
        }
    }
}

std::vector<int> getShellGaps(int n) {
    std::vector<int> gaps;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        gaps.push_back(gap);
    }
    return gaps;
}

std::vector<int> getHibbardGaps(int n) {
    std::vector<int> gaps;
    int k = 1;
    while (true) {
        int gap = (1 << k) - 1;
        if (gap >= n) {
            break;
        }
        gaps.push_back(gap);
        k++;
    }

    if (gaps.empty()) {
        gaps.push_back(1);
    }

    reverseVector(gaps);
    return gaps;
}

std::vector<int> getKnuthGaps(int n) {
    std::vector<int> gaps;
    int h = 1;
    while (h < n) {
        gaps.push_back(h);
        h = 3 * h + 1;
    }

    if (gaps.empty()) {
        gaps.push_back(1);
    }

    reverseVector(gaps);
    return gaps;
}