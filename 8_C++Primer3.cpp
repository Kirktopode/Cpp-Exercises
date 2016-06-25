#include<iostream>
#include<cstring>
using namespace std;

struct stringy 
{
	char * str;
	int ct;
};

//prototypes for set(), show(), and show() go here
void set(stringy &string, char str[]) // I don't use a pointer here because the string isn't passed as a pointer-to-character.
{
	
	int i = 0;
	while(str[i] != '\0')
		i++;
	string.ct = i;
	string.str = new char[i];
	strcpy(string.str, str);
}

void show(const stringy &string, int times = 1)
{
	for(int i = 0; i < times; i++)
		cout << string.str << endl;
}
void show(const char * str, int times = 1)
{
	for(int i = 0; i < times; i++)
		cout << str << endl;
}

int main()
{
	stringy beany;
	char testing[] = "Reality is precisely what I want it to be. I've ensured it."; //Because this isn't initialized as a pointer, I can't refer to it as one when I pass it to set()
	set(beany, testing);	//first argument is a reference,
							//allocates space to hold copy of testing, 
							// str member of beany to point to the new block, 
							//copies testing to new block, and sets ct member of beany
	show(beany);	//prints member string once
	show(beany, 2); //prints member string twice
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3); //Shows testing string thrice, previous does it just once.
	show("Done!");
}
