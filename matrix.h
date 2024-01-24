#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
private:
    int** data;    // Указатель на двумерный массив для хранения данных матрицы
    const int rows_;    // Количество строк
    const int cols_;    // Количество столбцов

public:
    // Конструктор матрицы
    Matrix(const int rows, const int cols);

    // Деструктор матрицы
    ~Matrix();

    // Получение и изменение элемента матрицы по индексам
    int& at(int row, int col);
    const int& at(int row, int col) const;

    // Получение количества строк и столбцов матрицы
    int rows() const;
    int cols() const;

    // Обмен двух строк матрицы
    void swapRows(int row1, int row2);
};

#endif    // MATRIX_H
