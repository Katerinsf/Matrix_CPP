#include <iomanip>
#include <random>

#include "s21_matrix_oop.h"

void print_matrix(S21Matrix &A);
void index_init(S21Matrix &A);
void up_init(S21Matrix &A, double a);
void low_init(S21Matrix &A, double a);
void diag_init(S21Matrix &A, double a);
void rand_init(S21Matrix &A);

int main() {
  try {
    S21Matrix A;
    A(1, 2);
  } catch (std::out_of_range &er) {
    std::cout << er.what() << "\n";
  } catch (const char *str) {
    std::cout << str << "\n";
  }

  return 0;
}

void print_matrix(S21Matrix &A) {
  if (A.GetRows() > 0 && A.GetCols() > 0) {
    for (int i = 0; i < A.GetRows(); i++) {
      for (int j = 0; j < A.GetCols(); j++)
        std::cout << (std::round(A(i, j) * 100) / 100) << "\t";
      std::cout << "\n";
    }
  } else
    std::cout << "Empty matr\n";
}

// Заполняем матрицу числами с номерами элементов(отсчет с 1)
void index_init(S21Matrix &A) {
  for (int i = 0; i < A.GetRows(); i++)
    for (int j = 0; j < A.GetCols(); j++) A(i, j) = (i + 1) * 10 + (j + 1);
}

void up_init(S21Matrix &A, double a) {
  for (int i = 0; i < A.GetRows(); i++)
    for (int j = 0; j < A.GetCols(); j++) {
      if (i <= j)
        A(i, j) = a;
      else
        A(i, j) = 0;
    }
}

void low_init(S21Matrix &A, double a) {
  for (int i = 0; i < A.GetRows(); i++)
    for (int j = 0; j < A.GetCols(); j++) {
      if (i >= j)
        A(i, j) = a;
      else
        A(i, j) = 0;
    }
}

void diag_init(S21Matrix &A, double a) {
  for (int i = 0; i < A.GetRows(); i++)
    for (int j = 0; j < A.GetCols(); j++) {
      if (i == j) A(i, j) = a;
    }
}

void rand_init(S21Matrix &A) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dist(1.0, 100.0);

  for (int i = 0; i < A.GetRows(); i++)
    for (int j = 0; j < A.GetCols(); j++) A(i, j) = dist(gen);
  // A(i, j) = (double)rand() / RAND_MAX * 10;
  // A(i, j) = rand() % 11;
}
