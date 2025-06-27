#include <iostream>
#include <cmath>
using namespace std;

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

	double distance() const // Расстояние до точки от начала координат
	{
		return sqrt(square(x) + square(y));
	}

	double distance(const Point& B) const // Расстояние от точки A до указанной точки
	{
		return sqrt(square(x - B.x) + square(y - B.y));
	}
};

double distance(const Point& A, const Point& B); // Расстояние между двумя точками

//#define STRUCT_POINT
//#define STRUCT_POINT_GET_SET
#define DISTANCE

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

	cout << "Введите координату x точки B: "; cin >> x;
	cout << "Введите координату y точки B: "; cin >> y;
	B.set_x(x);
	B.set_y(y);

	cout << "Расстояние от точки A до точки B (функция): " << distance(A, B) << endl;
	cout << "Расстояние от точки A до точки B (метод): " << A.distance(B) << endl;
#endif // DISTANCE

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