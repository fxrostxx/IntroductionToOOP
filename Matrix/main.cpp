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
	const int* const* get_arr() const
	{
		return arr;
	}
	int* const* get_arr()
	{
		return arr;
	}
	int get_rows() const
	{
		return rows;
	}
	int get_cols() const
	{
		return cols;
	}

	explicit Matrix(const int rows = 3, const int cols = 3) : rows(rows), cols(cols), arr(new int* [rows])
	{
		for (int i = 0; i < rows; ++i) arr[i] = new int[cols] {};

		cout << "DefaultConstructor: " << this << endl;
	}
	Matrix(const int* const* arr, const int rows, const int cols) : Matrix(rows, cols)
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j) this->arr[i][j] = arr[i][j];
		}

		cout << "Constructor: " << this << endl;
	}
	Matrix(const Matrix& other) : Matrix(other.arr, other.rows, other.cols)
	{
		cout << "CopyConstructor: " << this << endl;
	}
	Matrix(Matrix&& other) noexcept : rows(other.rows), cols(other.cols)
	{
		arr = other.arr;

		other.rows = 0;
		other.cols = 0;
		other.arr = nullptr;

		cout << "MoveConstructor: " << this << endl;
	}
	~Matrix()
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

	void print() const
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j) cout << arr[i][j] << '\t'; cout << endl;
		}
	}
	void fillRand()
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j) arr[i][j] = rand() % 10;
		}
	}
	Matrix transpose() const
	{
		Matrix transposed{ cols, rows };

		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j) transposed.arr[j][i] = this->arr[i][j];
		}

		return transposed;
	}

	Matrix& operator= (const Matrix& other)
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
	Matrix& operator= (Matrix&& other) noexcept
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
	Matrix& operator+= (const Matrix& other)
	{
		return *this = *this + other;
	}
	Matrix& operator-= (const Matrix& other)
	{
		return *this = *this - other;
	}
	Matrix& operator*= (const Matrix& other)
	{
		return *this = *this * other;
	}
	Matrix& operator*= (const int other)
	{
		return *this = *this * other;
	}
	const int* operator[] (int i) const
	{
		return arr[i];
	}
	int* operator[] (int i)
	{
		return arr[i];
	}
};

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

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	Matrix A;
	A.fillRand();
	A.print();

	Matrix B;
	B = A;
	B.print();

	Matrix C{ A + B };
	C.print();

	Matrix D{ C - A };
	D.print();

	Matrix E{ A * B };
	E.print();

	Matrix F{ A * 2 };
	F.print();

	Matrix G{ 3 * A };
	G.print();

	A *= 2;
	A.print();

	cout << endl;

	B.print();
	Matrix H{ B.transpose() };
	H.print();

	cout << endl;

	cout << (A == B) << endl;
	cout << (A != B) << endl;

	return 0;
}