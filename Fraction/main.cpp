#include <iostream>
using namespace std;

int GCD(int a, int b)
{
	if (a == 0) return b;
	return GCD(b % a, a);
}
int LCM(int a, int b)
{
	return (a * b) / GCD(a, b);
}

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
	Fraction& operator*= (Fraction other)
	{
		this->ToImproper();
		other.ToImproper();

		numerator *= other.numerator;
		denominator *= other.denominator;

		this->ToProper();

		return *this;
	}
	Fraction& operator/= (Fraction other)
	{
		this->ToImproper();
		other.ToImproper();

		numerator *= other.denominator;
		denominator *= other.numerator;

		this->ToProper();

		return *this;
	}
	Fraction& operator++ ()
	{
		this->ToImproper();

		numerator += denominator;

		this->ToProper();

		return *this;
	}
	Fraction operator++ (int)
	{
		Fraction old = *this;

		this->ToImproper();
		numerator += denominator;
		this->ToProper();

		return old;
	}
	Fraction& operator-- ()
	{
		this->ToImproper();

		numerator -= denominator;

		this->ToProper();

		return *this;
	}
	Fraction operator-- (int)
	{
		Fraction old = *this;

		this->ToImproper();
		numerator -= denominator;
		this->ToProper();

		return old;
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
	}.ToProper();
}
Fraction operator/ (Fraction left, Fraction right)
{
	left.ToImproper();
	right.ToImproper();

	return Fraction
	{
		left.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_numerator()
	}.ToProper();
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
bool operator== (const Fraction& left, const Fraction& right)
{
	return left.get_integer() == right.get_integer()
		&& left.get_numerator() == right.get_numerator()
		&& left.get_denominator() == right.get_denominator();
}
bool operator!= (const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator> (Fraction left, Fraction right)
{
	if (left == right) return false;

	/*else if (left.get_denominator() == right.get_denominator())
		return left.get_integer() >= right.get_integer() && left.get_numerator() > right.get_numerator();

	else if (left.get_numerator() == right.get_numerator())
		return left.get_integer() >= right.get_integer() && left.get_denominator() < right.get_denominator();

	else if (left.get_denominator() == right.get_denominator() && left.get_numerator() == right.get_numerator())
		return left.get_integer() > right.get_integer();*/

	else
	{
		left.ToImproper();
		right.ToImproper();

		int lcm{ LCM(left.get_denominator(), right.get_denominator()) };

		return left.get_numerator() * (lcm / left.get_denominator()) >
			right.get_numerator() * (lcm / right.get_denominator());
	}
}
bool operator< (const Fraction& left, const Fraction& right)
{
	if (left == right) return false;
	else return !(left > right);
}
bool operator>= (const Fraction& left, const Fraction& right)
{
	return !(left < right);
}
bool operator <= (const Fraction& left, const Fraction& right)
{
	return !(left > right);
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

	Fraction H{ 1, 2, 3 };
	Fraction I{ 2, 3, 4 };

	H /= I;
	cout << "Частное (/=): ";  H.Print();

	I = ++H;
	cout << "Префиксный инкремент: ";  I.Print();

	I = H++;
	cout << "Постфиксный инкремент: ";  I.Print();

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

	return 0;
}