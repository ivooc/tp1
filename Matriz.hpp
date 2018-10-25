#ifndef _TPPOO_MATRIZ__
#define _TPPOO_MATRIZ__

class Matrix{
  int row;  // numero de matrizes
  int col;  // numero de colunas
  double** pos;  // vetor bidimensional com valores da matriz
public:
  Matriz(int = 0, int = 0, const double &value = 0); // construtor generico default
  Matrix(const Matrix&); // cosntrutor de copia
  int getRows(); // devolve numero de linhas
  int getCols(); // devolve numero de oclunas
  Matrix& unit (); // inicializa matriz com a matriz identidade
  Matrix& zeros(); // modifica todos os elementos para o valor zero
  Matrix& ones (); // modifica todos elementos para o valor um
  Matrix& operator=(const Matrix&); // operador de copia
  double& operator()(const int&,const int&); // retorna elemento pos[x][y] 
  Matrix  operator+ (const Matrix&);  // retorna soma de matrizes
  Matrix  operator- (const Matrix&);  // retorna subtrai matirzes
  Matrix& operator+=(const Matrix&);  // soma matriz em si mesma
  Matrix& operator-=(const Matrix&);  // subtrai matriz em si mesma
  Matrix& operator=~(const Matrix&);  // transpõe matriz
  Matrix& operator*=(const double&);  // multiplicação escalar da propria matriz em si mesma
  Matrix& operator*=(const Matrix&);  // multiplicação vetorial de matrizes em si mesma
  Matrix  operator* (const Matrix&);  // multiplicação
  bool    operator==(const Matrix&);  // comparador de igualdade de matrizes
  bool    operator!=(const Matrix&);  // comparador de diferença de matrizes
  friend ostream& operator<< (ostream&, const Matrix&);  // imprime a matriz
  friend istream& operator>> (istream&, Matrix&);  // entra a matriz
  ~Matrix(); // destroi a matriz
};

#endif
