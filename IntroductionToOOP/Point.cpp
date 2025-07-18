#include "Point.h"

void Point::set_x(double x)
{
	this->x = x;
}
double Point::get_x() const
{
	return x;
}
void Point::set_y(double y)
{
	this->y = y;
}
double Point::get_y() const
{
	return y;
}

Point::Point(double x, double y) : x(x), y(y)
{
	cout << "Constructor: " << this << endl;
}
Point::Point(const Point& other) : Point(other.x, other.y)
{
	cout << "CopyConstructor: " << this << endl;
}
Point::~Point()
{
	cout << "Destructor: " << this << endl;
}

Point& Point::operator= (const Point& other)
{
	this->x = other.x;
	this->y = other.y;
	cout << "CopyAssignment: " << this << endl;

	return *this;
}
Point& Point::operator++ () // Prefix
{
	++x;
	++y;

	return *this;
}
Point Point::operator++ (int) // Postfix
{
	Point old = *this;

	++x;
	++y;

	return old;
}

double Point::distance() const // –ассто€ние до точки от начала координат
{
	return sqrt(square(x) + square(y));
}

double Point::distance(const Point& B) const // –ассто€ние от точки A до указанной точки
{
	return sqrt(square(x - B.x) + square(y - B.y));
}

void Point::print() const
{
	cout << this << ": x = " << x << ", y = " << y << endl;
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