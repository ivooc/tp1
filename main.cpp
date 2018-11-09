#include <iostream>
#include "Matrix.hpp"

using namespace std;

int main (){

  Matrix Y;
  Matrix X(3,1), A(3,3), B(4,4,5), C(3,3);
  Matrix W = C;
  Matrix Z(A);
  int numeroLinhas = A.getRows();
  int numeroColunas = A.getCols();
  cout << numeroLinhas << endl;
  cout << numeroColunas << endl;
  B.unit(); // inicializa Y com a matriz identidade
  A.ones(); // inicializa A com 1 em todas as posicoes
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
  if (A == C){// verifica a igualdade entre A e C
    cout << "A == C"<<endl;
  }
  else{
    cout <<"A != C"<<endl;
  }
  if(X != Y){// verifica a desigualdade entre X e Y
    cout << "X != Y"<<endl;
  }
  else{
    cout <<"X == Y"<<endl;
  }
  Y = W;
  cin >> Y; // leitura de dados para dentro da matriz Y
  cout << Y << endl; // Impressão de matrizes

  return 0 ;
}
