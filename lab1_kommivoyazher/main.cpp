#include <chrono>
#include <iostream>
#include "Matrix.h"
#include "KommivoyazherSolver.h"

void runTest(int nCities) {
    unsigned long long iterationsCount = 1;

    int** matrix = createMatrix(nCities);
    fillRandomMatrix(matrix, nCities, 1, 10);

    printMatrix(matrix, nCities);

    int routeSize = nCities - 1;
    int* route = new int[routeSize];
    for (int i = 0; i < routeSize; i++) {
        route[i] = i + 1;
    }

    int firstCost = calculateRouteCost(matrix, 0, route, routeSize);
    int minCost = firstCost;
    int maxCost = firstCost;

    const auto startTime = std::chrono::high_resolution_clock::now();

    while (nextPermutation(route, routeSize)) {
        int currentCost = calculateRouteCost(matrix, 0, route, routeSize);
        if (currentCost < minCost) {
            minCost = currentCost;
        }
        if (currentCost > maxCost) {
            maxCost = currentCost;
        }
        iterationsCount++;
    }

    const auto endTime = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> elapsedTime = endTime - startTime;

    std::cout << "Min cost: " << minCost << std::endl;
    std::cout << "Max cost: " << maxCost << std::endl;
    std::cout << "Iterations: " << iterationsCount << std::endl;
    std::cout << "Elapsed time: " << elapsedTime.count() << " seconds" << std::endl;

    delete[] route;
    destroyMatrix(matrix, nCities);
}

int main() {
    int testSizes[] = {4, 6, 8, 10, 11, 12};

    int testSizesCount = sizeof(testSizes) / sizeof(testSizes[0]);
    for (int i = 0; i < testSizesCount; i++) {
        int nCities = testSizes[i];
        runTest(nCities);
        std::cout << std::endl;
    }

    return 0;
}