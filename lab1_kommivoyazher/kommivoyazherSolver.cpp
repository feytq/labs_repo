#include "KommivoyazherSolver.h"
#include "Matrix.h"

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

