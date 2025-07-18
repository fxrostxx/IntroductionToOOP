#include "Point.h"

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