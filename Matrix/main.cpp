#include "Matrix.h"
int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	Matrix A;
	A.fillRand();
	A.print();

	Matrix B;
	B = A;
	B.print();

	Matrix C{ A + B };
	C.print();

	Matrix D{ C - A };
	D.print();

	Matrix E{ A * B };
	E.print();

	Matrix F{ A * 2 };
	F.print();

	Matrix G{ 3 * A };
	G.print();

	A *= 2;
	A.print();

	cout << endl;

	B.print();
	Matrix H{ B.transpose() };
	H.print();

	cout << endl;

	cout << (A == B) << endl;
	cout << (A != B) << endl;

	return 0;
}