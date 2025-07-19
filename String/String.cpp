#include "StringLIB.h"

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