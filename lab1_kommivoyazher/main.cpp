#include <iomanip>
#include <iostream>
#include "Matrix.h"
#include "KommivoyazherSolver.h"

void runExperiment(int nCities, int runIndex, int minRange, int maxRange) {
    int** matrix = createMatrix(nCities);
    fillRandomMatrix(matrix, nCities, minRange, maxRange);

    int startCity = 0;
    ExactResult exact = solveBruteForce(matrix, nCities, startCity);
    GreedyResult greedy = solveGreedy(matrix, nCities, startCity);

    double quality = calculateQuality(exact.minCost, exact.maxCost, greedy.cost);

    std::cout << "  Run #" << runIndex 
              << " | Exact [Min: " << exact.minCost 
              << ", Max: " << exact.maxCost 
              << ", Time: " << std::defaultfloat << exact.timeInSeconds << "s]"
              << " | Greedy [Cost: " << greedy.cost 
              << ", Time: " << std::defaultfloat << greedy.timeInSeconds << "s]"
              << " | Quality: " << std::fixed << std::setprecision(1) << quality << "%" 
              << std::endl;

    destroyMatrix(matrix, nCities);
}

int main() {
    int testSizes[] = {4, 6, 8, 10, 11, 12};
    int testSizesCount = sizeof(testSizes) / sizeof(testSizes[0]);
    int runsPerSize = 3;

    int minCostRange = 10;
    int maxCostRange = 1000;

    std::cout << "=== KOMMIVOYAZHER EXPERIMENT (Cost Range: " << minCostRange << " - " << maxCostRange << ") ===" << std::endl;

    for (int i = 0; i < testSizesCount; i++) {
        int nCities = testSizes[i];
        std::cout << "\nDimension: " << nCities << "x" << nCities << std::endl;
        
        for (int run = 1; run <= runsPerSize; run++) {
            runExperiment(nCities, run, minCostRange, maxCostRange);
        }
    }

    return 0;
}