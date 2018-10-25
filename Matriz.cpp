#include "Matrix.hpp"

/* IVO */
Matrix::Matrix(int = 0, int = 0, const double &value = 0){}
int Matrix::getRows() inline { return row; }
Matrix& Matrix::unit (){}
Matrix& Matrix::zeros(){}
Matrix  Matrix::operator+ (const Matrix&){}
Matrix& Matrix::operator+=(const Matrix&){}
bool    Matrix::operator==(const Matrix&){}
Matrix& Matrix::operator*=(const Matrix&){}
Matrix& Matrix::operator*=(const double&){}
friend ostream& operator<< (ostream&, const Matrix&){}

/* BECKER */
Matrix::Matrix(const Matrix&){}
int Matrix::getCols(){}
Matrix& Matrix::ones (){}
Matrix& Matrix::operator=(const Matrix&){}
Matrix  Matrix::operator- (const Matrix&){}
Matrix& Matrix::operator-=(const Matrix&){}
Matrix& Matrix::operator=~(const Matrix&){}
Matrix  Matrix::operator* (const Matrix&){}
bool    Matrix::operator!=(const Matrix&){}
friend istream& operator>> (istream&, Matrix&){}
Matrix::~Matrix(){}

/* PROFESSOR */
  /* A(2,1) = 10*/
  double& operator()(int, int, double) (double, double) /* operador()??
                                                        A(2,1)
                      A.pos[2][1]=10  // altera o valor de uma posição de A
                                                                          */
