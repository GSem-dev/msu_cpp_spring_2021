#include "Matrix.h"
Matrix::MyVector::MyVector(int* Vec, const Length N)
{
	len = N;
	MyVec = Vec;
}

Matrix::MyVector Matrix:: operator[](const size_t i)
{
	if (i > columns) throw std::out_of_range("");
	else return MyVector(matrix[i], rows);
}

int& Matrix::MyVector::operator[](const size_t i)
{
	if (i > len) throw std::out_of_range("");
	else return MyVec[i];
}

void Matrix::MyVector::operator=(const MyVector Vec)
{
	MyVec = Vec.MyVec;
}

const Matrix::MyVector  Matrix::operator[](const size_t i) const
{
	if (i > columns) throw std::out_of_range("");
	else return MyVector(matrix[i], rows);
}

const int& Matrix::MyVector::operator[](const size_t i) const
{
	if (i > this->len) throw std::out_of_range("");
	else return this->MyVec[i];

}

Matrix::Matrix(const size_t i,const size_t j)
{
	this->columns = i;
	this->rows = j;
	this->matrix = new int* [i];
	for (size_t k = 0; k < i; k++)
	{ 
		this->matrix[k] = new int[j];
	}
}

Matrix::Matrix(const Matrix& A)
{
	this->columns = A.columns;
	this->rows = A.rows;
	this->matrix = new int* [columns];
	for (size_t k = 0; k < columns; k++)
	{
		this->matrix[k] = new int[rows];
	}
	for (size_t i = 0; i < columns; i++)
	{
		for (size_t j = 0; j < rows; j++)
		{
			this->matrix[i][j] = A.matrix[i][j];
		}
	}
}

const size_t Matrix::getRows() const
{
	return rows;
}

const size_t Matrix::getColumns() const
{
	return columns;
}

void Matrix::operator=(Matrix& Mat)
{
	if (this->columns != Mat.columns || rows != Mat.rows)
	{
		throw std::out_of_range("");
	}
	else 
	{
		for (size_t i = 0; i < columns; ++i)
		{
			for (size_t j = 0; j < rows; ++j)
			{
				this->matrix[i][j] = Mat[i][j];
			}
		}
	}
}

void Matrix:: operator*=(const int a)
{
	for (size_t i = 0; i < columns; i++)
	{
		for (size_t j = 0; j < rows; j++)
		{
			this->matrix[i][j] *= a;
		}
	}
	
}
bool Matrix::operator==(const Matrix Matrix) const
{
	if (columns != Matrix.columns || rows != Matrix.rows) return false;
	else 
	{
		for (size_t i = 0; i < columns; ++i)
		{
			for (size_t j = 0; j < rows; ++j)
			{
				if (matrix[i][j] != Matrix[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}
}

bool Matrix::operator!=(const Matrix Matrix) const
{
	if (columns != Matrix.columns || rows != Matrix.rows) return false;
	else return !(*this == Matrix);
}

std::ostream& operator<< (std::ostream& out, const Matrix& point)
{
	for (size_t i = 0; i < point.columns; i++)
	{
		for (size_t j = 0; j < point.rows; j++)
		{
			out << point[i][j]<<'|';
			
		}
		out <<'\n';
	}
	return out;
}

Matrix::~Matrix()
{
	for (size_t i = 0; i < columns; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = nullptr;
}
