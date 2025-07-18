#include "String.h"

//#define CONSTRUCTORS
//#define COPY_SEMANTIC

int main()
{
	setlocale(LC_ALL, "rus");

#ifdef CONSTRUCTORS
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
#endif // CONSTRUCTORS

#ifdef COPY_SEMANTIC
	String str1{ "Hello" };
	cout << str1 << endl;

	String str2;
	str2 = str1;
	cout << str2 << endl;
#endif // COPY_SEMANTIC

	String str1;	// DefaultConstructor
	str1.print();

	String str2(5);	// SingleArgumentConstructor
	str2.print();

	String str3("Hello");	// SingleArgumentConstructor
	str2.print();

	String str4();	// Function
	//str4.print();

	String str5{};	// DefaultConstructor
	str5.print();

	String str6{ 6 };	// SingleArgumentConstructor
	str6.print();

	String str7{ "World" };
	str7.print();

	String str8 = str7;
	str8.print();

	String str9(str8);
	str9.print();

	String str10{ str9 };
	str10.print();

	String str11{ str3 + str8 };
	str11.print();

	cout << str11 << endl;

	return 0;
}