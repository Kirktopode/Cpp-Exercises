#include <iostream>
using namespace std;

#ifndef _COMPLEX0_
#define _COMPLEX0_
class complex
{
	private:
		double real;
		double imaginary;
	public:
		complex(double r, double i);
		complex();
		friend complex operator~(const complex &c);
		complex operator+(const complex &c) const;
		complex operator-(const complex &c) const;
		complex operator*(const complex &c) const;
		friend complex operator*(double m, const complex &c);
		friend ostream& operator<<(ostream &os, const complex &c);
		friend istream& operator>>(istream &is, complex &c);
};
complex::complex(double r, double i)
{
	real = r; imaginary = i;
}
complex::complex()
{
	real = 0; imaginary = 0;
}
complex operator~(const complex &c)
{
	return complex(c.real, -c.imaginary);
}
complex complex::operator+(const complex &c) const
{
	return complex(real + c.real, imaginary + c.imaginary);
}
complex complex::operator-(const complex &c) const
{
	return complex(real - c.real, imaginary - c.imaginary);
}
complex complex::operator*(const complex &c) const
{
	return complex(real * c.real - imaginary * c.imaginary, real * c.imaginary + imaginary * c.real);
}
complex operator*(double m, const complex &c)
{
	return complex(m * c.real, m * c.imaginary);
}
ostream& operator<<(ostream &os, const complex &c)
{
	os << "(" << c.real << ", " << c.imaginary << "i)";
	return os;
}
istream& operator>>(istream &is, complex &c)
{
	cout << "Real: ";
	is >> c.real;
	cout << "Imaginary: ";
	is >> c.imaginary;
	return is;
}
#endif
