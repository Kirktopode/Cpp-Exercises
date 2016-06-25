#include <iostream>
#include <cstring>
#include "9_C++Primer2h.h"

using namespace std;

int sword::reset()
{
	cout << "What name ye this sword, smithe?\n";
	cin.getline(fullname, Len);
	if(fullname[0] == '\0')
	{
		cout << "Thou ceaseth to make additional swords.\n";
		return 0;
	}
	cout << "What value of enchantment give ye it?\n";
	cin >> enchantment; cin.get();
	return 1;
}

sword::sword(const char * name, int ench)
{
	strncpy(fullname, name, Len);
	enchantment = ench;
}

void sword::reenchant(int ench)
{
	enchantment = ench;
}

void sword::showSword()
{
	cout << "Thy blade hath the name of \"" << fullname << "\" and hath an enchantment of ";
	if (enchantment > 0)
		cout << "+" << enchantment << ".\n";
	else
		cout << enchantment << ".\n";
}
