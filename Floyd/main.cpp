#include <iostream>



int main() {
    const int NUMBER = 5;
    const int MAXINT = 99999;
    int **D = new int*[NUMBER];
    int **P = new int*[NUMBER];
    int W[5][5] = { {0, 1, MAXINT, 1, 5 },
          {9, 0, 3, 2, MAXINT },
          {MAXINT, MAXINT, 0, 4, MAXINT },
          {MAXINT, MAXINT, 2, 0, 3 },
          {3, MAXINT, MAXINT, MAXINT, 0 }};

    for (int i = 0; i < NUMBER; i++) {
        D[i] = new int[NUMBER];
        P[i] = new int[NUMBER];
    }

    for (int i = 0; i < NUMBER; i++) {
        for (int j = 0; j < NUMBER; j++) {
            D[i][j] = W[i][j];
            P[i][j] = 0;
        }
    }

    for (int k = 0; k < NUMBER; k++) {
        for (int i = 0; i < NUMBER; i++) {
            for (int j = 0; j < NUMBER; j++) {
                int path = D[i][k] + D[k][j];
                if (D[i][j] > path) {
                    D[i][j] = path;
                    P[i][j] = k + 1;
                }
            }
        }
        for (int i = 0; i < NUMBER; i++) {
            for (int j = 0; j < NUMBER; j++) {
                std::cout << D[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    std::cout << "\n";
    std::cout << "\n";



    for (int i = 0; i < NUMBER; i++) {
        for (int j = 0; j < NUMBER; j++) {
            std::cout << P[i][j] << " ";
        }
        std::cout << "\n";
    }


    return 0;
}
