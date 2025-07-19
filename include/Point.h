#pragma once

#include <iostream>
#include <cmath>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define delimiter "\n--------------------------------------------------\n"

class Point;

double square(double n);
double distance(const Point& A, const Point& B);

class Point
{
	double x;
	double y;

public:
	void set_x(double x);
	double get_x() const;
	void set_y(double y);
	double get_y() const;
	Point(double x = 0, double y = 0);
	Point(const Point& other);
	~Point();
	Point& operator= (const Point& other);
	Point& operator++ ();
	Point operator++ (int);

	double distance() const;
	double distance(const Point& B) const;
	void print() const;
};

Point operator+ (const Point& left, const Point& right);
bool operator== (const Point& left, const Point& right);
bool operator!= (const Point& left, const Point& right);