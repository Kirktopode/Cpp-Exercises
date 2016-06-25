#include <iostream>
using namespace std;

void clearInput()
{
	char ch;
	cin.clear();
	while((ch = cin.get())!='\n')
		continue;
}

int fillArray(double ray[], int raysize)
{
	int i = 0;
	while(cin && i < raysize)
	{
		cout << "Mass for star " << i + 1 << " : ";
		cin >> ray[i];
		if(!cin)
			break;
		i++;
	}
	clearInput();
	return i;
}

void showArray(const double ray[], int raysize)
{
	for(int i = 0; i < raysize; i++)
		cout << "\nMass of star " << i+1 << ": " << ray[i];
}

void reverseArray(double ray[], int raysize, int inshift = 0)
{
	if(inshift > raysize/2||inshift < 0)
		return;
	double temp; int n = raysize - 1 - inshift;
	for(int i = inshift; i < n; i++)
	{
		temp = ray[i];
		ray[i] = ray[n];
		ray[n] = temp;
		n--;
	}
}

int main()
{
	int size;
	cout << "How many stars are we categorizing?\n";
	cin >> size;
	double *ray = new double[size];
	size = fillArray(ray, size);
	showArray(ray, size);
	cout << endl;
	reverseArray(ray, size);
	showArray(ray, size);
	cout << endl;
	reverseArray(ray, size, 1);
	showArray(ray, size);
	return 0;
}
