#include <iostream>

using namespace std;

void sillyPrint(const char * str, int n = 0)
{
	static int times = 0;
	cout << str << endl;
	if(n)
		for(int i = 0; i < times - 1; i++)
		{
			cout << str << endl;
		}
	times += 1;
}

int main()
{
	sillyPrint("b0p", 1);
	sillyPrint("beep");
	sillyPrint("beep");
	sillyPrint("beep");
	sillyPrint("goop", 1);
	return 0;
}
