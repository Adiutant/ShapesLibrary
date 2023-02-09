//
// Created by rlego on 09.02.2023.
//

#ifndef GEOMETRYLIBRARY_MATRIX_H
#define GEOMETRYLIBRARY_MATRIX_H
#include <stdfix.h>
#include <vector>
#include <iostream>

class Matrix {
public:
    inline bool operator == (const Matrix& other) const;

    Matrix() = default;
    explicit Matrix(const Matrix* other);
    ~Matrix() = default;

    void Reset(int num_rows, int num_col);

    Matrix(int num_rows,int num_col);

    inline  std::vector<double>& operator[](size_t index){
        return _vector[index];
    }
    Matrix GetMinorMatrix();
    void Transpose();

    Matrix getReverseMatrix(double);

    inline Matrix operator*( Matrix other) const;

    
   inline double At(int row, int col) const {
         return _vector[row][col];
    }

    inline int GetNumRows() const {
        return int(_vector.size());
    }
    inline int GetNumCol() const {
        try {
            return  int(_vector[0].size());

        }
        catch (std::exception&) {
            return 0;
        }
    }

private:
    std::vector<std::vector<double>> _vector = {};
    void swap(double& a, double& b);



};

bool Matrix::operator==(const Matrix& other) const  {
    if (GetNumRows() != other.GetNumRows()) { return false; }
    if (GetNumCol() != other.GetNumCol()) { return false; }
    int rows = GetNumRows();
    int col = GetNumCol();
    for (int i = 0; i < rows;i++) {
        for (int j = 0; j < col; j++) {
            if (At(i,j) != other.At(i, j)) { return false; }
        }
    }
    return true;
}

Matrix Matrix::operator*( Matrix other) const {
    Matrix result(this->GetNumRows(),other.GetNumCol() );
    int rows = this->GetNumRows();
    int col = this->GetNumCol();
    for (int i = 0; i < rows;i++) {
        for (int j = 0; j < col; j++) {
            result[i][j % other.GetNumCol()] +=  this->At(i,j) * other[j][i % other.GetNumCol()];
        }
    }
    return result;
}


#endif //GEOMETRYLIBRARY_MATRIX_H
