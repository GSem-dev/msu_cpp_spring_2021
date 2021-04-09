#include "Matrix.h"
Matrix::MyVector::MyVector(int* Vec, const Len N)
{
	len = N;
	MyVec = Vec;
}


int& Matrix::MyVector::operator[](const size_t i)
{
	if (i > len)
	{
		throw std::out_of_range("");
	}
	else
	{
		return MyVec[i];
	}

}
void Matrix::MyVector::operator=(const MyVector Vec)
{
	MyVec = Vec.MyVec;
}
const int& Matrix::MyVector::operator[](const size_t i) const
{
	if (i > this->len)
	{
		throw std::out_of_range("");
	}
	else
	{
		return this->MyVec[i];
	}

}

Matrix::Matrix(const size_t i,const size_t j)
{
	this->columns = i;
	this->rows = j;
	this->matrix = new int* [i];
	for (size_t k = 0; k < i; k++)
	{ 
		this->matrix[k] = new int[j];
		if (!this->matrix[k])
		{
			throw std::out_of_range("Init Error!");
			for (size_t m = 0; m < k; m++)
			{
				delete[] this->matrix[k];
			}
			delete[] this->matrix;
			matrix = nullptr;
		}
	}
}

Matrix::Matrix(const Matrix& A)
{
	columns = A.columns;
	rows = A.rows;
	matrix = new int* [columns];
	for (size_t k = 0; k < columns; k++)
	{
		this->matrix[k] = new int[rows];
		if (!matrix[k])
		{
			throw std::out_of_range("Init Error!");
			for (size_t m = 0; m < k; m++)
			{
				delete[] matrix[k];
			}
			delete[] matrix;
			matrix = nullptr;
		}
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

const Matrix::MyVector  Matrix::operator[](const size_t i) const
{
	if (i > columns)
	{
		throw std::out_of_range("");
	}
	else
	{
		return MyVector(matrix[i], rows);
	}
}

Matrix::MyVector Matrix:: operator[](const size_t i)
{
	if (i > columns)
	{
		throw std::out_of_range("");
	}
	else
	{
		return MyVector(matrix[i], rows);
	}
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
	if (columns != Matrix.columns || rows != Matrix.rows)
	{
		return false;
	}
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
	if (columns != Matrix.columns || rows != Matrix.rows)
	{
		return false;
	}
	else
	{
		return !(*this == Matrix);
	}
}




std::ostream& operator<< (std::ostream& out, const Matrix& point)
{
	for (size_t i = 0; i < point.columns; i++)
	{
		for (size_t j = 0; j < point.rows; j++)
		{
			out << point[i][j]<<' ';
			
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
