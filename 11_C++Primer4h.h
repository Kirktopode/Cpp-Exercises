class Stack
{
private:
	enum {MAX = 10}; // constant specific to class
	int * pitems; // holds stack items
	int size; // number of elements in stack
	int top; // index for top stack item
public:
	Stack(int n = 10); // creates stack with n elements
	Stack(const Stack & st);
	~Stack();
	bool isempty() const;
	bool isfull() const;
	// push() returns false if stack already is full, true otherwise
	bool push(const int & item); // add item to stack
	// pop() returns false if stack already is empty, true otherwise
	bool pop(int & item); // pop top into item
	Stack & operator=(const Stack & st);
};
