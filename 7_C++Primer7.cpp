#include <iostream>
using namespace std;

double max(double x, double y)
{
	if (x > y)
		return x;
	return y;
}
double min(double x, double y)
{
	if (x > y)
		return y;
	return x;
}
double add(double x, double y)
{
	return x + y;
}
double multiply(double x, double y)
{
	return x * y;
}
double diff(double x, double y)
{
	return max(x, y) - min(x, y);
}

double avg(double x, double y)
{
	return (max(x, y)+min(x, y))/2;
}

void clearInput()
{
	char ch;
	cin.clear();
	while((ch = cin.get())!='\n')
		continue;
}

int main()
{
	double(*pf[6])(double, double) = {add, diff, multiply, max, min, avg};
	
	
	
	while(true)
	{
		cout << "What do you want to do?\n"
			<< "1. Add\t2. Difference\t3. Multiply\n"
			<< "4. Max\t5. Min\t6. Average\t(Q)uit\n";
		char choice;
		cin.get(choice);
		clearInput();
		if (choice == 'Q' || choice == 'q')
		{
			cout << "Goodbye.\n"; break;
		}
		else if(choice > char('6') || choice < char('1'))
		{
			cout << "\nInvalid. Try again.";
			continue;
		}
		while(true)
		{
			cout << "Give me two numbers, please.\n";
			double x, y; cin >> x >> y;
			if(!cin)
			{
				cout << "Invalid!\n";
				clearInput();
				continue;
			}
			if (choice == '1')
				cout << "Answer: " << pf[0](x, y) << endl;
			else if(choice == '2')
				cout << "Answer: " << pf[1](x, y) << endl;
			else if(choice == '3')
				cout << "Answer: " << pf[2](x, y) << endl;
			else if(choice == '4')
				cout << "Answer: " << pf[3](x, y) << endl;
			else if(choice == '5')
				cout << "Answer: " << pf[4](x, y) << endl;
			else if(choice == '6')
				cout << "Answer: " << pf[5](x, y) << endl;
			clearInput();
			break;
		}
	}
	
	return 0;
}
