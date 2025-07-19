#pragma once

#include <iostream>
#include <cmath>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

int GCD(int a, int b);
int LCM(int a, int b);

class Fraction;

Fraction operator* (Fraction left, Fraction right);
Fraction operator/ (const Fraction& left, const Fraction& right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;

public:
	int get_integer() const;
	int get_numerator() const;
	int get_denominator() const;

	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	Fraction();
	explicit Fraction(int integer);
	explicit Fraction(double value);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();

	Fraction& operator= (const Fraction& other);
	Fraction& operator+= (const Fraction& other);
	Fraction& operator-= (const Fraction& other);
	Fraction& operator*= (const Fraction& other);
	Fraction& operator/= (Fraction other);
	Fraction& operator++ ();
	const Fraction operator++ (int);
	Fraction& operator-- ();
	const Fraction operator-- (int);

	explicit operator int() const;
	explicit operator double() const;

	void Print() const;
	Fraction& ToImproper();
	Fraction& ToProper();
	Fraction Invert() const;
	Fraction& ReduceFraction();
};

Fraction operator+ (const Fraction& left, const Fraction& right);
Fraction operator- (const Fraction& left, const Fraction& right);
bool operator== (Fraction left, Fraction right);
bool operator!= (const Fraction& left, const Fraction& right);
bool operator> (Fraction left, Fraction right);
bool operator< (Fraction left, Fraction right);
bool operator>= (const Fraction& left, const Fraction& right);
bool operator <= (const Fraction& left, const Fraction& right);
std::ostream& operator<< (std::ostream& os, const Fraction& obj);
std::istream& operator>> (std::istream& is, Fraction& obj);