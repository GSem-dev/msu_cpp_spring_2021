#pragma once
#include <vector>
#include <iostream>


class Matrix
{

	int** matrix;
	size_t columns;
	size_t rows;
	public:	
		class MyVector
		{
			using Length = size_t;
			int* MyVec;
			Length len;
		public:
			MyVector(int* Vec, const Length N);
			int& operator[](const size_t i);
			const int& operator[](const size_t i) const;
			void operator=(const MyVector Vec);
		};
		MyVector operator[](const size_t i);
		const MyVector  operator[](const size_t i) const;
		Matrix(const size_t i,const size_t j);
		Matrix(const Matrix& A);
		const size_t getRows() const;
		const size_t getColumns() const;
		void operator=(Matrix& Mat);
		void operator*=(const int a);
		bool operator==(const Matrix Matrix) const;
		bool operator!=(const Matrix Matrix) const;
		friend std::ostream& operator<< (std::ostream& out, const Matrix& point);
		
		~Matrix();

};
