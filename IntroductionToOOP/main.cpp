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

	Point& operator = (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment: " << this << endl;

		return *this;
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

double distance(const Point& A, const Point& B); // Расстояние между двумя точками

//#define STRUCT_POINT
//#define STRUCT_POINT_GET_SET
//#define DISTANCE
//#define CONSTRUCTORS

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

	return 0;
}

double distance(const Point& A, const Point& B)
{
	return sqrt(square(A.get_x() - B.get_x()) + square(A.get_y() - B.get_y()));
}

double square(double n)
{
	return n * n;
}