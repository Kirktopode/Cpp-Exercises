#include "9_C++Primer6h.h"
#include <iostream>
using namespace std;

List::List()
{
	max = 10;
	total = 0;
}

bool List::append(int n)
{
	if (total < 10)
	{
		contents[total] = n;
		total++;
		return true;
	}
	return false;
}

bool List::isFull() const
{
	return total == 10;
}

bool List::isEmpty() const
{
	return total == 0;
}

void List::visit (void(*pf)(int &))
{
	for(int i = 0; i < total; i++)
		(*pf)(contents[i]);
}

void List::print() const
{
	if(total == 0)
		cout << "Listypants is EMPTY.\n";
	for(int i = 0; i < total; i++)
	{
		cout << "Item " << i << ": " << contents[i] << endl;
	}
}

int List::len() const
{
	return total;
}

void doubleMe(int &n)
{
	n *= 2;
}

void sayWords(int &n)
{
	switch(n)
	{
		case 0: cout << 'A'; break;
		case 1: cout << 'B'; break;
		case 2: cout << 'C'; break;
		case 3: cout << 'D'; break;
		case 4: cout << 'E'; break;
		case 5: cout << 'F'; break;
		case 6: cout << 'G'; break;
		case 7: cout << 'H'; break;
		case 8: cout << 'I'; break;
		case 9: cout << 'J'; break;
		case 10: cout << 'K'; break;
		case 11: cout << 'L'; break;
		case 12: cout << 'M'; break;
		case 13: cout << 'N'; break;
		case 14: cout << 'O'; break;
		case 15: cout << 'P'; break;
		case 16: cout << 'Q'; break;
		case 17: cout << 'R'; break;
		case 18: cout << 'S'; break;
		case 19: cout << 'T'; break;
		case 20: cout << 'U'; break;
		case 21: cout << 'V'; break;
		case 22: cout << 'W'; break;
		case 23: cout << 'X'; break;
		case 24: cout << 'Y'; break;
		case 25: cout << 'Z'; break;
		default: cout << ' '; break;
	}
}

void cutMe(int &n)
{
	n /= 3;
}
