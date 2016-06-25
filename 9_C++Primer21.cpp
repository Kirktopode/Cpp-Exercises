#include <iostream>
#include "9_C++Primer2h.h"
using namespace std;

int main()
{
	sword swordArray[5];
	int trucount = 0;
	for(int i = 0; i < 5; i++)
	{
		if(!swordArray[i].reset())
			break;
		trucount += 1;
	}
	for(int i = 0; i < trucount; i++)
	{
		swordArray[i].showSword();
	}
	return 0;
}
