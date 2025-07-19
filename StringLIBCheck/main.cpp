#include <StringLIB.h>

int main()
{
	setlocale(LC_ALL, "rus");

	String str1;
	str1.print();

	String str2{ 5 };
	str2.print();

	String str3{ "Hello" };
	str3.print();
	cout << str3 << endl;

	String str4{ "World" };
	cout << str4 << endl;

	String str5;
	str5 = str3 + str4;
	cout << str5 << endl;
}