#include <iostream>
#include <cstring>

using namespace std;
struct MightyWarrior
{
	char name[20];
	double weight;
	int enemiesSlain;
};

void warriorEdit(MightyWarrior &man, const char*nuname = "Genericus", double nuweight = 222.22, int nuslain = 90)
{
	strcpy(man.name, nuname);
	man.weight = nuweight;
	man.enemiesSlain = nuslain;
}
void warriorDisplay(const MightyWarrior &man)
{
	cout << man.name << " is a mighty warrior indeed! He weighs " << man.weight << " stone and has slain " << man.enemiesSlain << " foes.\n";
}

int main()
{
	MightyWarrior Bob = {"Cronan Borbufus", 345.19, 456};
	warriorDisplay(Bob);
	cout << "Now we shall speak of Doobus.\n";
	warriorEdit(Bob);
	warriorDisplay(Bob);
	cout << "What? Why did I speak of Genericus? I wish to speak of Doobus!\n";
	warriorEdit(Bob, "Doobus", 908.789, 45678);
	warriorDisplay(Bob);
	return 0;
}
