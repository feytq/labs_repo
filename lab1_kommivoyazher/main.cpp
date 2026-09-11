#include <iostream>
#include "Matrix.h"

const int CITIES_COUNT = 10;

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

void print(const int* p, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << p[i] << " ";
    }
    std::cout << std::endl;
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

    for(int i = 0; i < routeSize; i++) {
        cost += matrix[currentCity][route[i]];
        currentCity = route[i];
    }

    cost += matrix[currentCity][startCity];

    return cost;
}

int main() {
    int nCities = CITIES_COUNT;
    int** matrix = createMatrix(nCities);
    fillRandomMatrix(matrix, nCities, 1, 10);

    printMatrix(matrix, nCities);

    int routeSize = nCities - 1;
    int* route = new int[routeSize];
    for (int i = 0; i < routeSize; i++) {
        route[i] = i + 1;
    }

    int minCost = calculateRouteCost(matrix, 0, route, routeSize);

    while (nextPermutation(route, routeSize)) {
        int currentCost = calculateRouteCost(matrix, 0, route, routeSize);
        if (currentCost < minCost) {
            minCost = currentCost;
        }
    }

    std::cout << "Min cost: " << minCost << std::endl;

    delete[] route;
    destroyMatrix(matrix, nCities);

    return 0;
}