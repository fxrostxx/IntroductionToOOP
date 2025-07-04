#include <iostream>
#include <cmath>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define delimiter "\n--------------------------------------------------\n"

double square(double n);

class Point
{
	double x;
	double y;

public:
	void set_x(double x)
	{
		this->x = x;
	}

	double get_x() const
	{
		return x;
	}

	void set_y(double y)
	{
		this->y = y;
	}

	double get_y() const
	{
		return y;
	}

	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor: " << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		y = 0;
		cout << "SingleArgumentConstructor: " << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor: " << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor: " << this << endl;
	}
	~Point()
	{
		cout << "Destructor: " << this << endl;
	}

	Point& operator= (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment: " << this << endl;

		return *this;
	}
	Point& operator++ () // Prefix
	{
		++x;
		++y;

		return *this;
	}
	Point operator++ (int) // Postfix
	{
		Point old = *this;

		++x;
		++y;

		return old;
	}

	double distance() const // Расстояние до точки от начала координат
	{
		return sqrt(square(x) + square(y));
	}

	double distance(const Point& B) const // Расстояние от точки A до указанной точки
	{
		return sqrt(square(x - B.x) + square(y - B.y));
	}

	void print() const
	{
		cout << this << ": x = " << x << ", y = " << y << endl;
	}
};

Point operator+ (const Point& left, const Point& right);
bool operator== (const Point& left, const Point& right);
bool operator!= (const Point& left, const Point& right);

double distance(const Point& A, const Point& B); // Расстояние между двумя точками

//#define STRUCT_POINT
//#define STRUCT_POINT_GET_SET
//#define DISTANCE
//#define CONSTRUCTORS
//#define ASSIGNMENT
//#define ARITHMETICAL_OPERATORS

int main()
{
	setlocale(LC_ALL, "rus");

#ifdef STRUCT_POINT
	Point A{ 2, 3 };

	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;

	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef STRUCT_POINT_GET_SET
	Point A;

	A.set_x(2);
	A.set_y(3);

	cout << A.get_x() << "\t" << A.get_y();
#endif // STRUCT_POINT_GET_SET

#ifdef DISTANCE
	Point A;
	A.set_x(2);
	A.set_y(3);

	Point B;
	double x, y;

	cout << "Расстояние до точки A от начала координат: " << A.distance() << endl;

	cout << delimiter << endl;

	cout << "Введите координату x точки B: "; cin >> x;
	cout << "Введите координату y точки B: "; cin >> y;
	B.set_x(x);
	B.set_y(y);

	cout << "Расстояние от точки A до точки B (функция): " << distance(A, B) << endl;

	cout << delimiter << endl;

	cout << "Расстояние от точки A до точки B (метод): " << A.distance(B) << endl;
#endif // DISTANCE

#ifdef CONSTRUCTORS
	Point A;
	A.print();

	Point B{ 5 };
	B.print();

	Point C{ 7, 8 };
	C.print();

	Point D{ C };
	D.print();

	Point E;
	E = D;
	E.print();
#endif // CONSTRUCTORS

#ifdef ASSIGNMENT
	int a, b, c;
	a = b = c = 0;
	cout << a << ' ' << b << ' ' << c << endl;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point{ 2, 3 };
	cout << delimiter << endl;
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT

#ifdef ARITHMETICAL_OPERATORS
	Point A{ 2, 3 };
	Point B{ 7, 8 };
	Point C{ A + B };

	A.print();
	B.print();
	C.print();

	A = B++;
	A.print();
	B.print();
#endif // ARITHMETICAL_OPERATORS

	cout << (Point(2, 3) == Point(2, 3)) << endl;

	cout << (Point(2, 3) != Point(2, 3)) << endl;

	return 0;
}

Point operator+ (const Point& left, const Point& right)
{
	Point result;

	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());

	return result;
}
bool operator== (const Point& left, const Point& right)
{
	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y()) return true;
	else return false;*/

	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
}
bool operator!= (const Point& left, const Point& right)
{
	return !(left == right);
}

double distance(const Point& A, const Point& B)
{
	return sqrt(square(A.get_x() - B.get_x()) + square(A.get_y() - B.get_y()));
}

double square(double n)
{
	return n * n;
}