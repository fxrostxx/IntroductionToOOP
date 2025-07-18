#include "Fraction.h"

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