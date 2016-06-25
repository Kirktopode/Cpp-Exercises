#include <iostream>
using namespace std;

class Move
{
	private:
		double x;
		double y;
	public:
		Move(double a = 0, double b = 0); // sets x, y to a, b
		showMove() const; // shows current x, y values
		Move add(const Move & m) const;
		// this function adds x of m to x of invoking object to get new x,
		// adds y of m to y of invoking object to get new y, creates a new
		// move object initialized to new x, y values and returns it
		reset(double a = 0, double b = 0); // resets x,y to a, b
};

Move::Move(double a, double b)
{
	x = a; y = b;
}
Move::showMove() const
{
	cout << "(" << x << ", " << y << ")\n";
}
Move Move::add(const Move &m) const
{
	Move t = Move(x + m.x, y + m.y);
	return t;
}
Move::reset(double a, double b)
{
	x = a; y = b;
}

int main()
{
	Move spot = Move(); Move ospot = Move(5, 2);
	spot.showMove(); ospot.showMove();
	spot = spot.add(ospot); ospot = ospot.add(spot);
	spot.showMove(); ospot.showMove();
	spot.reset(); ospot.reset(-2.2, 3.4);
	spot.showMove(); ospot.showMove();
	return 0;
}
