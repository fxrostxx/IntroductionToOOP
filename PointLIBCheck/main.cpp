#include <Point.h>

int main()
{
	setlocale(LC_ALL, "rus");

	cout << (Point(2, 3) == Point(2, 3)) << endl;

	cout << (Point(2, 3) != Point(2, 3)) << endl;

	return 0;
}