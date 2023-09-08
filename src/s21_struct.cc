#include "s21_matrix_oop.h"

// Выделяет память для матрицы
void S21Matrix::s21_create_matrix() {
  if (rows_ == 0 || cols_ == 0)
    matrix_ = nullptr;
  else {
    matrix_ = new double*[rows_];
    int i;
    try {
      for (i = 0; i < rows_; i++) {
        matrix_[i] = new double[cols_];
      }
    } catch (...) {
      for (int j = 0; j < i; j++) delete[] matrix_[j];
      delete[] matrix_;
      throw "Memory error";
    }
  }
}

void S21Matrix::s21_remove_matrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++)
      if (matrix_[i] != nullptr) delete[] matrix_[i];
    delete[] matrix_;
    matrix_ = nullptr;
  }
  rows_ = 0;
  cols_ = 0;
}

// A basic constructor that initialises a matrix of some predefined dimension
S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

// Parametrized constructor with number of rows and columns
S21Matrix::S21Matrix(int rows, int cols)
    : rows_(rows), cols_(cols), matrix_(nullptr) {
  if (rows_ < 1 || cols_ < 1)
    throw std::out_of_range("Row or сolumn out of range!");
  s21_create_matrix();
}

// Copy constructor
S21Matrix::S21Matrix(const S21Matrix& other) : S21Matrix() { *this = other; }

// Move constructor
S21Matrix::S21Matrix(S21Matrix&& other) : S21Matrix() {
  *this = std::move(other);
}

// Destructor
S21Matrix::~S21Matrix() { s21_remove_matrix(); }

int S21Matrix::GetRows() const noexcept { return rows_; }

int S21Matrix::GetCols() const noexcept { return cols_; }

void S21Matrix::SetRows(int rows) {
  if (rows < 1) throw std::out_of_range("Row out of range!");

  S21Matrix temp = std::move(*this);
  rows_ = rows;
  cols_ = temp.cols_;
  s21_create_matrix();
  if (rows_ >= 1 && cols_ >= 1) {
    rows = rows_ < temp.rows_ ? rows_ : temp.rows_;
    for (int i = 0; i < rows_; i++)
      for (int j = 0; j < cols_; j++)
        matrix_[i][j] = i >= temp.rows_ ? 0 : temp.matrix_[i][j];
  }
}

void S21Matrix::SetCols(int cols) {
  if (cols < 1) throw std::out_of_range("Col out of range!");

  S21Matrix temp = std::move(*this);
  rows_ = temp.rows_;
  cols_ = cols;
  s21_create_matrix();
  if (rows_ >= 1 && cols_ >= 1) {
    cols = cols_ < temp.cols_ ? cols_ : temp.cols_;
    for (int i = 0; i < rows_; i++)
      for (int j = 0; j < cols_; j++)
        matrix_[i][j] = j >= temp.cols_ ? 0 : temp.matrix_[i][j];
  }
}
