#include "Matrix.hpp"

using namespace std;


Matrix::Matrix(size_t rows, size_t cols) : rows(rows), cols(cols), data(rows, vector<double>(cols, 0.0)) {}

Matrix::Matrix(size_t rows, size_t cols, const vector<vector<double>>& values) : rows(rows), cols(cols), data(values) {}


double& Matrix::operator()(size_t row, size_t col) {
    if (row >= rows || col >= cols) {
        throw MatrixException();
    }
    return data[row][col];
}

const double& Matrix::operator()(size_t row, size_t col) const {
    if (row >= rows || col >= cols) {
        throw MatrixException();
    }
    return data[row][col];
}


Matrix Matrix::operator+(const Matrix& other) const {
    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        cerr << "Invalid matrix dimensions for multiplication." << endl;
        exit(EXIT_FAILURE);
    }

    Matrix result(rows, other.cols);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < other.cols; j++) {
            for (size_t k = 0; k < cols; k++) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}


Matrix Matrix::transpose() const {
    Matrix result(cols, rows);
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            result.data[j][i] = data[i][j];
        }
    }
    return result;
}


void Matrix::display() const {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            cout << data[i][j] << "\t";
        }
        cout << endl;
    }
}


ostream& operator<<(ostream& os, const Matrix& matrix) {
    for (size_t i = 0; i < matrix.getRows(); i++) {
        for (size_t j = 0; j < matrix.getCols(); j++) {
            os << matrix(i, j) << "\t";
        }
        os << endl;
    }
    return os;
}


istream& operator>>(istream& is, Matrix& matrix) {
    for (size_t i = 0; i < matrix.getRows(); i++) {
        for (size_t j = 0; j < matrix.getCols(); j++) {
            cout << "Enter value for matrix[" << i << "][" << j << "]: ";
            is >> matrix(i, j);
        }
    }
    return is;
}
