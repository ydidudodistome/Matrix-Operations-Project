#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    vector<vector<double>> data;
    size_t rows;
    size_t cols;

public:

    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

    Matrix(size_t rows, size_t cols);
    Matrix(size_t rows, size_t cols, const vector<vector<double>>& values);

    double& operator()(size_t row, size_t col);
    const double& operator()(size_t row, size_t col) const;

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;

    Matrix transpose() const;

    void display() const;

    class MatrixException : public exception {
    public:
        const char* what() const noexcept override {
            return "Matrix index out of bounds";
        }
    };
};

ostream& operator<<(ostream& os, const Matrix& matrix);

istream& operator>>(istream& is, Matrix& matrix);


#endif 
