#include <Fraction.h>

int main()
{
	setlocale(LC_ALL, "rus");

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

	return 0;
}