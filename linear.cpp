#include "linear.h"

#include <iostream>

#include "matrix.h"

void printSolution(int* solution, int n) {
    if (!IsSolved) {
        return;
    }
    std::cout << "Solution: ";
    for (int i = 0; i < n; ++i) {
        std::cout << solution[i] << " ";
    }
    std::cout << std::endl;
}

void solveLinearEquationSystem(Matrix& A, int* b, int* solution, int n, int mod) {
    for (int i = 0; i < n; ++i) {
        int pivot = i;
        bool foundPivot = false;

        while (pivot < n) {
            if (A.at(pivot, i) != 0) {
                foundPivot = true;
                break;
            }
            ++pivot;
        }

        if (A.at(i, i) == 0) {
            std::cout << "Error! Singular matrix.";
            return;
        }

        if (pivot != i) {
            for (int j = 0; j < n; ++j) {
                int temp = A.at(i, j);
                A.at(i, j) = A.at(pivot, j);
                A.at(pivot, j) = temp;
            }

            int tempB = b[i];
            b[i] = b[pivot];
            b[pivot] = tempB;
        }

        int pivotElement = A.at(i, i);
        int pivotInverse = 1;
        bool solutionExists = false;

        while (pivotInverse < mod) {
            if ((pivotInverse * pivotElement) % mod == 1) {
                solutionExists = true;
                break;
            }
            ++pivotInverse;
        }

        if (!solutionExists) {
            std::cout << "Error! No solution in the given modulus.";
            return;
        }

        for (int j = i; j < n; ++j) {
            A.at(i, j) = ((A.at(i, j) * pivotInverse) - (A.at(i, j) * pivotInverse / mod) * mod + mod) % mod;
            while (A.at(i, j) >= mod) {
                A.at(i, j) -= mod;
            }
        }

        b[i] = ((b[i] * pivotInverse) - (b[i] * pivotInverse / mod) * mod + mod) % mod;
        while (b[i] >= mod) {
            b[i] -= mod;
        }

        for (int k = 0; k < n; ++k) {
            if (k != i) {
                int factor = A.at(k, i);

                for (int j = i; j < n; ++j) {
                    A.at(k, j) = (A.at(k, j) - factor * A.at(i, j) + mod) % mod;
                    while (A.at(k, j) >= mod) {
                        A.at(k, j) -= mod;
                    }
                }

                b[k] = (b[k] - factor * b[i] + mod) % mod;
                while (b[k] >= mod) {
                    b[k] -= mod;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        solution[i] = b[i];
    }
    IsSolved = true;
}
