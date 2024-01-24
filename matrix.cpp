#include "matrix.h"

// Конструктор матрицы
Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
    // Выделение памяти под двумерный массив (матрицу)
    data = new int*[rows_];
    for (int i = 0; i < rows_; ++i) {
        // Выделение памяти для каждой строки матрицы
        data[i] = new int[cols_];
        // Инициализация значений элементов матрицы нулями
        for (int j = 0; j < cols_; ++j) {
            data[i][j] = 0;
        }
    }
}

// Деструктор матрицы
Matrix::~Matrix() {
    // Освобождение выделенной памяти для каждой строки
    for (int i = 0; i < rows_; ++i) {
        delete[] data[i];
    }
    // Освобождение выделенной памяти для массива указателей строк
    delete[] data;
}

// Получение элемента матрицы по индексам для изменения
int& Matrix::at(int row, int col) {
    return data[row][col];
}

// Получение элемента матрицы по индексам для чтения
const int& Matrix::at(int row, int col) const {
    return data[row][col];
}

// Получение количества строк в матрице
int Matrix::rows() const {
    return rows_;
}

// Получение количества столбцов в матрице
int Matrix::cols() const {
    return cols_;
}

// Обмен двух строк матрицы
void Matrix::swapRows(int row1, int row2) {
    if (row1 >= 0 && row1 < rows_ && row2 >= 0 && row2 < rows_) {
        // Обмен указателей на строки матрицы
        int* tempRow = data[row1];
        data[row1] = data[row2];
        data[row2] = tempRow;
    }
}
