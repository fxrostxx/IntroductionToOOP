#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

class String
{
private:
	char* str;
	int size;

public:
	const char* get_str() const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	int get_size() const
	{
		return size;
	}

	explicit String(int size = 80)
	{
		this->size = size;
		str = new char[size] {};

		cout << "DefaultConstructor: " << this << endl;
	}
	String(const char* str)
	{
		size = strlen(str) + 1;
		this->str = new char[size] {};

		for (int i = 0; i < size; ++i) this->str[i] = str[i];

		cout << "Constructor: " << this << endl;
	}
	String(const String& other)
	{
		size = other.size;
		str = new char[size] {};

		for (int i = 0; i < size; ++i) str[i] = other.str[i];

		cout << "CopyConstructor: " << this << endl;
	}

	~String()
	{
		delete[] str;
		str = nullptr;
		size = 0;

		cout << "Destructor: " << this << endl;
	}

	void print() const
	{
		cout << "Size: " << size << endl;
		cout << "Str: " << str << endl;
	}

	String& operator= (const String& other)
	{
		delete[] str;

		size = other.size;
		str = new char[size] {};

		for (int i = 0; i < size; ++i) str[i] = other.str[i];

		cout << "CopyAssignment: " << this << endl;

		return *this;
	}
};

String operator+ (const String& left, const String& right)
{
	String result{ left.get_size() + right.get_size() - 1 };

	for (int i = 0; i < left.get_size(); ++i) result.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); ++i) result.get_str()[i + left.get_size() - 1] = right.get_str()[i];

	return result;	
}

std::ostream& operator<< (std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//#define CONSTRUCTORS

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

	String str5 = str3 + str4;
	cout << str5 << endl;
#endif // CONSTRUCTORS

	String str1{ "Hello" };
	cout << str1 << endl;

	String str2;
	str2 = str1;
	cout << str2 << endl;

	return 0;
}