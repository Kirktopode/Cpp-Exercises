const int Len = 40;

struct sword
{
	char fullname[Len];
	int enchantment;
};

//get name, enchantment bonus from user, sets members of s to values entered.
//returns 1 if name is entered, 0 if name is empty string
int setSword (sword & s);

//function sets sword structure to provided name, enchantment
//using values passed as arguments to the funcition
void setSword(sword & s, const char * name, int ench);

//function resets enchantment to new value
void reenchant(sword & s, int ench);

//function displays contents of sword structure
void showSword(const sword & s);
