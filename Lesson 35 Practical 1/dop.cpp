#include "dop.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void Matrix::allocateMemory() {
    if (rows > 0 && cols > 0) {
        data = new int* [rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }
    else {
        data = nullptr;
    }
}

void Matrix::freeMemory() {
    if (data != nullptr) {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
}

Matrix::Matrix() : rows(0), cols(0), data(nullptr) {}

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    allocateMemory();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = rand() % 100;
        }
    }
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    allocateMemory();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = other.data[i][j];
        }
    }
}

Matrix::~Matrix() {
    freeMemory();
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;

    freeMemory();

    rows = other.rows;
    cols = other.cols;
    allocateMemory();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = other.data[i][j];
        }
    }

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    os << m.rows << " " << m.cols << "\n";

    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            os << m.data[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Matrix& m) {
    m.freeMemory();

    is >> m.rows >> m.cols;
    m.allocateMemory();

    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            is >> m.data[i][j];
        }
    }
    return is;
}