#pragma once
#include <iostream>   
#include <cstdlib> 
#include <cmath>
class BigInt
{
	uint16_t* Data;
	size_t Len;
	bool sign;
public:
	BigInt();
	BigInt(const BigInt& A); // Copy constructor
	BigInt(const int32_t& A);
	BigInt(BigInt&& A); // Move constructor
	BigInt(std::string& str);
	BigInt(std::string&& str);// Move constructor
	BigInt& operator=(BigInt&& A); //Move operator
	BigInt& operator=(const BigInt& A); // Copy operator
	BigInt& operator=(const int32_t& A); //Copy operator
	BigInt& operator=(const int32_t&& A); //Move operator
	void abs_plus(const BigInt& A, const BigInt& B);
	void abs_minus(const BigInt& A, const BigInt& B);
	BigInt operator-();
	BigInt operator+(const BigInt& A) const;
	BigInt operator+(const int32_t& A) const; // new
	BigInt operator-(const BigInt& A) const;
	BigInt operator-(const int32_t& A) const; // new
	BigInt operator*(const BigInt& A) const; //  new
	BigInt operator*(const int32_t& A) const; // new
	bool operator>(const BigInt& A) const;
	bool operator<(const BigInt& A) const;
	bool operator>=(const BigInt& A) const;
	bool operator<=(const BigInt& A) const;
	bool operator==(const BigInt& A) const;
	bool operator!=(const BigInt& A) const;
	size_t getLen() const;
	friend std::ostream& operator<< (std::ostream& out, const BigInt& point);
	friend std::ostream& operator<< (std::ostream& out, const BigInt&& point);
	~BigInt();
};

