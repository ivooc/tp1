#include "Matrix.hpp"

/* IVO */
Matrix::Matrix(int Rows, int Cols, const double &value){
    rows = Rows;
    cols = Cols;
    pos = new double[rows*cols];
    for (int i = 0; i < (rows*cols); i++)
        pos[i] = value;
}

// funcoes implementadas inline no header

//int Matrix::getRows(){}
//int Matrix::index(int row, int col) const {}
//int Matrix::getIndexCol (int index) const {}
//int Matrix::getIndexRow (int index) const {}
//double Matrix::getValueAt(int row, int col) const {}

void Matrix::setValueAt(int row, int col, const double &value){
    if (col < cols && row < rows)
        pos[index(row, col)] = value;
}
void Matrix::setValueAt(int index, const double &value){
    if (index < (rows*cols))
        pos[index] = value;
}
Matrix& Matrix::unit(){
    if (rows == cols)
        for (int i = 0; i < (rows*cols); i++){
            if (getIndexRow(i) == getIndexCol(i))
                pos[i] = 1;
            else
                pos[i] = 0;
        }
    return *this;
}
Matrix& Matrix::zeros(){
    for (int i = 0; i < (rows*cols); i++)
        pos[i] = 0;
    return *this;
}
const Matrix Matrix::operator+(const Matrix& m) const{
    Matrix result(*this);
    if (rows == m.rows && cols == m.cols){
        for (int i = 0; i < (rows*cols); i++){
            result.pos[i] += m.pos[i];
        }
    }
    return result;
}
Matrix& Matrix::operator+=(const Matrix& m){
    if (rows == m.rows && cols == m.cols){
        for (int i = 0; i < (rows*cols); i++){
            pos[i] += m.pos[i];
        }
    }
    return *this;
}
bool Matrix::operator==(const Matrix& m){
    if (rows == m.rows && cols == m.cols){
        for (int i = 0; i < (rows*cols); i++){
            if (pos[i] != m.pos[i])
                return false;
        }
        return true;
    }
    return false;
}
Matrix& Matrix::operator*=(const Matrix& m){}
Matrix& Matrix::operator*=(const double& value){}
ostream& operator<< (ostream& out, const Matrix& m){}

/* BECKER */
Matrix::Matrix(const Matrix& m){
 rows = m.getRows();
 cols = m.getCols();
 delete[] pos;
 pos = new double[rows*cols];
 for(int ii = 0; ii<m.getRows()*m.getCols(); ii++){
    pos[ii] = m.pos[ii];
  }
}
Matrix& Matrix::ones (){
  for(int ii = 0; ii<rows*cols; ii++){
      pos[ii] = 1;
    }
  return *this;
}
double& Matrix::operator()(const int& r, const int& c){
  return pos[index(r,c)];
}
Matrix& Matrix::operator=(const Matrix& m){
  if (this == &m) return *this;
  delete[] pos;
  rows = m.getRows();
  cols = m.getCols();
  pos = new double[rows*cols];
  for (int ii = 0; ii<rows*cols; ii++){
    pos[ii] = m.pos[ii];
  }
  return *this;
}
const Matrix  Matrix::operator- (const Matrix& m) const{
  Matrix result(*this);
  if (rows!=m.getRows() || cols!=m.getCols()) {
    for(int ii=0; ii<cols*rows; ii++){
      result.pos[ii]-=m.pos[ii];
    }
  }
  return result;
}
Matrix& Matrix::operator-=(const Matrix& m){
  if (rows!=m.getRows() || cols!=m.getCols()){
    for(int ii=0; ii<cols*rows; ii++){
      pos[ii]-=m.pos[ii];
    }
  }
  return *this;

}
Matrix& Matrix::operator~(){/*
  cols=m.getCols();
  rows=m.getRows();
  delete[] pos;
  pos = new double[rows*cols];
  for(int ii=0, ii< rows, ii++){
    for(int jj = 0, jj<=cols, jj++){
      *this(ii,jj) = m(jj,ii);
      *this(jj,ii) = m(ii,jj);
    }
  }
*/  return *this;}
const Matrix Matrix::operator* (const Matrix& m) const {}
bool Matrix::operator!=(const Matrix& m){}
istream& operator>> (istream& op, Matrix& m){}
Matrix::~Matrix(){}
