#include <iostream>
using namespace std;
int main()
{
	char * months[12] = 
	{
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	double profitray[3][13];
	for(int x = 0; x < 3; x++)
	{
		profitray[x][12] = 0;
		cout << "Year " << x+1 << " profits--\n\n";
		for(int y = 0; y < 12; y++)
		{
			cout << months[y] << " profits: $";
			cin >> profitray[x][y];
			profitray[x][12] += profitray[x][y];
		}
		cout << "\n\n";
	}
	for(int x = 0; x < 3; x++)
		cout << "Year " << x+1 << " profits: $" << profitray[x][12] << "\n";
	cout << "\nTotal profits: $" << profitray[0][12] + profitray[1][12] + profitray[2][12] << "\n\n";
	
	double daphne, cleo;
	daphne = cleo = 100;
	unsigned short yrs = 0;
	while(cleo <= daphne)
	{
		daphne += 10;
		cleo += .05 * cleo;
		yrs++;
	}
	cout << "In " << yrs << " years, Cleo's investment overtakes Daphne's.\n";
	cout << "Daphne's Investment: $" << daphne << "\t Cleo's Investment: $" << cleo << "\n\n";
	
	cout << "GIVE ME NUMBERS!";
	double num, sum;
	sum = 0;
	cin >> num;
	while (num)
	{
		sum += num;
		cout << "Cumulative Sum: " << sum << "\n";
		cin >> num;
	}
	cout << "Final Sum: " << sum << "\n" << "Goodbye.\n\n";
	
	cout << "Give me two integers, sir!\n";
	int num1, num2;
	cin >> num1 >> num2;
	int big, little;
	big = num1, little = num2;
	if(num1 <= num2)
		big = num2, little = num1;
	int sum1 = 0;
	for(int i = little; i <= big; i++)
		sum1 += i;
	cout << "The sum is " << sum1;
}
