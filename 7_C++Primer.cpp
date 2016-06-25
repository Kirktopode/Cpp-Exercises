#include <iostream>
#include <cstring>
using namespace std;

const int STRLEN = 30;

double harmean(double x, double y);
double rayAvg(const unsigned int ray[], int);
int rayAssign(unsigned int ray[]);
void rayDisplay(const unsigned int ray[], int);
int fillArray(double ray[], int raysize);
void showArray(const double ray[], int raysize);
void reverseArray(double ray[], int raysize, int inshift = 0);

double factorial(int);

void clearInput()
{
	char ch;
	cin.clear();
	while((ch = cin.get())!='\n')
		continue;
}

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



struct starship
{
	char Name[STRLEN];
	char Class[STRLEN];
	int Troops;
};

struct cargo
{
	char contents[40];
	float height, width, length, volume, mass, density;
};

void showCargo(cargo thisCargo);
void setCargoVolumeDensity(cargo *thisCargo);
int getinfo(starship pa[], int);
void display1(starship st);
void display2(starship *ps);
void display3(const starship pa[], int);


int main()
{
	double x, y; x = y = 1;
	while(x&&y)
	{
		cout << "I need two numbers.\n";
		cin >> x >> y;
		if(!cin)
			break;
		cout << "Harmonic mean: " << harmean(x, y) << "\n";
	}
	
	clearInput();
	
	int choice; unsigned int troops[10] = {0}; int raysize = 0;
	while (true)
	{
		cout << "What do you want to do, commander?\n"
		<< "1. Assign troops to squads\n2. Display current squad sizes\n"
		<< "3. Display average squad size\n4. Quit\n";
		cin >> choice;
		if(choice == 1)
			raysize = rayAssign(troops);
		else if(choice == 2)
			rayDisplay(troops, raysize);
		else if(choice == 3)
			cout << "Average troop size:" << rayAvg(troops, raysize) << "\n";
		else if(choice == 4)
		{
			cout << "Goodbye.\n\n";
			break;
		}
		else
			cout << "Invalid response. Try again.\n";
		
		clearInput();
	}
	clearInput();
	
	cargo aCargo;
	cout << "What kind of cargo are you carrying?\n";
	cin.getline(aCargo.contents, 40);
	cout << "Height of cargo: ";
	cin >> aCargo.height;
	cout << "Width of cargo: ";
	cin >> aCargo.width;
	cout << "Length of cargo: ";
	cin >> aCargo.length;
	cout << "Mass of cargo: ";
	cin >> aCargo.mass;
	setCargoVolumeDensity(&aCargo);
	showCargo(aCargo);
	
	while(true)
	{
		cout << "\nGive me a number to factorial!\n";
		int x;
		cin >> x;
		if(x < 0 || !cin)
		{
			clearInput();
			cout << "\nGoodbye... :( \n";
			break;
		}
		cout << "Factorial'd! --> " << factorial(x);
	}
	
	int size;
	cout << "How many stars are we categorizing?\n";
	cin >> size;
	double *ray = new double[size];
	size = fillArray(ray, size);
	showArray(ray, size);
	reverseArray(ray, size);
	showArray(ray, size);
	reverseArray(ray, size, 1);
	showArray(ray, size);
	
	cout << "\nEnter fleet size: ";
	int fleetsize;
	cin >> fleetsize;
	while (cin.get() != '\n')
	continue;
	starship * ptr_sta = new starship[fleetsize];
	int entered = getinfo(ptr_sta, fleetsize);
	for (int i = 0; i < entered; i++)
	{
		display1(ptr_sta[i]);
		display2(&ptr_sta[i]);
	}
	display3(ptr_sta, entered);
	delete [] ptr_sta;
	cout << "Done\n";
	
	double(*pf[6])(double, double) = {add, multiply, diff, max, min, avg};
	
	while(true)
	{
		cout << "What do you want to do?\n"
			<< "1. Add\n2. Difference\n3. Multiply\n"
			<< "4. Max\n5. Min\n6. Average\n (Q)uit";
		char choice;
		cin.get(choice);
		clearInput;
		if (choice == 'Q' || choice == 'q')
		{
			cout << "Goodbye.\n"; break;
		}
		else if(choice > '6' || choice < '1')
		{
			cout << "Invalid. Try again.";
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
			pf[int(choice)-48](x, y);
			break;
		}
	}
	
	cout << "\nEND THUS FAR.\n";
	
	return 0;
}

int getinfo(starship pa[], int raylen)
{
	cout << "Welcome, commander. Enter information about the fleet.\n";
	int i;
	for(i = 0; i < raylen; i++)
	{
		cout << "Starship #" << i+1 << " Name: ";
		cin.getline(pa[i].Name, STRLEN);
		if(pa[i].Name[0] == '\0')
			break;
		cout << "Starship #" << i+1 << " Class: ";
		cin.getline(pa[i].Class, STRLEN);
		if(pa[i].Class[0] == '\0')
		{
			strcpy(pa[i].Class, "Standard");
		}
		cout << "Starship #" << i+1 << " Troops: ";
		cin >> pa[i].Troops;
		while(!cin)
		{
			cout << "Invalid input. Try again.\n";
			clearInput();
			cin >> pa[i].Troops;
		}
		clearInput();
	}
	return i;
}
void display1(starship st)
{
	cout << "\nName: " << st.Name
		<< "\nClass: " << st.Class
		<< "\nTroops: " << st.Troops;
}
void display2(starship *ps)
{
	cout << "\nName: " << ps->Name
		<< "\nClass: " << ps->Class
		<< "\nTroops: " << ps->Troops;
}
void display3(const starship pa[], int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << "\nName: " << pa[i].Name
			<< "\nClass: " << pa[i].Class
			<< "\nTroops: " << pa[i].Troops;
	}
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

void reverseArray(double ray[], int raysize, int inshift)
{
	if(inshift > raysize/2||inshift < 0)
		return;
	double temp; int n = raysize -1;
	for(int i = inshift; i < n; i++)
	{
		temp = ray[i];
		ray[i] = ray[n];
		ray[n] = temp;
		n--;
	}
}

double factorial(int x)
{
	if(x == 0)
	{
		return 1;
	}
	return x * factorial(x - 1);
}

void setCargoVolumeDensity(cargo *thisCargo)
{
	thisCargo->volume = thisCargo->height * thisCargo->length * thisCargo->width;
	thisCargo->density = thisCargo->mass / thisCargo->volume;
}

void showCargo(cargo thisCargo)
{
	cout << "Contents: " << thisCargo.contents << "\nHeight: " << thisCargo.height
	<< "\nWidth: " << thisCargo.width << "\nLength: " << thisCargo.length
	<< "\nMass: " << thisCargo.mass << "\nVolume: " << thisCargo.volume << "\nDensity: " << thisCargo.density << "\n";
}

int rayAssign(unsigned int ray[])
{
	int i = 0;
	while (i < 10 && cin)
	{
		cout << "Troops to place in squad " << i + 1 << ": ";
		cin >> ray[i];
		if(!cin) break;
		i++;
	}
	if(!cin)
		clearInput();
	return i;
}

void rayDisplay(const unsigned int ray[], int raysize)
{
	for(int i = 0; i < raysize; i++)
		cout << "Troops in squad " << i+1 << ": " << ray[i] << "\n";
}

double rayAvg(const unsigned int ray[], int raysize)
{
	double total;
	for(int i = 0; i < raysize; i++)
		total += ray[i];
	return total/raysize;
}

double harmean(double x, double y)
{
	return 2.0*x*y/(x+y);
}
