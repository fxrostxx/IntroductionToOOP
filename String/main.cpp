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
	String(String&& other) noexcept
	{
		size = other.size;
		str = other.str;

		other.size = 0;
		other.str = nullptr;

		cout << "MoveConstructor: " << this << endl;
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
		if (this == &other) return *this;

		delete[] str;

		size = other.size;
		str = new char[size] {};

		for (int i = 0; i < size; ++i) str[i] = other.str[i];

		cout << "CopyAssignment: " << this << endl;

		return *this;
	}
	String& operator= (String&& other) noexcept
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
	char operator[] (int i) const
	{
		return str[i];
	}
	char& operator[] (int i)
	{
		return str[i];
	}
};

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

#define CONSTRUCTORS
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



	return 0;
}