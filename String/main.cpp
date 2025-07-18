#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

class String
{
private:
	int size;
	char* str;

public:
	const char* get_str() const;
	char* get_str();
	int get_size() const;

	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other) noexcept;

	~String();

	void print() const;

	String& operator= (const String& other);
	String& operator= (String&& other) noexcept;
	char operator[] (int i) const;
	char& operator[] (int i);
};
const char* String::get_str() const
{
	return str;
}
char* String::get_str()
{
	return str;
}
int String::get_size() const
{
	return size;
}

String::String(int size) : size(size), str(new char[size] {})
{
	cout << "DefaultConstructor: " << this << endl;
}
String::String(const char* str) : String(strlen(str) + 1)
{
	for (int i = 0; i < size; ++i) this->str[i] = str[i];

	cout << "Constructor: " << this << endl;
}
String::String(const String& other) : String(other.str)
{
	cout << "CopyConstructor: " << this << endl;
}
String::String(String&& other) noexcept : size(other.size), str(other.str)
{
	other.size = 0;
	other.str = nullptr;

	cout << "MoveConstructor: " << this << endl;
}

String::~String()
{
	delete[] str;
	str = nullptr;
	size = 0;

	cout << "Destructor: " << this << endl;
}

void String::print() const
{
	cout << "Size: " << size << endl;
	cout << "Str: " << str << endl;
}

String& String::operator= (const String& other)
{
	if (this == &other) return *this;

	delete[] str;

	size = other.size;
	str = new char[size] {};

	for (int i = 0; i < size; ++i) str[i] = other.str[i];

	cout << "CopyAssignment: " << this << endl;

	return *this;
}
String& String::operator= (String&& other) noexcept
{
	if (this == &other) return *this;

	delete[] str;

	size = other.size;
	str = other.str;

	other.size = 0;
	other.str = nullptr;

	cout << "MoveAssignment: " << this << endl;

	return *this;
}
char String::operator[] (int i) const
{
	return str[i];
}
char& String::operator[] (int i)
{
	return str[i];
}

String operator+ (const String& left, const String& right)
{
	String result{ left.get_size() + right.get_size() - 1 };

	for (int i = 0; i < left.get_size(); ++i) result[i] = left[i];
	for (int i = 0; i < right.get_size(); ++i) result[i + left.get_size() - 1] = right[i];

	return result;
}

std::ostream& operator<< (std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

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

	return 0;
}