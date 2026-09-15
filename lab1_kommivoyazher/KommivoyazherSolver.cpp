#include "KommivoyazherSolver.h"
#include "Matrix.h"
#include <chrono>

namespace {

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void reverse(int* p, int start, int end) {
    while (start < end) {
        swap(p[start], p[end]);
        start++;
        end--;
    }
}

bool nextPermutation(int* p, int n) {
    int i;
    for (i = n - 2; i >= 0; i--) {
        if (p[i] < p[i + 1]) {
            break;
        }
    }

    if (i < 0) {
        return false;
    }

    int j;
    for (j = n - 1; j > i; j--) {
        if (p[i] < p[j]) {
            break;
        }
    }

    swap(p[i], p[j]);
    reverse(p, i + 1, n - 1);

    return true;
}

int calculateRouteCost(int** matrix, int startCity, const int* route, int routeSize) {
    int cost = 0;
    int currentCity = startCity;

    for (int i = 0; i < routeSize; i++) {
        cost += matrix[currentCity][route[i]];
        currentCity = route[i];
    }

    cost += matrix[currentCity][startCity];

    return cost;
}

} // anonymous namespace

ExactResult solveBruteForce(int** matrix, int nCities, int startCity) {
    int routeSize = nCities - 1;
    int* route = new int[routeSize];
    int idx = 0;
    for (int i = 0; i < nCities; i++) {
        if (i != startCity) {
            route[idx++] = i;
        }
    }

    const auto startTime = std::chrono::high_resolution_clock::now();

    int firstCost = calculateRouteCost(matrix, startCity, route, routeSize);
    int minCost = firstCost;
    int maxCost = firstCost;

    while (nextPermutation(route, routeSize)) {
        int currentCost = calculateRouteCost(matrix, startCity, route, routeSize);
        if (currentCost < minCost) {
            minCost = currentCost;
        }
        if (currentCost > maxCost) {
            maxCost = currentCost;
        }
    }

    const auto endTime = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> elapsedTime = endTime - startTime;

    delete[] route;
    return {minCost, maxCost, elapsedTime.count()};
}

GreedyResult solveGreedy(int** matrix, int nCities, int startCity) {
    int totalCost = 0;
    int currentCity = startCity;

    int routeSize = nCities - 1;
    int* route = new int[routeSize];
    int idx = 0;
    for (int i = 0; i < nCities; i++) {
        if (i != startCity) {
            route[idx++] = i;
        }
    }

    const auto startTime = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < routeSize; i++) {
        int bestIndex = i;
        int minCost = matrix[currentCity][route[i]];

        for (int j = i + 1; j < routeSize; j++) {
            int cost = matrix[currentCity][route[j]];
            if (cost < minCost) {
                minCost = cost;
                bestIndex = j;
            }
        }
        swap(route[i], route[bestIndex]);

        totalCost += minCost;
        currentCity = route[i];
    }
 
    totalCost += matrix[currentCity][startCity];

    const auto endTime = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> elapsedTime = endTime - startTime;

    delete[] route;
    return {totalCost, elapsedTime.count()};
}

double calculateQuality(int minCost, int maxCost, int greedyCost) {
    if (maxCost == minCost) {
        return 100.0;
    }
    return (static_cast<double>(maxCost - greedyCost) / (maxCost - minCost)) * 100.0;
}