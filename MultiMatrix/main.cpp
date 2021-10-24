#include <iostream>

int minMultiMatrix(int n, const int *d) {
    int **M = new int*[n + 1];
    int **P = new int*[n + 1];

    for (int i = 0; i < n + 1; i++) {
        M[i] = new int[n + 1];
        P[i] = new int[n + 1];
        for (int j = 0; j < n + 1; j++) {
            M[i][j] = 9999999;
            M[i][i] = 0;
            P[i][j] = 9999999;
        }
    }

    for(int diagonal = 1; diagonal <= n; diagonal++) {
        for(int i = 1; i <= n - diagonal; i++) {
            int j = i + diagonal;
            for(int k = i; k < j; k++) {
                if(M[i][j] > M[i][k] + M[k + 1][j] + (d[i - 1] * d[k] * d[j])) {
                    M[i][j] = M[i][k] + M[k + 1][j] + (d[i - 1] * d[k] * d[j]);
                    P[i][j] = k;
                }
            }
        }
    }

    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            std::cout << M[i][j] << "  ";
        }
        std::cout << "\n";
    }

    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            std::cout << P[i][j] << "  ";
        }
        std::cout << "\n";
    }
    return 0;
}

int main() {
    int d[] = {10, 4, 5, 20, 2, 50};
    minMultiMatrix(5, d);

    return 0;
}
