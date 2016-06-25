#include <iostream>
using namespace std;

struct Item
{
	char fullname[35];
	double payment;
};

class Stack
{
	private:
		enum {MAX = 10}; // constant specific to class
		Item items[MAX]; // holds stack items
		int top; // index for top stack item
	public:
		Stack();
		bool isempty() const;
		bool isfull() const;
		// push() returns false if stack already is full, true otherwise
		bool push(const Item & item); // add item to stack
		// pop() returns false if stack already is empty, true otherwise
		bool pop(Item & item); // pop top into item
};

Stack::Stack() // create an empty stack
{
	top = 0;
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == MAX;
}

bool Stack::push(const Item & item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
		return false;
}

bool Stack::pop(Item & item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}

using namespace std;




int main()
{
	/*	Write a program that adds and removes customer structures from a stack, represented by
	a Stack class declaration. Each time a customer is removed, his or her payment should
	be added to a running total, and the running total should be reported */
	Stack tastic;
	double total = 0;
	Item ilist[12] = 	{{"Magic Sum", 5.3}, 
						{"Salty Drum", 4.3}, 
						{"Cruel Plum", 3}, 
						{"Angry Crumb", 2.8}, 
						{"Paltry Bum", 90.5}, 
						{"Sitting Numb", 12.23}, 
						{"Saber Gum", 34.43},
						{"Candied Hum", 1.001},
						{"Angled Mum", 10},
						{"Power Rum", 45.3},
						{"Bacon Yum", 2.02},
						{"Kalan Xum", 0.001}};
	
	if(tastic.isempty())
	{
		cout << "Stack Tastic is empty!\n";
	}	
	int i = 0;
	while(tastic.push(ilist[i]))
	{
		cout << "Adding " << ilist[i].fullname << " to Stack Tastic.\n";
		i++;
	}
	if(tastic.isfull())
	{
		cout << "Stack Tastic is full!\n";
	}
	i--;
	while(tastic.pop(ilist[i]))
	{
		cout << "Paying a price of " << ilist[i].payment << " for " << ilist[i].fullname << endl;;
		total += ilist[i].payment;
		i--;
	}
	if(tastic.isempty())
	{
		cout << "Stack Tastic is empty!\n";
	}
	
	cout << "\n\nHere's the new ilist:\n";
	for(i = 0; i < 12; i++)
	{
		cout << ilist[i].fullname << " " << ilist[i].payment << endl;
	}
	
	cout << "Here's the total: " << total;
	
	return 0;
}
