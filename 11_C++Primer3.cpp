#include <iostream>
#include <cstring>
using namespace std;
#include "11_C++Primer3h.h"
// constructors
Stock::Stock() // default constructor
{
	company = new char[8];
	strcpy(company, "no name");
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}
Stock::Stock(const char * co, int n, double pr)
{
	company = new char[strlen(co) + 1];
	std::strcpy(company, co);
	if (n < 0)
	{
		std::cerr << "Number of shares can’t be negative; " 
		<< company << " shares set to 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}
// class destructor
Stock::~Stock() // quiet class destructor
{
}
// other methods
void Stock::buy(int num, double price)
{
	if (num < 0)
	{
		std::cerr << "Number of shares purchased can’t be negative. "
		<< "Transaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}
void Stock::sell(int num, double price)
{
	using std::cerr;
	if (num < 0)
	{
		cerr << "Number of shares sold can't be negative. "
		<< "Transaction is aborted.\n";
	}
	else if (num > shares)
	{
		cerr << "You can’t sell more than you have! "
		<< "Transaction is aborted.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}
void Stock::update(double price)
{
	share_val = price;
	set_tot();
}
 ostream & operator<<(ostream & os, const Stock & s)
{
	os << "Company: " << s.company
	<< " Shares: " << s.shares << endl
	<< " Share Price: $" << s.share_val
	<< " Total Worth: $" << s.total_val << endl;
}
const Stock & Stock::topval(const Stock & s) const
{
	if (s.total_val > total_val)
		return s;
	else
	return *this;
}

const int STKS = 4;
int main()
{
	// create an array of initialized objects
	Stock stocks[STKS] = {
		Stock("NanoSmart", 12, 20.0),
		Stock("Boffo Objects", 200, 2.0),
		Stock("Monolithic Obelisks", 130, 3.25),
		Stock("Fleep Enterprises", 60, 6.5)
	};
	cout.precision(2); // #.## format
	cout.setf(ios_base::fixed, ios_base::floatfield);// #.## format
	cout.setf(ios_base::showpoint); // #.## format
	cout << "Stock holdings:\n";
	int st;
	for (st = 0; st < STKS; st++)
		cout << stocks[st];
	Stock top = stocks[0];
	for (st = 1; st < STKS; st++)
		top = top.topval(stocks[st]);
	cout << "\nMost valuable holding:\n";
	cout << top;
	return 0;
}
