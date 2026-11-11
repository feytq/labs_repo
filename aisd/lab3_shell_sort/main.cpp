#include "ShellSort.h"
#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>

namespace {

struct DatasetConfig {
    int size;
    int minVal;
    int maxVal;
    std::string name;
};

std::vector<int> generateRandomArray(int size, int minVal, int maxVal) {
    static std::mt19937 generator(42);
    std::uniform_int_distribution<int> distribution(minVal, maxVal);

    std::vector<int> result(size);
    for (int i = 0; i < size; i++) {
        result[i] = distribution(generator);
    }
    return result;
}

void writeToFile(const std::string& filename, const std::vector<int>& arr) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: cannot open file " << filename << "\n";
        return;
    }

    int n = static_cast<int>(arr.size());
    for (int i = 0; i < n; i++) {
        file << arr[i] << (i + 1 == n ? "" : " ");
    }
}

double measureAverageTime(const std::vector<int>& sourceArr, const std::vector<int>& gaps, int runs = 3) {
    double totalMs = 0.0;

    for (int r = 0; r < runs; r++) {
        std::vector<int> workingCopy = sourceArr;

        const auto startTime = std::chrono::high_resolution_clock::now();
        shellSort(workingCopy, gaps);
        const auto endTime = std::chrono::high_resolution_clock::now();

        if (!isSorted(workingCopy)) {
            std::cerr << "Sorting validation failed!\n";
            return -1.0;
        }

        const std::chrono::duration<double, std::milli> elapsed = endTime - startTime;
        totalMs += elapsed.count();
    }

    return totalMs / runs;
}

} // anonymous namespace

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<DatasetConfig> configs = {
        {10000, -10, 10, "10k_range10"},
        {10000, -1000, 1000, "10k_range1k"},
        {10000, -100000, 100000, "10k_range100k"},
        {100000, -10, 10, "100k_range10"},
        {100000, -1000, 1000, "100k_range1k"},
        {100000, -100000, 100000, "100k_range100k"},
        {1000000, -10, 10, "1m_range10"},
        {1000000, -1000, 1000, "1m_range1k"},
        {1000000, -100000, 100000, "1m_range100k"}
    };

    std::ofstream reportFile("report.txt");

    std::cout << std::left << std::setw(18) << "Dataset"
              << std::setw(16) << "Shell (avg ms)"
              << std::setw(18) << "Hibbard (avg ms)"
              << std::setw(16) << "Knuth (avg ms)" << "\n";
    std::cout << std::string(68, '-') << "\n";

    reportFile << "Dataset\tShell (ms)\tHibbard (ms)\tKnuth (ms)\n";

    for (const auto& config : configs) {
        std::cout << "Generating " << config.name << "..." << std::flush;
        std::vector<int> baseArray = generateRandomArray(config.size, config.minVal, config.maxVal);

        writeToFile(config.name + ".txt", baseArray);
        std::cout << " saved. Benchmarking...\n";

        std::vector<int> gapsShell = getShellGaps(config.size);
        std::vector<int> gapsHibbard = getHibbardGaps(config.size);
        std::vector<int> gapsKnuth = getKnuthGaps(config.size);

        double timeShell = measureAverageTime(baseArray, gapsShell);
        double timeHibbard = measureAverageTime(baseArray, gapsHibbard);
        double timeKnuth = measureAverageTime(baseArray, gapsKnuth);

        std::cout << std::left << std::setw(18) << config.name
                  << std::setw(16) << std::fixed << std::setprecision(2) << timeShell
                  << std::setw(18) << std::fixed << std::setprecision(2) << timeHibbard
                  << std::setw(16) << std::fixed << std::setprecision(2) << timeKnuth << "\n";

        reportFile << config.name << "\t" << timeShell << "\t" << timeHibbard << "\t" << timeKnuth << "\n";
    }

    std::cout << "\nFinished. Results written to report.txt\n";
    return 0;
}