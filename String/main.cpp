#include <iostream>
using namespace std;

class String
{
private:
	char* str;
	int length;

public:
	char* get_str() const
	{
		return str;
	}
	int get_length() const
	{
		return length;
	}
	void set_str(char* str)
	{
		delete[] this->str;

		this->str = str;
	}
	void set_length(int length)
	{
		this->length = length;
	}

	String()
	{
		length = 0;
		str = nullptr;

		cout << "DefaultConstructor: " << this << endl;
	}
	String(const char* str)
	{
		length = strlen(str);

		this->str = new char[length + 1];

		for (int i = 0; i <= length; ++i) this->str[i] = str[i];

		cout << "Constructor: " << this << endl;
	}
	String(const String& other)
	{
		length = other.length;

		str = new char[length + 1];

		for (int i = 0; i <= length; ++i) str[i] = other.str[i];
		str[length] = 0;

		cout << "CopyConstructor: " << this << endl;
	}
	~String()
	{
		delete[] str;
		str = nullptr;

		cout << "Destructor: " << this << endl;
	}
	String& operator= (const String& other)
	{
		delete[] str;

		length = other.length;

		str = new char[length + 1];

		for (int i = 0; i <= length; ++i) str[i] = other.str[i];

		return *this;
	}
};

String operator+ (const String& left, const String& right)
{
	String result;

	result.set_length(left.get_length() + right.get_length());

	result.set_str(new char[result.get_length() + 1]);

	int i = 0;

	for (; i < left.get_length(); ++i) result.get_str()[i] = left.get_str()[i];
	for (int j = 0; i <= result.get_length(); ++i, ++j) result.get_str()[i] = right.get_str()[j];

	return result;	
}

std::ostream& operator<< (std::ostream& os, String& obj)
{
	os << obj.get_str();

	return os;
}

int main()
{
	setlocale(LC_ALL, "rus");

	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;

	cout << str3 << endl;

	return 0;
}