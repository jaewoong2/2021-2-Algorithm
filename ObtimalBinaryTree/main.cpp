#include <iostream>

float sum(const float *p, int start, int end) {
    float s = 0;
    for(int i = start; i < end + 1; i++) {
        s += p[i];
    }

    return s;
}

void optimalBinarySearchTree(int n, float *p) {
    // initialize code
    float **A = new float*[n + 2]; // 0 ~ n + 1
    int **R = new int*[n + 2];

    for(int i = 0; i < n + 2; i++) {
        A[i] = new float[n + 1]; // 0 ~ n
        R[i] = new int[n + 1];
    }

    for (int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 1; j++) {
            if(i == 0) {
                A[i][j] = float(j);
            } else {
                A[i][j] = 99999;
            }
            R[i][j] = 0;
        }
    }

    // main code
    for(int i = 1; i < n + 1; i++) {
        A[i][i - 1] = 0;
        A[i][i] = p[i];
        R[i][i] = i;
        R[i][i - 1]  = 0;
    }

    A[n + 1][n] = 0;
    R[n + 1][n] = 0;

    for(int diagonal = 1; diagonal < n; diagonal++) {
        for (int i = 1; i < n - diagonal + 1; i++) {
            int j = i + diagonal;
            for (int k = i; k < j + 1; k++) {
                if(A[i][j] > A[i][k - 1] + A[k + 1][j] + sum(p, i, j)) {
                    A[i][j] = A[i][k - 1] + A[k + 1][j] + sum(p, i, j);
                    R[i][j] = k;
                }
            }
        }
    }

    for(int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 1; j++) {
            std::cout << A[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "\n";

    for(int i = 0; i < n + 2; i++) {
        for (int j = 0; j < n + 1; j++) {
            std::cout << R[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    const int N = 4;
    float a[] = {0, 0.125 * 3, 0.125 * 3, 0.125, 0.125};


    optimalBinarySearchTree(N, a);
    return 0;
}

