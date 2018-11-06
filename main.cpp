#include <iostream>
#include "Matrix.hpp"

using namespace std;

int main (){
  Matrix Y;
  Matrix X(3,1), A(3,3), C(3,3);
  Matrix W = C;
  Matrix Z(A);
  int numeroLinhas = A.getRows();
  int numeroColunas = A.getCols();
  Y.unit(); // inicializa Y com a matriz identidade
  A(2,1)=10; // altera o valor de uma posição de A
  Y.zeros(); // modifica todos os elementos de Y para o valor zero
  C=A+A; // Soma
  C-=A; // Subtração
  A=C-A; // Subtração
  A+=A; // Soma
  A=~C; // A é igual a transposta de C
  X.ones(); // modifica todos os elementos de X com 1s
  X*=2; // multiplicação por uma constante
  C=A*X; // multiplicação de matrizes
  C*=X; // multiplicação de matrizes
  if (A == C); // verifica a igualdade entre A e C
  if(X != Y); // verifica a desigualdade entre A e C
  //cout << C << endl; // Impressão de matrizes
  cin >> Y; // leitura de dados para dentro da matriz Y
  
  return 0 ;
}
