#include<iostream>
#include"9_C++Primer6h.h"
using namespace std;
int main()
{

	
	int nums[] = {10, 45, 15, 3, 6, 30, 9, 18, 12, 21,};
	List listypants = List();
	
	if(listypants.isEmpty())
		cout << "Listypants is empty. :( \n";
	for(int i = 0; i < 10; i++)
	{
		listypants.append(nums[i]);
	}
	if(listypants.isFull())
		cout << "Listypants is full!\n";
	listypants.visit(sayWords);cout << endl; cout << endl;
	listypants.print(); cout << endl;
	listypants.visit(cutMe);
	listypants.visit(sayWords);cout << endl; cout << endl;
	listypants.print(); cout << endl;
	listypants.visit(sayWords);cout << endl; cout << endl;
	listypants.print();cout << endl;
	listypants.visit(cutMe);
	listypants.visit(sayWords);cout << endl; cout << endl;
	listypants.print();cout << endl;
	listypants.visit(doubleMe);
	listypants.visit(sayWords);cout << endl; cout << endl;
	listypants.print();cout << endl;
	return 0;
}
