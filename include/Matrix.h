#pragma once

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Matrix;

Matrix operator+ (const Matrix& left, const Matrix& right);
Matrix operator- (const Matrix& left, const Matrix& right);
Matrix operator* (const Matrix& left, const Matrix& right);
Matrix operator* (const Matrix& left, int right);

class Matrix
{
private:
	int rows;
	int cols;
	int** arr;

public:
	const int* const* get_arr() const;
	int* const* get_arr();
	int get_rows() const;
	int get_cols() const;

	explicit Matrix(const int rows = 3, const int cols = 3);
	Matrix(const int* const* arr, const int rows, const int cols);
	Matrix(const Matrix& other);
	Matrix(Matrix&& other) noexcept;
	~Matrix();

	void print() const;
	void fillRand();
	Matrix transpose() const;

	Matrix& operator= (const Matrix& other);
	Matrix& operator= (Matrix&& other) noexcept;
	Matrix& operator+= (const Matrix& other);
	Matrix& operator-= (const Matrix& other);
	Matrix& operator*= (const Matrix& other);
	Matrix& operator*= (const int other);
	const int* operator[] (int i) const;
	int* operator[] (int i);
};

Matrix operator+ (const Matrix& left, const Matrix& right);
Matrix operator- (const Matrix& left, const Matrix& right);
Matrix operator* (const Matrix& left, const Matrix& right);
Matrix operator* (const Matrix& left, const int right);
Matrix operator* (const int left, const Matrix& right);
bool operator== (const Matrix& left, const Matrix& right);
bool operator!= (const Matrix& left, const Matrix& right);