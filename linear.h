#ifndef LINEAR_H
#define LINEAR_H
#include "matrix.h"

static bool IsSolved = false;
void printSolution(int* solution, int n);
void solveLinearEquationSystem(Matrix& A, int* b, int* solution, int n, int mod);

#endif    // LINEAR_H
