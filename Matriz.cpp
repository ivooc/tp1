#include "Matriz.hpp"

/* IVO */
Matrix::Matrix(int Rows, int Cols, const double &value)
{
    rows = Rows;
    cols = Cols;
    pos = new double[rows*cols];
    for (int i = 0; i < (rows*cols); i++)
        pos[i] = value;
}

// fun��es implementadas inline no header

//int Matrix::getRows(){}
//int Matrix::index(int row, int col) const {}
//int Matrix::getIndexCol (int index) const {}
//int Matrix::getIndexRow (int index) const {}
//double Matrix::getValueAt(int row, int col) const {}

void Matrix::setValueAt(int row, int col, const double &value)
{
    if (col < cols && row < rows)
        pos[index(row, col)] = value;
}

void Matrix::setValueAt(int index, const double &value)
{
    if (index < (rows*cols))
        pos[index] = value;
}

Matrix& Matrix::unit()
{
    if (rows == cols)
        for (int i = 0; i < (rows*cols); i++){
            if (getIndexRow(i) == getIndexCol(i))
                setValueAt(i, 1);
            else
                setValueAt(i, 0);
        }
    return *this;
}

Matrix& Matrix::zeros()
{
    for (int i = 0; i < (rows*cols); i++)
        setValueAt(i, 0);
    return *this;
}

Matrix Matrix::operator+(const Matrix& m) const
{
    if (rows == m.rows && cols == m.cols){
        Matrix result(rows, cols, 0);
        for (int i = 0; i < (rows*cols); i++){
            result.pos[i] = pos[i] + m.pos[i];
        }
        return result; // necessita do construtor de c�pia implementado para funcionar
    }
    else
        return null;
}

Matrix& Matrix::operator+=(const Matrix& m)
{
    if (rows == m.rows && cols == m.cols){
        for (int i = 0; i < (rows*cols); i++){
            pos[i] += m.pos[i];
        }
    }
    return *this;
}

bool Matrix::operator==(const Matrix& m)
{
    if (rows == m.rows && cols == m.cols){
        for (int i = 0; i < (rows*cols); i++){
            if (pos[i] == m.pos[i])
                continue;
            else
                return false;
        }
        return true;
    }
    return false;
}

Matrix& Matrix::operator*=(const Matrix&){}
Matrix& Matrix::operator*=(const double&){}
friend  ostream& operator<< (ostream&, const Matrix&){}

/* BECKER */
Matrix::Matrix(const Matrix&){}
int     Matrix::getCols() const{}
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
