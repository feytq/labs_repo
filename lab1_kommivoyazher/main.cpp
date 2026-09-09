#include <iostream>
using namespace std;
const int N = 5;

void Swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Reverse(int *start, int *end){
    while(start < end){
        Swap(start, end);
        start++;
        end--;
    }
}
void Print(int *P, int n){
    for(int i = 0; i < n; i++){
        cout << P[i] << " ";
    }
    cout << endl;
}
bool Permutation(int *P, int n){
    int i, j;
    for(i = n - 2; i >= 0; i--){
        if (P[i] < P[i + 1]) {
            break;
        }
    }
    if (i < 0){
        return false;
    }
    for(j = n - 1; j > i; j--){
        if(P[i] < P[j]){
            break;
        }
    }
    Swap(&P[i], &P[j]);
    Reverse(&P[i + 1], &P[n - 1]);

    return true;
}

int main(){
    int P[N] = {1, 2, 3, 4, 5};
    Print(P, N);
    while(Permutation(P, N)){
        Print(P, N);
    }
    return 0;
}