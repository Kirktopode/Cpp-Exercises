#include <iostream>
#include <cstring>
#include <cctype>
using std::cin;
using std::cout;
#include "11_C++Primer2h.h"
// static method

// class methods
String::String(const char * s) // construct String from C string
{
	len = strlen(s); // set size
	str = new char[len + 1]; // allot storage
	strcpy(str, s); // initialize pointer
}
String::String() // default constructor
{
	len = 0;
	str = new char[1]; // default string
	str[0] = '\0';
}
String::String(const String & st)
{
	len = st.len; // same length
	str = new char [len + 1]; // allot space
	strcpy(str, st.str); // copy string to new location
}
String::~String() // necessary destructor
{
	delete [] str; // required
}
// overloaded operator methods
// assign a String to a String
String & String::operator=(const String & st)
{
	if (this == &st)
		return *this;
	delete [] str;
	len = st.len;
	str = new char[len + 1];
	strcpy(str, st.str);
	return *this;
}
// assign a C string to a String
String & String::operator=(const char * s)
{
	delete [] str;
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
	return *this;
}
// read-write char access for non-const String
char & String::operator[](int i)
{
	return str[i];
}
// read-only char access for const String
const char & String::operator[](int i) const
{
	return str[i];
}
// overloaded operator friends
bool operator<(const String &st1, const String &st2)
{
	return (strcmp(st1.str, st2.str) < 0);
}
bool operator>(const String &st1, const String &st2)
{
	return st2.str < st1.str;
}
bool operator==(const String &st1, const String &st2)
{
	return (strcmp(st1.str, st2.str) == 0);
}
// simple String output
ostream & operator<<(ostream & os, const String & st)
{
	os << st.str;
	return os;
}
// quick and dirty String input
istream & operator>>(istream & is, String & st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}

String operator+(const String &st1, const String &st2)
{
	String temp = st1; int x = 0;
	for(int i = 0; i < st2.length(); i++)
	{
		temp[st1.len + i] = st2[i]; 
		temp.len++;
	}
	temp.str[temp.len] = '\0';
	return temp;
}
String String::stringlow() const
{
	String temp = String(str);
	for(int i = 0; i < len; i++)
	{
		temp.str[i] = tolower(temp.str[i]);
	}
	return temp;
}
String String::stringup() const
{
	String temp = String(str);
	for(int i = 0; i < len; i++)
	{
		temp.str[i] = toupper(temp.str[i]);
	}
	return temp;
}
int String::has(char c) const
{
	int count = 0;
	for(int i = 0; i < len; i++)
	{
		if(this->stringup()[i] == c || this->stringlow()[i] == c)
			count++;
	}
	return count;
}
int main()
{	
	String s1(" and I am a C++ student.");
	String s2 = "Please enter your name: ";
	String s3; 
	cout << s3; 
	cout << s2; // overloaded << operator
	cin >> s3; // overloaded >> operator
	s2 = "My name is " + s3; // overloaded =, + operators
	cout << s2 << ".\n";
	s2 = s2 + s1;
	s2.stringup(); // converts string to uppercase
	cout << "The string\n" << s2 << "\ncontains " << s2.has('A')
		<< " 'A' characters in it.\n";
	s1 = "red"; // String(const char *),
	// then String & operator=(const String&)
	String rgb[3] = { String(s1), String("green"), String("blue")};
	cout << "Enter the name of a primary color for mixing light: ";
	String ans;
	bool success = false;
	while (cin >> ans)
	{
		ans.stringlow(); // converts string to lowercase
		for (int i = 0; i < 3; i++)
		{
			if (ans == rgb[i]) // overloaded == operator
			{
				cout << "That's right!\n";
				success = true;
				break;
			}
	}
	if (success)
		break;
	else
		cout << "Try again!\n";
	}
	cout << "Bye\n";
	return 0;
}

