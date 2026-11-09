#pragma once

#include <vector>

bool isSorted(const std::vector<int>& arr);

void shellSort(std::vector<int>& arr, const std::vector<int>& gaps);

std::vector<int> getShellGaps(int n);
std::vector<int> getHibbardGaps(int n);
std::vector<int> getKnuthGaps(int n);
