# include<iostream>
# include<cctype>
using namespace std;
int main()
{
	char ch;
	while((ch = cin.get() ) != '@')
	{
		if(!isdigit(ch))
		{
			if(isupper(ch))
				cout << char(tolower(ch));
			else if (islower(ch))
				cout << char(toupper(ch));
			else
				cout << ch;
		}
	}
	cout << "\nInput ends.\n";
	
	while((ch = cin.get()) != '\n')
		continue;
	
	cout << "Make up to 10 donations.";
	double donray[10], avg; int abovecount; int count = 0;
	for(int i = 0; i < 10 && cin >> donray[count];i++)
	{
		avg += donray[i];
		count++;
	}
	avg /= ++count;	
	
	for(int i = 0; i < count; i++)
		if(donray[i] > avg)
			abovecount++;
	cout << "Average donation: $" << avg << "\n" << abovecount << " donations are above average.";
	
	cin.clear();
	while((ch = cin.get())!='\n')
		continue;
		
	char horse[20];
	cout << "\nWhat kind of horse you want, boy?\n";
	cin.getline(horse, 20);
	cout << "But I loathe the " << horse << " with every fiber of my being.\n\nYou can have a cactus.";
	
	return 0;
}
