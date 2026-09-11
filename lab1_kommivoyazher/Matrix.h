#pragma once

int** createMatrix(int nCities);
void destroyMatrix(int** matrix, int nCities);
void fillRandomMatrix(int** matrix, int nCities, int minCost, int maxCost);
void printMatrix(int** matrix, int nCities);