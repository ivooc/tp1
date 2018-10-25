#include "Matrix.hpp"

/* IVO */
Matrix::Matrix(int = 0, int = 0, const double &value = 0){}
int     Matrix::getRows() inline { return row; }
Matrix& Matrix::unit (){}
Matrix& Matrix::zeros(){}
Matrix  Matrix::operator+ (const Matrix&){}
Matrix& Matrix::operator+=(const Matrix&){}
bool    Matrix::operator==(const Matrix&){}
Matrix& Matrix::operator*=(const Matrix&){}
Matrix& Matrix::operator*=(const double&){}
friend  ostream& operator<< (ostream&, const Matrix&){}

/* BECKER */
Matrix::Matrix(const Matrix&){}
int     Matrix::getCols(){}
Matrix& Matrix::ones (){}
double& Matrix::operator()(const int&, const int&){}
Matrix& Matrix::operator=(const Matrix&){}
Matrix  Matrix::operator- (const Matrix&){}
Matrix& Matrix::operator-=(const Matrix&){}
Matrix& Matrix::operator=~(const Matrix&){}
Matrix  Matrix::operator* (const Matrix&){}
bool    Matrix::operator!=(const Matrix&){}
friend  istream& operator>> (istream&, Matrix&){}
Matrix::~Matrix(){}
