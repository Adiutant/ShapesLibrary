//
// Created by rlego on 09.02.2023.
//

#include "Matrix.h"
using namespace std;

Matrix::Matrix(int num_rows, int num_col)  {
    if (num_rows < 0 || num_col < 0) { throw out_of_range(""); }
    for (int i = 0; i < num_rows; i++) {
        vector<double> proxyVector = {};
        for (int j = 0; j < num_col; j++) {
            proxyVector.push_back(0);
        }
        _vector.push_back(proxyVector);
    }
}


Matrix Matrix::getReverseMatrix(double determinant) {
    Matrix result(this);
    int rows = result.GetNumRows();
    int col = result.GetNumCol();
    for (int i = 0; i < rows;i++) {
        for (int j = 0; j < col; j++) {
            result[i][j] /=determinant;
        }
    }
    return result;

}

void Matrix::Transpose() {
    swap(_vector[0][1], _vector[1][0]);
}

void Matrix::swap(double &a, double &b) {
    double tmp = b;
    b = a;
    a =tmp;
}


Matrix Matrix::GetMinorMatrix()  {
    Matrix result(this);
    swap(result[0][0], result[1][1]);
    swap(result[0][1], result[1][0]);
    return result;

}

Matrix::Matrix(const Matrix *other) {
    _vector = other->_vector;
}


void Matrix::Reset(int num_rows, int num_col)
{
    if (num_rows < 0 || num_col < 0) { throw out_of_range(""); }
    _vector = {};
    for (int i = 0; i < num_rows; i++) {
        vector<double> proxyVector = {};
        for (int j = 0; j < num_col; j++) {

            proxyVector.push_back(0);
        }
        _vector.push_back(proxyVector);
    }
}



