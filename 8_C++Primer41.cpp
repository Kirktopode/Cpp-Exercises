#include <iostream>
#include "8_C++Primer4h.h"
using namespace std;

int main()
{
	sword swordArray[5];
	int trucount = 0;
	for(int i = 0; i < 5; i++)
	{
		if(!setSword(swordArray[i]))
			break;
		trucount += 1;
	}
	for(int i = 0; i < trucount; i++)
	{
		showSword(swordArray[i]);
	}
	return 0;
}
