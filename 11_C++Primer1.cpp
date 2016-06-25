#include <iostream>
#include <cstring>
using namespace std;

class Rogue 
{
	private:
		char name[20];
		char * talent;
		double weight;
	public:
		Rogue();
		Rogue(const char * nm, const char * t, double wt);
		Rogue(const Rogue &r);
		~Rogue();
		Rogue & operator=(const Rogue & r);
		void ShowRogue() const; // display all Rogue data
};
Rogue::Rogue()
{
	strcpy(name, "Generic Footpad");
	talent = NULL;
	weight = 0;
}
Rogue::Rogue(const char *nm, const char *t, double wt)
{
	strncpy(name, nm, 19);
	name[19] = '\0';
	talent = new char[strlen(t) + 1];
	strcpy(talent, t);
	weight = wt;
}
Rogue::Rogue(const Rogue &r)
{
	strcpy(name, r.name);
	talent = new char[strlen(r.talent) + 1];
	strcpy(talent, r.talent);
	weight = r.weight;
}
Rogue::~Rogue()
{
	delete [] talent;
}
Rogue & Rogue::operator=(const Rogue & r)
{
	strcpy(name, r.name);
	talent = new char[strlen(r.talent) + 1];
	strcpy(talent, r.talent);
	weight = r.weight;
}
void Rogue::ShowRogue() const
{
	cout << name << " is good at " << talent << " and is " << weight << " kilograms fat.\n";
}

int main()
{
	Rogue bob = Rogue("Bobert", "bobbery", 1234.2); bob.ShowRogue();
	Rogue narf = bob; narf.ShowRogue();
	Rogue foop = Rogue("Foopogori fomori famdomonogobo", "fooping around all of the town all of the time", .05); foop.ShowRogue();
	narf = foop; narf.ShowRogue();
	return 0;
}
