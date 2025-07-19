#include <Fraction.h>

int main()
{
	setlocale(LC_ALL, "rus");

	Fraction A{ 2, 3, 4 };
	A.Print();
	Fraction B{ 3, 4, 5 };
	B.Print();

	Fraction C{ A * B };
	cout << "������������: ";  C.Print();

	C = A / B;
	cout << "�������: ";  C.Print();

	C = A + B;
	cout << "�����: ";  C.Print();

	C = A - B;
	cout << "��������: ";  C.Print();

	A += B;
	cout << "����� (+=): ";  A.Print();

	Fraction D{ 1, 2, 3 };
	Fraction E{ 2, 3, 4 };

	D -= E;
	cout << "�������� (-=): ";  D.Print();

	Fraction F{ 1, 2, 3 };
	Fraction G{ 2, 3, 4 };

	F *= G;
	cout << "������������ (*=): ";  F.Print();

	F /= G;
	cout << "������� (/=): ";  F.Print();

	return 0;
}