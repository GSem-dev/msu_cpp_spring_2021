#include "Matrix.h"


Matrix::MyVector::MyVector(int32_t* Vec, const size_t N)
{
	len = N;
	MyVec = Vec;
}

Matrix::MyVector Matrix:: operator[](const size_t i)
{
	if (i > columns) throw std::out_of_range("");
	else return MyVector(matrix[i], rows);
}

int32_t& Matrix::MyVector::operator[](const size_t i)
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

const  int32_t& Matrix::MyVector::operator[](const size_t i) const
{
	if (i > this->len) throw std::out_of_range("");
	else return this->MyVec[i];

}

Matrix::Matrix(const size_t i,const size_t j)
{
	this->columns = i;
	this->rows = j;
	this->matrix = new  int32_t* [i];
	for (size_t k = 0; k < i; k++)
	{ 
		this->matrix[k] = new  int32_t[j];
	}
}

Matrix::Matrix(const Matrix& A)
{
	columns = A.columns;
	rows = A.rows;
	matrix = new  int32_t* [columns];
	for (size_t k = 0; k < columns; k++)
	{
		this->matrix[k] = new  int32_t[rows];
	}
	for (size_t i = 0; i < columns; i++)
	{
		for (size_t j = 0; j < rows; j++)
		{
			matrix[i][j] = A.matrix[i][j];
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

void Matrix::operator=(Matrix& A)
{
	if (this->columns != A.columns || rows != A.rows)
	{
		throw std::out_of_range("");
	}
	else 
	{
		for (size_t i = 0; i < columns; ++i)
		{
			for (size_t j = 0; j < rows; ++j)
			{
				this->matrix[i][j] = A[i][j];
			}
		}
	}
}

void Matrix:: operator*=(const  int32_t a)
{
	for (size_t i = 0; i < columns; i++)
	{
		for (size_t j = 0; j < rows; j++)
		{
			this->matrix[i][j] *= a;
		}
	}
	
}

bool Matrix::operator==(const Matrix A) const
{
	if (columns != A.columns || rows != A.rows) return false;
	else 
	{
		for (size_t i = 0; i < columns; ++i)
		{
			for (size_t j = 0; j < rows; ++j)
			{
				if (matrix[i][j] != A[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}
}

bool Matrix::operator!=(const Matrix A) const
{
	if (columns != A.columns || rows != A.rows) return false;
	else return !(*this == A);
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
