#include <iostream>
using namespace std;

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
};

//#define STRUCT_POINT;

int main()
{
	setlocale(LC_ALL, "rus");

#ifdef STRUCT_POINT
	Point A{ 2, 3 };

	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;

	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

	Point A;

	A.set_x(2);
	A.set_y(3);

	cout << A.get_x() << "\t" << A.get_y();

	return 0;
}