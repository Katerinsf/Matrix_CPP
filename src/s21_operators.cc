#include "s21_matrix_oop.h"

// Assignment of values from one matrix to another one (Copy)
S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    s21_remove_matrix();
    rows_ = other.rows_;
    cols_ = other.cols_;
    s21_create_matrix();
    if (rows_ >= 1 && cols_ >= 1) {
      for (int i = 0; i < rows_; i++)
        for (int j = 0; j < cols_; j++) matrix_[i][j] = other.matrix_[i][j];
    }
  }
  return *this;
}

// Assignment of values from one matrix to another one (Move)
S21Matrix& S21Matrix::operator=(S21Matrix&& other) {
  if (this != &other) {
    s21_remove_matrix();
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = other.matrix_;
    other.rows_ = 0;
    other.cols_ = 0;
    other.matrix_ = nullptr;
    // std::cout << "lvalue!\n";
  }
  return *this;
}

// Checks for matrices equality (EqMatrix)
bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }

// Addition of two matrices
S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix res = *this;
  res.SumMatrix(other);
  return res;
}

// Addition assignment (SumMatrix)
S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return *this;
}

// Subtraction of one matrix from another
S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix res = *this;
  res.SubMatrix(other);
  return res;
}

// Difference assignment (SubMatrix)
S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);
  return *this;
}

// Matrix multiplication by a number
S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix res = *this;
  res.MulNumber(num);
  return res;
}

// Number multiplication by a matrix
S21Matrix operator*(const double value, const S21Matrix& matrix) {
  S21Matrix result = matrix;
  result.MulNumber(value);
  return result;
}

// Multiplication assignment (MulNumber)
S21Matrix& S21Matrix::operator*=(const double num) {
  this->MulNumber(num);
  return *this;
}

// Matrix multiplication
S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix res = *this;
  res.MulMatrix(other);
  return res;
}

// Multiplication assignment (MulMatrix)
S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);
  return *this;
}

// Indexation by matrix elements (row, column)
double& S21Matrix::operator()(const int i, const int j) {
  if (i < 0 || j < 0 || i >= rows_ || j >= cols_ || matrix_ == nullptr)
    throw std::out_of_range("Row or сolumn out of range or invalid matrix");
  return matrix_[i][j];
}
