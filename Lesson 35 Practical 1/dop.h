#pragma once
#include <iostream>

class Matrix {
private:
    int rows;
    int cols;
    int** data;

    void allocateMemory();
    void freeMemory();

public:
    Matrix();
    Matrix(int r, int c);
    Matrix(const Matrix& other);
    ~Matrix();
    Matrix& operator=(const Matrix& other);

    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
    friend std::istream& operator>>(std::istream& is, Matrix& m);
};