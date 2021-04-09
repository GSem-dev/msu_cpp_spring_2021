#pragma once
#include <vector>
#include <iostream>


class Matrix
{
	int32_t** matrix;
	size_t columns;
	size_t rows;
	public:	
		class MyVector
		{
			int32_t* MyVec;
			size_t len;
		public:
			MyVector(int* Vec, const size_t N);
			int32_t& operator[](const size_t i);
			const  int32_t& operator[](const size_t i) const;
			void operator=(const MyVector Vec);
		};
		MyVector operator[](const size_t i);
		const MyVector  operator[](const size_t i) const;
		Matrix(const size_t i,const size_t j);
		Matrix(const Matrix& A);
		const size_t getRows() const;
		const size_t getColumns() const;
		void operator=(Matrix& A);
		void operator*=(const  int32_t a);
		bool operator==(const Matrix A) const;
		bool operator!=(const Matrix A) const;
		friend std::ostream& operator<< (std::ostream& out, const Matrix& point);		
		~Matrix();
};
