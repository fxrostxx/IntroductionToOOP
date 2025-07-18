#include "Fraction.h"

int GCD(int a, int b)
{
	if (a == 0) return b;
	return GCD(b % a, a);
}
int LCM(int a, int b)
{
	return (a * b) / GCD(a, b);
}

int Fraction::get_integer() const
{
	return integer;
}
int Fraction::get_numerator() const
{
	return numerator;
}
int Fraction::get_denominator() const
{
	return denominator;
}

void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0) denominator = 1;

	this->denominator = denominator;
}

Fraction::Fraction()
{
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;

	cout << "DefaultConstructor: " << this << endl;
}
Fraction::Fraction(int integer)
{
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;

	cout << "SingleArgumentConstructor: " << this << endl;
}
Fraction::Fraction(double value)
{
	int precision = 1e+9; // 1000000000

	this->integer = value;
	this->numerator = round((value - integer) * precision);
	this->denominator = precision;

	this->ReduceFraction();

	cout << "SingleArgumentConstructor: " << this << endl;
}
Fraction::Fraction(int numerator, int denominator)
{
	this->integer = 0;
	this->numerator = numerator;
	set_denominator(denominator);

	cout << "Constructor: " << this << endl;
}
Fraction::Fraction(int integer, int numerator, int denominator)
{
	this->integer = integer;
	this->numerator = numerator;
	set_denominator(denominator);

	cout << "Constructor: " << this << endl;
}
Fraction::Fraction(const Fraction& other)
{
	integer = other.integer;
	numerator = other.numerator;
	denominator = other.denominator;

	cout << "CopyConstructor: " << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destructor: " << this << endl;
}

Fraction& Fraction::operator= (const Fraction& other)
{
	integer = other.integer;
	numerator = other.numerator;
	denominator = other.denominator;

	cout << "CopyAssignment: " << this << endl;

	return *this;
}
Fraction& Fraction::operator+= (const Fraction& other)
{
	if (denominator == other.denominator)
	{
		integer += other.integer;
		numerator += other.get_numerator();
	}
	else
	{
		int lcm{ LCM(denominator, other.denominator) };

		integer += other.integer;
		numerator = numerator * (lcm / denominator) +
			other.numerator * (lcm / other.denominator);
		denominator = lcm;
	}

	this->ToProper();

	return *this;
}
Fraction& Fraction::operator-= (const Fraction& other)
{
	if (denominator == other.denominator)
	{
		integer -= other.integer;
		numerator -= other.get_numerator();
	}
	else
	{
		int lcm{ LCM(denominator, other.denominator) };

		integer -= other.integer;
		numerator = numerator * (lcm / denominator) -
			other.numerator * (lcm / other.denominator);
		denominator = lcm;
	}

	this->ToProper();

	return *this;
}
Fraction& Fraction::operator*= (const Fraction& other)
{
	return *this = *this * other;
}
Fraction& Fraction::operator/= (Fraction other)
{
	return *this = *this / other;
}
Fraction& Fraction::operator++ ()
{
	++integer;

	return *this;
}
const Fraction Fraction::operator++ (int)
{
	Fraction old = *this;

	++integer;

	return old;
}
Fraction& Fraction::operator-- ()
{
	--integer;

	return *this;
}
const Fraction Fraction::operator-- (int)
{
	Fraction old = *this;

	--integer;

	return old;
}

Fraction::operator int() const
{
	return integer + numerator / denominator;
}
Fraction::operator double() const
{
	return integer + (double)numerator / denominator;
}

void Fraction::Print() const
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
Fraction& Fraction::ToImproper()
{
	numerator += integer * denominator;
	integer = 0;

	return *this;
}
Fraction& Fraction::ToProper()
{
	integer += numerator / denominator;
	numerator %= denominator;

	return *this;
}
Fraction Fraction::Invert() const
{
	Fraction inverted = *this;

	inverted.ToImproper();

	swap(inverted.numerator, inverted.denominator);

	return inverted;
}
Fraction& Fraction::ReduceFraction()
{
	int gcd{ GCD(numerator, denominator) };

	numerator /= gcd;
	denominator /= gcd;

	return *this;
}

Fraction operator* (Fraction left, Fraction right)
{
	left.ToImproper();
	right.ToImproper();

	return Fraction
	{
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	}.ToProper().ReduceFraction();
}
Fraction operator/ (const Fraction& left, const Fraction& right)
{
	return left * right.Invert();
}
Fraction operator+ (const Fraction& left, const Fraction& right)
{
	if (left.get_denominator() == right.get_denominator()) return Fraction
	{
		left.get_integer() + right.get_integer(),
		left.get_numerator() + right.get_numerator(),
		left.get_denominator()
	};

	int lcm{ LCM(left.get_denominator(), right.get_denominator()) };

	return Fraction
	{
		left.get_integer() + right.get_integer(),

		left.get_numerator() * (lcm / left.get_denominator()) +
		right.get_numerator() * (lcm / right.get_denominator()),

		lcm
	}.ToProper();
}
Fraction operator- (const Fraction& left, const Fraction& right)
{
	if (left.get_denominator() == right.get_denominator()) return Fraction
	{
		left.get_integer() - right.get_integer(),
		left.get_numerator() - right.get_numerator(),
		left.get_denominator()
	};

	int lcm{ LCM(left.get_denominator(), right.get_denominator()) };

	return Fraction
	{
		left.get_integer() - right.get_integer(),

		left.get_numerator() * (lcm / left.get_denominator()) -
		right.get_numerator() * (lcm / right.get_denominator()),

		lcm
	}.ToProper();
}
bool operator== (Fraction left, Fraction right)
{
	left.ToImproper();
	right.ToImproper();

	return left.get_numerator() * right.get_denominator() ==
		left.get_denominator() * right.get_numerator();
}
bool operator!= (const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator> (Fraction left, Fraction right)
{
	left.ToImproper();
	right.ToImproper();

	return left.get_numerator() * right.get_denominator() >
		left.get_denominator() * right.get_numerator();
}
bool operator< (Fraction left, Fraction right)
{
	left.ToImproper();
	right.ToImproper();

	return left.get_numerator() * right.get_denominator() <
		left.get_denominator() * right.get_numerator();
}
bool operator>= (const Fraction& left, const Fraction& right)
{
	return !(left < right);
}
bool operator <= (const Fraction& left, const Fraction& right)
{
	return !(left > right);
}

std::ostream& operator<< (std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer()) os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer()) os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer()) os << ")";
	}
	else if (obj.get_integer() == 0) os << 0;

	return os;
}
std::istream& operator>> (std::istream& is, Fraction& obj)
{
	const int size = 256;
	char temp[size]{};

	is.getline(temp, size);

	int n = 0;
	int numbers[3]{};
	const char delimeters[]{ "() /," };

	for (char* pch = strtok(temp, delimeters); pch && n < 3; pch = strtok(NULL, delimeters))
		numbers[n++] = atoi(pch);

	switch (n)
	{
	case 0: obj = Fraction{}; break;
	case 1: obj = Fraction{ numbers[0] }; break;
	case 2: obj = Fraction{ numbers[0], numbers[1] }; break;
	case 3: obj = Fraction{ numbers[0], numbers[1], numbers[2] }; break;
	}

	return is;
}