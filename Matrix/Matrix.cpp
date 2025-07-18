#include "Matrix.h"

const int* const* Matrix::get_arr() const
{
	return arr;
}
int* const* Matrix::get_arr()
{
	return arr;
}
int Matrix::get_rows() const
{
	return rows;
}
int Matrix::get_cols() const
{
	return cols;
}

Matrix::Matrix(const int rows, const int cols) : rows(rows), cols(cols), arr(new int* [rows])
{
	for (int i = 0; i < rows; ++i) arr[i] = new int[cols] {};

	cout << "DefaultConstructor: " << this << endl;
}
Matrix::Matrix(const int* const* arr, const int rows, const int cols) : Matrix(rows, cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j) this->arr[i][j] = arr[i][j];
	}

	cout << "Constructor: " << this << endl;
}
Matrix::Matrix(const Matrix& other) : Matrix(other.arr, other.rows, other.cols)
{
	cout << "CopyConstructor: " << this << endl;
}
Matrix::Matrix(Matrix&& other) noexcept : rows(other.rows), cols(other.cols)
{
	arr = other.arr;

	other.rows = 0;
	other.cols = 0;
	other.arr = nullptr;

	cout << "MoveConstructor: " << this << endl;
}
Matrix::~Matrix()
{
	for (int i = 0; i < rows; ++i)
	{
		delete[] arr[i];
		arr[i] = nullptr;
	}
	delete[] arr;
	arr = nullptr;

	rows = cols = 0;

	cout << "Destructor: " << this << endl;
}

void Matrix::print() const
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j) cout << arr[i][j] << '\t'; cout << endl;
	}
}
void Matrix::fillRand()
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j) arr[i][j] = rand() % 10;
	}
}
Matrix Matrix::transpose() const
{
	Matrix transposed{ cols, rows };

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j) transposed.arr[j][i] = this->arr[i][j];
	}

	return transposed;
}

Matrix& Matrix::operator= (const Matrix& other)
{
	if (this == &other) return *this;

	for (int i = 0; i < rows; ++i) delete[] arr[i];
	delete[] arr;

	rows = other.rows;
	cols = other.cols;
	this->arr = new int* [rows];
	for (int i = 0; i < rows; ++i) arr[i] = new int[cols] {};

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j) arr[i][j] = other.arr[i][j];
	}

	cout << "CopyAssignment: " << this << endl;

	return *this;
}
Matrix& Matrix::operator= (Matrix&& other) noexcept
{
	if (this == &other) return *this;

	for (int i = 0; i < rows; ++i) delete[] arr[i];
	delete[] arr;

	rows = other.rows;
	cols = other.cols;
	arr = other.arr;

	other.rows = 0;
	other.cols = 0;
	other.arr = nullptr;

	cout << "MoveAssignment: " << this << endl;

	return *this;
}
Matrix& Matrix::operator+= (const Matrix& other)
{
	return *this = *this + other;
}
Matrix& Matrix::operator-= (const Matrix& other)
{
	return *this = *this - other;
}
Matrix& Matrix::operator*= (const Matrix& other)
{
	return *this = *this * other;
}
Matrix& Matrix::operator*= (const int other)
{
	return *this = *this * other;
}
const int* Matrix::operator[] (int i) const
{
	return arr[i];
}
int* Matrix::operator[] (int i)
{
	return arr[i];
}

Matrix operator+ (const Matrix& left, const Matrix& right)
{
	if (left.get_cols() != right.get_cols() || left.get_rows() != right.get_rows()) return Matrix{};

	Matrix result{ left.get_rows(), left.get_cols() };

	for (int i = 0; i < result.get_rows(); ++i)
	{
		for (int j = 0; j < result.get_cols(); ++j) result[i][j] = left[i][j] + right[i][j];
	}

	return result;
}
Matrix operator- (const Matrix& left, const Matrix& right)
{
	if (left.get_cols() != right.get_cols() || left.get_rows() != right.get_rows()) return Matrix{};

	Matrix result{ left.get_rows(), left.get_cols() };

	for (int i = 0; i < result.get_rows(); ++i)
	{
		for (int j = 0; j < result.get_cols(); ++j) result[i][j] = left[i][j] - right[i][j];
	}

	return result;
}
Matrix operator* (const Matrix& left, const Matrix& right)
{
	if (left.get_cols() != right.get_rows()) return Matrix{};

	Matrix result{ left.get_rows(), right.get_cols() };

	for (int i = 0; i < left.get_rows(); ++i)
	{
		for (int j = 0; j < right.get_cols(); ++j)
		{
			for (int k = 0; k < left.get_cols(); ++k) result[i][j] += left[i][k] * right[k][j];
		}
	}

	return result;
}
Matrix operator* (const Matrix& left, const int right)
{
	Matrix result{ left.get_rows(), left.get_cols() };

	for (int i = 0; i < left.get_rows(); ++i)
	{
		for (int j = 0; j < left.get_cols(); ++j) result[i][j] = left[i][j] * right;
	}

	return result;
}
Matrix operator* (const int left, const Matrix& right)
{
	return right * left;
}
bool operator== (const Matrix& left, const Matrix& right)
{
	if (left.get_rows() != right.get_rows() || left.get_cols() != right.get_cols()) return false;

	for (int i = 0; i < left.get_rows(); ++i)
	{
		for (int j = 0; j < left.get_cols(); ++j)
		{
			if (left[i][j] != right[i][j]) return false;
		}
	}

	return true;
}
bool operator!= (const Matrix& left, const Matrix& right)
{
	return !(left == right);
}