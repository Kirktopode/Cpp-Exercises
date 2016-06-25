#include<iostream>
using namespace std;
#include "11_C++Primer4h.h"

/*
enum {MAX = 10}; // constant specific to class
int * pitems; // holds stack items
int size; // number of elements in stack
int top; // index for top stack item
*/

Stack::Stack(int n) : size(n), top(0) // creates stack with n elements
{
	if(n > 10 || n < 1)
	{
		cerr << "Bad stack size -- must be 1-10\n";
		exit(1);
	}
	pitems = new int[size];
}
Stack::Stack(const Stack & st) : size(st.size), top(st.top)
{
	pitems = new int[size];
	for(int i = 0; i < st.top; i++)
		pitems[i] = st.pitems[i];
}
Stack::~Stack()
{
	delete[] pitems;
}
bool Stack::isempty() const
{
	return top == 0;
}
bool Stack::isfull() const
{
	return top == size;
}
// push() returns false if stack already is full, true otherwise
bool Stack::push(const int & item)
{
	if(top == size)
		return false;
	pitems[top++] = item;
	return true;
}
bool Stack::pop(int & item)
{
	if(top == 0)
		return false;
	item = pitems[--top];
	return true;
}
Stack & Stack::operator=(const Stack & st)
{
	top = st.top; size = st.size;
	pitems = new int[size];
	for(int i = 0; i < st.top; i++)
		pitems[i] = st.pitems[i];
}

int main()
{
	Stack first;
	Stack second(7);
	int ray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int ray1[10];

	cout << "Ray: ";
	for(int i = 0; i < 10; i++)
		cout << ray[i] << " ";
	cout << "Ray1 is empty.\n\n";

	for(int i = 0; first.push(ray[i]); i++)
		cout << "Adding " << ray[i] << " to first from ray!\n";
	for(int i = 0; first.pop(ray1[i]); i++)
		cout << ray1[i] << " popped from first into ray1!\n";
	for(int i = 0; second.push(ray1[i]); i++)
		cout << "Adding " << ray1[i] << " to second from ray1!\n";
	for(int i = 0; second.pop(ray[i]); i++)
		cout << ray[i] << " popped from second into ray!\n";
	
	cout << "\nRay: ";
	for(int i = 0; i < 10; i++)
		cout << ray[i] << " ";
		
	cout << endl << "\nRay1: ";
	for(int i = 0; i < 10; i++)
		cout << ray1[i] << " ";
}
