#include <iostream>
#include <cstring>
using namespace std;

class plorg
{
	private:
		char name[20];
		int CI;
	public:
		plorg(const char *n = "Plorga");
		alterCI(int n);
		diagnose() const;
};

plorg::plorg(const char *n)
{
	strncpy(name, n, 20);
	name[20] = '\0';
	CI = 50;
}

plorg::alterCI(int n)
{
	CI = n;
}

plorg::diagnose() const
{
	cout << name << " currently has a contentment index of " << CI << endl;
}

int main()
{
	plorg bob = plorg();
	bob.diagnose();
	bob.alterCI(23);
	bob.diagnose();
	bob = plorg("Mroofrogus");
	bob.diagnose();
	return 0;
}
