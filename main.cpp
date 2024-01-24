#include <chrono>
#include <iostream>

#include "linear.h"
#include "matrix.h"

void print(int n, Matrix matrix) {
    for (int i{}; i < n; i++) {
        std::cout
    }
}

int main() {
    int n = 3, mod;
    std::cout << "Enter the size of the matrix: ";

    Matrix matrix(n, n);
    int* vectorA = new int[n * n]{ 4, -7, 8, 2, -4, 5, -3, 11, 1 };
    int* vectorB = new int[n]{ -23, -13, 16 };
    int* solution = new int[n];
    /*std::cout << "Enter the elements of the matrix: " << std::endl;
   for (int i = 0; i < n; ++i) {
       for (int j = 0; j < n; ++j) {
           std::cin >> matrix.at(i,j);
       }
   }

   std::cout << "Enter the elements of the vector b: " << std::endl;
   for (int i = 0; i < n; ++i) {
       std::cin >> vectorB[i];
   }*/

    std::cout << "Enter the elements of the matrix: " << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            srand(time(NULL) + rand());
            // matrix.at(i, j) = rand() % 100;
            matrix.at(i, j) = vectorA[i + j];
            // std::cout << matrix.at(i, j) << std::endl;
            print(n, matrix);
        }
    }

    std::cout << "Enter the elements of the vector b: " << std::endl;
    for (int i = 0; i < n; ++i) {
        // srand(time(NULL) + rand());
        // vectorB[i] = rand() % 100;
        std::cout << vectorB[i] << std::endl;
    }

    std::cout << "Enter the modulus: ";
    mod = 1;

    auto start = std::chrono::high_resolution_clock::now();
    solveLinearEquationSystem(matrix, vectorB, solution, n, mod);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
    printSolution(solution, n);
    std::cout << "Time taken by function: " << (duration.count() * 1000) << " milliseconds" << std::endl;

    delete[] vectorB;
    delete[] solution;

    return 0;
}
