#include <random>
#include <iostream>
#include "matrix.h"

int** createMatrix(int nCities) {
    int** matrix = new int*[nCities];
    for (int i = 0; i < nCities; i++) {
        matrix[i] = new int[nCities];
    }
    return matrix;
}

void destroyMatrix(int** matrix, int nCities) {
    for (int i = 0; i < nCities; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void fillRandomMatrix(int** matrix, int nCities, int minCost, int maxCost) {
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<int> distribution(minCost, maxCost);

    for (int i = 0; i < nCities; i++) {
        for (int j = 0; j < nCities; j++) {
            if (i == j) {
                matrix[i][j] = 0;
            } else {
                matrix[i][j] = distribution(generator);
            }
        }
    }
}

void printMatrix(int** matrix, int nCities) {
    for (int i = 0; i < nCities; i++) {
        for (int j = 0; j < nCities; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}