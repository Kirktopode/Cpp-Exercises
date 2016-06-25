#include <iostream>
#include <cstring>
using namespace std;

class Cd 
{ // represents a CD disk
	private:
		char * performers;
		char * label;
		int selections; // number of selections
		double playtime; // playing time in minutes
	public:
		Cd(const char * s1, const char * s2, int n, double x);
		Cd(const Cd & d);
		Cd();
		virtual ~Cd();
		virtual void Report() const; // reports all CD data
		Cd & operator=(const Cd & d);
};

class Classic : public Cd
{
	private:
		char * primary;
	public:
		Classic(const char* s1, const char* s2, const char* s3, int n, double x);
		Classic(const Classic &c);
		Classic();
		~Classic();
		void Report() const;
		Classic & operator=(const Classic &c);
};

Cd::Cd(const char * s1, const char * s2, int n, double x) : selections(n), playtime(x)
{
	performers = new char[strlen(s1)+1];
	label = new char[strlen(s2)+1];
	strcpy(performers, s1);
	strcpy(label, s2);
}
Cd::Cd(const Cd & d) : selections(d.selections), playtime(d.playtime)
{
	performers = new char[strlen(d.performers)+1];
	label = new char[strlen(d.label)+1];
	strcpy(performers, d.performers);
	strcpy(label, d.label);	
}
Cd::Cd() : selections(0), playtime(0)
{
	performers = new char[1];
	label = new char[1];
	performers[0] = label[0] = '\0';
}
Cd::~Cd()
{
	delete[] performers; delete[] label;
}
void Cd::Report() const
{
	cout << label << ": " << performers << ", selections: "
	 << selections << ", playtime: " << playtime << endl;
}
Cd & Cd::operator=(const Cd & d)
{
	selections = d.selections;
	playtime = d.playtime;
	delete[] performers; delete[] label;
	performers = new char[strlen(d.performers)+1];
	label = new char[strlen(d.label)+1];
	strcpy(performers, d.performers);
	strcpy(label, d.label);	
	return *this;
}

Classic::Classic(const char* s1, const char* s2, const char* s3, int n, double x) :
	Cd(s2, s3, n, x)
{
	primary = new char[strlen(s1)+1];
	strcpy(primary, s1);
}
Classic::Classic(const Classic &c) : Cd(c)
{
	primary = new char[strlen(c.primary) + 1];
	strcpy(primary, c.primary);
}
Classic::Classic() : Cd()
{
	primary = new char[1];
	primary[0] = '\0';
}
Classic::~Classic()
{
	delete[] primary;
}
void Classic::Report() const
{
	cout << primary << ": ";
	Cd::Report();
}
Classic & Classic::operator=(const Classic &c)
{
	Cd::operator=(c);
	delete[] primary;
	primary = new char[strlen(c.primary) + 1];
	strcpy(primary, c.primary);
	return *this;
}


void Bravo(const Cd & disk);
int main()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
	"Alfred Brendel", "Philips", 2, 57.17);
	Cd *pcd = &c1;
	cout << "Using object directly:\n";
	c1.Report(); // use Cd method
	c2.Report(); // use Classic method
	cout << "Using type cd * pointer to objects:\n";
	pcd->Report(); // use Cd method for cd object
	pcd = &c2;
	pcd->Report(); // use Classic method for classic object
	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);
	cout << "Testing assignment: ";
	Classic copy;
	copy = c2;
	copy.Report();
	return 0;
}
void Bravo(const Cd & disk)
{
	disk.Report();
}
