#include <iostream>
#include <cmath>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

int GCD(int a, int b)
{
	if (a == 0) return b;
	return GCD(b % a, a);
}
int LCM(int a, int b)
{
	return (a * b) / GCD(a, b);
}

class Fraction;

Fraction operator* (Fraction left, Fraction right);
Fraction operator/ (const Fraction& left, const Fraction& right);

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
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;

		cout << "SingleArgumentConstructor: " << this << endl;
	}
	explicit Fraction(double value)
	{
		int precision = 1e+9; // 1000000000

		this->integer = value;
		this->numerator = round((value - integer) * precision);
		this->denominator = precision;

		this->ReduceFraction();

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
	Fraction& operator+= (const Fraction& other)
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
	Fraction& operator-= (const Fraction& other)
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
	Fraction& operator*= (const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/= (Fraction other)
	{
		return *this = *this / other;
	}
	Fraction& operator++ ()
	{
		++integer;

		return *this;
	}
	const Fraction operator++ (int)
	{
		Fraction old = *this;

		++integer;

		return old;
	}
	Fraction& operator-- ()
	{
		--integer;

		return *this;
	}
	const Fraction operator-- (int)
	{
		Fraction old = *this;

		--integer;

		return old;
	}

	explicit operator int() const
	{
		return integer + numerator / denominator;
	}
	explicit operator double() const
	{
		return integer + (double)numerator / denominator;
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
	Fraction Invert() const
	{
		Fraction inverted = *this;

		inverted.ToImproper();

		swap(inverted.numerator, inverted.denominator);

		return inverted;
	}
	Fraction& ReduceFraction()
	{
		int gcd{ GCD(numerator, denominator) };

		numerator /= gcd;
		denominator /= gcd;

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

//#define CONSTRUCTORS
//#define ARITHMETICAL_OPERATORS
//#define INCREMENT_DECREMENT
//#define COMPARISON_OPERATORS
#define STREAMS
//#define CONVERSION_FROM_CLASS_TO_OTHER
//#define HAVE_A_NICE_DAY

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

#ifdef ARITHMETICAL_OPERATORS
	Fraction A{ 2, 3, 4 };
	A.Print();
	Fraction B{ 3, 4, 5 };
	B.Print();

	Fraction C{ A * B };
	cout << "Произведение: ";  C.Print();

	C = A / B;
	cout << "Частное: ";  C.Print();

	C = A + B;
	cout << "Сумма: ";  C.Print();

	C = A - B;
	cout << "Разность: ";  C.Print();

	A += B;
	cout << "Сумма (+=): ";  A.Print();

	Fraction D{ 1, 2, 3 };
	Fraction E{ 2, 3, 4 };

	D -= E;
	cout << "Разность (-=): ";  D.Print();

	Fraction F{ 1, 2, 3 };
	Fraction G{ 2, 3, 4 };

	F *= G;
	cout << "Произведение (*=): ";  F.Print();

	F /= G;
	cout << "Частное (/=): ";  F.Print();
#endif // ARITHMETICAL_OPERATORS

#ifdef INCREMENT_DECREMENT
	Fraction H{ 1, 2, 3 };
	Fraction I{ 2, 3, 4 };

	I = ++H;
	cout << "Префиксный инкремент: ";  I.Print();

	I = H++;
	cout << "Постфиксный инкремент: ";  I.Print();
#endif // INCREMENT_DECREMENT

#ifdef COMPARISON_OPERATORS
	Fraction J{ 1, 5, 3 };
	Fraction K{ 1, 2, 3 };

	cout << "Оператор сравнения (==): " << (J == K) << endl;

	cout << "Оператор сравнения (!=): " << (J != K) << endl;

	cout << "Оператор сравнения (>): " << (J > K) << endl;

	cout << "Оператор сравнения (<): " << (J < K) << endl;

	cout << "Оператор сравнения (>=): " << (J >= K) << endl;

	cout << "Оператор сравнения (<=): " << (J <= K) << endl;

	Fraction L{ 1, 15, 3 };

	L.ReduceFraction();
	cout << "Сокращение дроби: "; L.Print();
#endif // COMPARISON_OPERATORS

#ifdef STREAMS
	Fraction A{ 2, 3, 4 };

	cout << "Введите простую дробь: ";
	cin >> A;

	cout << A << endl;
#endif // STREAMS

#ifdef CONVERSION_FROM_CLASS_TO_OTHER
	Fraction A{ 1, 2, 3 };
	A.ToImproper();

	int a = (int)A;

	cout << a << endl;

	double b = (double)A;

	cout << b << endl;

	return 0;
#endif // CONVERSION_FROM_CLASS_TO_OTHER

#ifdef HAVE_A_NICE_DAY
	Fraction A{ Fraction{ 2.75 } };

	cout << A << endl;
#endif // HAVE_A_NICE_DAY



}