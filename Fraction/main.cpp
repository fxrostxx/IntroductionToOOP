#include <iostream>
using namespace std;

class Fraction
{
	int integer;
	int numerator;
	int denominator;

public:
	int get_integer() const
	{
		return integer;
	}
	int get_numerator() const
	{
		return numerator;
	}
	int get_denominator() const
	{
		return denominator;
	}

	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;

		this->denominator = denominator;
	}

	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;

		cout << "DefaultConstructor: " << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;

		cout << "SingleArgumentConstructor: " << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);

		cout << "Constructor: " << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);

		cout << "Constructor: " << this << endl;
	}
	Fraction(const Fraction& other)
	{
		integer = other.integer;
		numerator = other.numerator;
		denominator = other.denominator;

		cout << "CopyConstructor: " << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor: " << this << endl;
	}

	Fraction& operator= (const Fraction& other)
	{
		integer = other.integer;
		numerator = other.numerator;
		denominator = other.denominator;

		cout << "CopyAssignment: " << this << endl;

		return *this;
	}

	void Print() const
	{
		if (integer) cout << integer;
		if (numerator)
		{
			if (integer) cout << "(";
			cout << numerator << "/" << denominator;
			if (integer) cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}
	Fraction& ToImproper()
	{
		numerator += integer * denominator;
		integer = 0;

		return *this;
	}
	Fraction& ToProper()
	{
		integer += numerator / denominator;
		numerator %= denominator;

		return *this;
	}
};

Fraction operator* (Fraction left, Fraction right)
{
	left.ToImproper();
	right.ToImproper();

	return Fraction
	{
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	}.ToProper();
}

//#define CONSTRUCTORS

int main()
{
	setlocale(LC_ALL, "rus");

#ifdef CONSTRUCTORS
	Fraction A;
	A.Print();

	Fraction B{ 5 };
	B.Print();

	Fraction C{ 1, 2 };
	C.Print();

	Fraction D{ 2, 3, 4 };
	D.Print();

	Fraction E{ D };
	E.Print();
#endif // CONSTRUCTORS

	Fraction A{ 1, 2, 3 };
	A.Print();
	Fraction B{ 2, 3, 4 };
	B.Print();

	Fraction C{ A * B };
	C.Print();

	return 0;
}