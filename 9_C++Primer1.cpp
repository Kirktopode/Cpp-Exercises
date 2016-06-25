#include <iostream>
#include <cstring>
using namespace std;

class Mage
{
	private:
		enum{Len = 30};
		char name[Len];
		char spec[Len];
		double gold;
	public:
		Mage(const char * n, const char * s, double g = 0);
		void display();
		void pay(double g);
		void spend(double g);
};

Mage::Mage(const char *n, const char *s, double g)
{
	strncpy(name, n, Len);
	strncpy(spec, s, Len);
	gold = g;
}

void Mage::display()
{
	cout << "The grand mage " << name << " is a master of " << spec << " and has a net worth of " << gold << " gold.\n";
}

void Mage::pay(double g)
{
	gold += g;
	cout << name << " earns " << g << " gold.\n";
}

void Mage::spend(double g)
{
	if(g > gold)
	{
		cout << name << " tries to spend money on stupid crap, but needs " << g - gold << " more gold to do so.\n";
		return;
	}
	gold -= g;
	cout << name << " spends " << g << " gold on stupid crap.\n";
}

int main()
{
	Mage merly("Drannicus", "necromancy", 424.54);
	merly.display();
	merly.spend(424.55);
	merly.display();
	merly.pay(.01);
	merly.display();
	merly.spend(424.55);
	merly.display();
	return 0;
}
