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
                pos[i] = 1.0;
            else
                pos[i] = 0.0;
        }
    return *this;
}
Matrix& Matrix::zeros(){
    for (int i = 0; i < (rows*cols); i++)
        pos[i] = 0.0;
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
Matrix& Matrix::operator*=(const Matrix& m){
    if (cols == m.rows){
        Matrix aux(*this);
        if (rows != m.rows || cols != m.cols){
            cols = m.cols;
            if (pos != nullptr) delete[] pos;
            pos = new double[rows*cols];
        }
        zeros();
        for (int rowLeft = 0; rowLeft < aux.rows; rowLeft++)
            for (int colRight = 0; colRight < m.cols; colRight++)
                for (int element = 0; element < aux.cols; element++)
                    pos[index(rowLeft, colRight)] +=
                        aux.pos[index(rowLeft, element)] * m.pos[index(element, colRight)];

    }
    return *this;
}
Matrix& Matrix::operator*=(const double& value){
    for (int i = 0; i < (rows*cols); i++)
        pos[i] *= value;
    return *this;
}
ostream& operator<< (ostream& out, const Matrix& m){
    out << setprecision(1) << fixed;
    for (int i = 0; i < (m.rows*m.cols); i++){
        if (m.getIndexCol(i) == 0) out << "| ";
        out << m.pos[i] << " ";
        if (m.getIndexCol(i) == (m.cols - 1)) out << "|" << endl;
    }
    return out;
}

/* BECKER */
Matrix::Matrix(const Matrix& m){
    rows = m.getRows();
    cols = m.getCols();
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
  return pos[index(r-1,c-1)];
}
Matrix& Matrix::operator=(const Matrix& m){
  if (this != &m) {
    delete[] pos;
    rows = m.getRows();
    cols = m.getCols();
    pos = new double[rows*cols];
    for (int ii = 0; ii<rows*cols; ii++){
        pos[ii] = m.pos[ii];
    }
  }
  return *this;
}
const Matrix  Matrix::operator- (const Matrix& m) const{
  Matrix result(*this);
  if (rows==m.getRows() && cols==m.getCols()) {
    for(int ii=0; ii<cols*rows; ii++){
      result.pos[ii]-=m.pos[ii];
    }
  }
  return result;
}
Matrix& Matrix::operator-=(const Matrix& m){
  if (rows==m.getRows() && cols==m.getCols()){
    for(int ii=0; ii<cols*rows; ii++){
      pos[ii]-=m.pos[ii];
    }
  }
  return *this;

}
Matrix& Matrix::operator~(){
  double aux;
  for(int ii=0; ii< rows; ii++){
    for(int jj = 0; jj<ii; jj++){
        aux =  pos[index(jj,ii)];
        pos[index(jj,ii)] = pos[index(ii,jj)];
        pos[index(ii,jj)] = aux;
    }
  }
  return *this;
}
const Matrix Matrix::operator* (const Matrix& m) const {
    if(cols!=m.getRows()  ){ return *this; }
    int _r = getRows();
    int _c = m.getCols();
    Matrix result( _r, _c);
    // Percorre matrix resultante
    for(int rr = 0; rr<_r ; rr++){
        for(int cc = 0; cc<_c ; cc++){
            // Percorre vetores originais
            for (int iter = 0; iter ;iter++){
                result.pos[index(rr,cc)]+=
                        pos[index(_r,iter)]*m.pos[index(_c,iter)];
            }
        }
    }
    return result;
}
bool Matrix::operator!=(const Matrix& m){
    if(getCols()!=m.getCols()){ return true; }
    if(getRows()!=m.getRows()){ return true; }
    for(int ii = 0; ii<getRows(); ii++){
        for(int jj = 0; jj<getCols(); jj++){
            if( pos[index(ii,jj)] != m.pos[index(ii,jj)] ){
                return true; 
            }
        }
    }
    return false;
}
istream& operator>> (istream& op, Matrix& m){
    for(int ii = 0; ii<m.getCols()*m.getRows(); ii++){
        op>>m.pos[ii];
    }
    return op;
}
