#include <iostream>
#include <cstring>
#include "8_C++Primer4h.h"

using namespace std;
//get name, enchantment bonus from user, sets members of s to values entered.
//returns 1 if name is entered, 0 if name is empty string
int setSword (sword & s)
{
	cout << "What name ye this sword, smithe?\n";
	cin.getline(s.fullname, Len);
	cout << "What value of enchantment give ye it?\n";
	cin >> s.enchantment; cin.get();
	if(s.fullname[0] == '\0')
		return 0;
	return 1;
}

//function sets sword structure to provided name, enchantment
//using values passed as arguments to the funcition
void setSword(sword & s, const char * name, int ench)
{
	strcpy(s.fullname, name);
}

//function resets enchantment to new value
void reenchant(sword & s, int ench)
{
	s.enchantment = ench;
}

//function displays contents of sword structure
void showSword(const sword & s)
{
	cout << "Thy blade hath the name of \"" << s.fullname << "\" and hath an enchantment of ";
	if (s.enchantment > 0)
		cout << "+" << s.enchantment << ".\n";
	else
		cout << s.enchantment << ".\n";
}
