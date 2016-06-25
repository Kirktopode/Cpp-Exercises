class List
{
	private:
		int contents[10];
		int max;
		int total;
	public:
		List();
		bool append(int n);
		bool isFull() const;
		bool isEmpty() const;
		void visit (void(*pf)(int &));
		int len() const;
		void print() const;
};

void cutMe(int &n);

void sayWords(int &n);

void doubleMe(int &n);
