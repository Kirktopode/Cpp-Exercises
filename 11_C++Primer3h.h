/* Rewrite the Stock class, as described in Listings 10.7 and 10.8 in Chapter 10, so that it
uses dynamically allocated memory directly instead of using string class objects to hold
the stock names. Also, replace the show() member function with an overloaded
operator<<() definition. Test the new definition program in Listing 10.9. */
#include <iostream>
using namespace std;

#ifndef STOCK2_H_
#define STOCK2_H_
class Stock
{
private:
char * company;
int shares;
double share_val;
double total_val;
void set_tot() { total_val = shares * share_val; }
public:
Stock(); // default constructor
Stock(const char * co, int n = 0, double pr = 0.0);
~Stock(); // do-nothing destructor
void buy(int num, double price);
void sell(int num, double price);
void update(double price);
friend ostream & operator<<(ostream & os, const Stock & s);
const Stock & topval(const Stock & s) const;
};
#endif
