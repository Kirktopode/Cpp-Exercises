#include <iostream>
using namespace std;
#include "10_C++Primer1h.h"
int main()
{
	complex a = complex(3.0, 4.0);
	complex c;
	cout << "Enter a complex number (q to quit):\n";
	while (cin >> c)
	{
		cout << "c is " << c << '\n';
		cout << "complex conjugate is " << ~c << '\n';
		cout << "c + a is " << c + a << '\n';
		cout << "a - c is " << a - c << '\n';
		cout << "a * c is " << a * c << '\n';
		cout << "2 * c is " << 2 * c << '\n';
		cout << "Enter a complex number (q to quit):\n";
	}
	cout << "Done!\n";
	return 0;
}
