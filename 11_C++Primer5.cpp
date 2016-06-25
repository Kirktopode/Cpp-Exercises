#include <ctime> // for time()
#include "11_C++Primer5h.h"
#include <cstdlib> // (or stdlib.h) for rand()
#include <iostream>
// Queue methods
Queue::Queue(int qs) : qsize(qs)
{
	front = rear = NULL;
	items = 0;
}
Queue::~Queue()
{
	Node * temp;
while (front != NULL) // while queue is not yet empty
{
	temp = front; // save address of front item
	front = front->next;// reset pointer to next item
	delete temp; // delete former front
}
}
bool Queue::isempty() const
{
	return items == 0;
}
bool Queue::isfull() const
{
	return items == qsize;
}
int Queue::queuecount() const
{
	return items;
}
// Add item to queue
bool Queue::enqueue(const Item & item)
{
	if (isfull())
		return false;
	Node * add = new Node; // create node
	if (add == NULL)
		return false; // quit if none available
	add->item = item; // set node pointers
	add->next = NULL;
	items++;
	if (front == NULL) // if queue is empty,
		front = add; // place item at front
	else
		rear->next = add; // else place at rear
	rear = add; // have rear point to new node
return true;
}

bool Queue::dequeue(Item & item)
{
	if (front == NULL)
		return false;
	item = front->item; // set item to first item in queue
	items--;
	Node * temp = front; // save location of first item
	front = front->next; // reset front to next item
	delete temp; // delete former first item
	if (items == 0)
		rear = NULL;
	return true;
}
// customer method
// when is the time at which the customer arrives
// the arrival time is set to when and the processing
// time set to a random value in the range 1 - 3
void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}


const int MIN_PER_HR = 60;
bool newcustomer(double x); // is there a new customer?
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;
	// setting things up
	std::srand(std::time(0)); // random initializing of rand()
	cout << "Case Study: Bank of Heather Automatic Teller\n";
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;
	Queue line1(qs); // line queue holds up to qs people
	Queue line2(qs); //QUEUE TWO
	cout << "Enter the number of simulation hours: ";
	int hours; // hours of simulation
	cin >> hours;
	// simulation will run 1 cycle per minute
	long cyclelimit = MIN_PER_HR * hours; // # of cycles
	cout << "Enter the average number of customers per hour: ";
	double perhour; // average # of arrival per hour
	cin >> perhour;
	double min_per_cust; // average time between arrivals
	min_per_cust = MIN_PER_HR / perhour;
	Item temp; // new customer data
	long turnaways = 0; // turned away by full queue
	long customers = 0; // joined the queue
	long served = 0; // served during the simulation
	long sum_line1 = 0; // cumulative line length
	long sum_line2 = 0; //QUEUE2?
	int wait_time1 = 0; // time until autoteller is free
	int wait_time2 = 0; //QUEUE2?
	long line_wait1 = 0; // cumulative time in line
	long line_wait2 = 0;
	// running the simulation
	for (int cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (newcustomer(min_per_cust)) // have newcomer
		{
			if (line1.isfull() && line2.isfull()) //MODIFIED FOR TWO QUEUES
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle); // cycle = time of arrival
				if(line2.queuecount() > line1.queuecount()).
					line1.enqueue(temp); // add newcomer to line
				else
					line2.enqueue(temp);
			}
		}
		if (wait_time1 <= 0 && !line1.isempty()) //LINE 1
		{
			line1.dequeue (temp); // attend next customer
			wait_time1 = temp.ptime(); // for wait_time minutes
			line_wait1 += cycle - temp.when();
			served++;
		}
		if (wait_time1 > 0)
			wait_time1--;
		sum_line1 += line1.queuecount();
		if (wait_time2 <= 0 && !line2.isempty()) //LINE 2
		{
			line2.dequeue (temp); // attend next customer
			wait_time2 = temp.ptime(); // for wait_time minutes
			line_wait2 += cycle - temp.when();
			served++;
		}
		if (wait_time2 > 0)
			wait_time2--;
		sum_line2 += line2.queuecount();
	}
	// reporting results
	if (customers > 0)
	{
		cout << "customers accepted: " << customers << endl;
		cout << " customers served: " << served << endl;
		cout << " turnaways: " << turnaways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.setf(ios_base::showpoint);
		cout << (double) (sum_line1 + sum_line2) / (2*cyclelimit) << endl;
		cout << " average wait time: "
		<< (double) (line_wait1 + line_wait2) / (2*served) << " minutes\n";
	}
	else
		cout << "No customers!\n";
	cout << "Done!\n";
	return 0;
}
// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}
