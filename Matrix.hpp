#ifndef _TPPOO_MATRIZ__
#define _TPPOO_MATRIZ__

#include <iostream>
#include <iomanip>

using namespace std;

class Matrix{
  int rows;  // numero de linhas
  int cols;  // numero de colunas
  double* pos;  // vetor unidimensional com valores da matriz
  int index(int row, int col) const { return col + cols * row; }
  int getIndexCol (int index) const { return index % cols; }
  int getIndexRow (int index) const { return index / cols; }
  double getValueAt(int row, int col) const { return pos[index(row, col)]; }
  void setValueAt(int row, int col, const double &value);
  void setValueAt(int index, const double &value);
public:
  Matrix(int = 0, int = 0, const double& = 0.0); // construtor generico default
  Matrix(const Matrix&); // construtor de copia
  int getRows() const { return rows; } // devolve numero de linhas
  int getCols() const { return cols; } // devolve numero de colunas
  Matrix& unit (); // inicializa matriz com a matriz identidade
  Matrix& zeros(); // modifica todos os elementos para o valor zero
  Matrix& ones (); // modifica todos elementos para o valor um
  Matrix& operator=(const Matrix&); // operador de copia
  double& operator()(const int&,const int&); // retorna elemento pos[x][y]
  const Matrix  operator+ (const Matrix&) const;  // retorna soma de matrizes
  const Matrix  operator- (const Matrix&) const;  // retorna subtrai matirzes
  Matrix& operator+=(const Matrix&);  // soma matriz em si mesma
  Matrix& operator-=(const Matrix&);  // subtrai matriz em si mesma
  Matrix& operator~() ;  // transp�e matriz
  Matrix& operator*=(const double&);  // multiplicacao escalar da propria matriz em si mesma
  Matrix& operator*=(const Matrix&);  // multiplicacao vetorial de matrizes em si mesma
  const Matrix  operator* (const Matrix&) const;  // multiplicacao
  bool    operator==(const Matrix&);  // comparador de igualdade de matrizes
  bool    operator!=(const Matrix&);  // comparador de diferenca de matrizes
  friend ostream& operator<< (ostream&, const Matrix&);  // imprime a matriz
  friend istream& operator>> (istream&, Matrix&);  // entra a matriz
  ~Matrix() { delete[] pos; }; // destroi a matriz
};

#endif
