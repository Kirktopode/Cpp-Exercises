#include <iostream>
using namespace std;

template <class T>
T max5(const T ray[])
{
	T max = ray[0];
	for(int i = 1; i < 5; i++)
	{
		if(ray[i] > max)
			max = ray[i];
	}
	return max;
}
int main()
{
	int gers[5] = {2, 10, 3, -1, 0}; 
	double dubs[5] = {1.1, 2.2, 8.672, -3.1, 0.12};
	cout << "Max of gers: " << max5(gers) << "\n";
	cout << "Max of dubs: " << max5(dubs);
	return 0;
}
