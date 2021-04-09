#pragma once
#include <vector>
#include <iostream>


class Matrix
{

	int** matrix;
	size_t columns;
	size_t rows;
	public:
		Matrix(const size_t i,const size_t j);
		Matrix(const Matrix& A);
		const size_t getRows() const;
		const size_t getColumns() const;
		
		class MyVector
		{
			using Len = size_t;
			int* MyVec;
			Len len;
		public:
			MyVector(int* Vec, const Len N);
			int& operator[](const size_t i);
			const int& operator[](const size_t i) const;
			void operator=(const MyVector Vec);
		};
		MyVector operator[](const size_t i);
		const MyVector  operator[](const size_t i) const;
		void operator*=(const int a);
		void operator=(Matrix& Mat);
		bool operator==(const Matrix Matrix) const;
		bool operator!=(const Matrix Matrix) const;
		friend std::ostream& operator<< (std::ostream& out, const Matrix& point);
		
		~Matrix();

};
