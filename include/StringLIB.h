#pragma once

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

String operator+ (const String& left, const String& right);
std::ostream& operator<< (std::ostream& os, const String& obj);