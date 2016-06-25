#include <iostream>
#include <cstring>
using namespace std;

template <class type>
type maxn(const type ray[], int len)
{
	type max = ray[0];
	for(int i = 1; i < len; i++)
	{
		if (ray[i] > max)
			max = ray[i];
	}
	return max;
}

template <> const char* maxn(const char *const strs[], int len) //Of course, I need to specify a return type for the function
{
	int maxIndex = 0; int maxLen = 0;
	for(int i = 0; i < len; i++)
	{
		int n = 0;
		while(strs[i][n] != '\0')
		{
			n += 1;
		}
		if(n + 1 > maxLen)
		{
			maxLen = n + 1;
			maxIndex = i;
		}
	}
	return strs[maxIndex];
}

int main()
{
	int nums[] = {1, -6, 90, 2, 87, 4};
	double dubs[] = {2.2, 1.0, 4.45, 4.46};;
	const char *const strings[]= {"Moobulus", "Carnage", "Pestilence", "Dismay", "Boredom", "Itchinesss"}; //To make an array of pointers-to-char that gives me strings, I need const char *const str[]--for parameter AND argument
	cout << maxn(nums, 6) << endl << maxn(dubs, 4) << endl << maxn(strings, 6);
	return 0;
}
