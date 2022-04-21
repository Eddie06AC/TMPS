#include<iostream>
#include"Header.h"

using namespace std;


int main() 
{
	Person* per = new Person();
	Bike* bike = new Bike();
	Bus* bus = new Bus();
	Car* car = new Car();

	Route* route = new Route();

	cout << "Where you go?\n1.Cekani - Riskanovka(3.2 km)\n2.Riskanovka - Botanika(4.7 km)\n3.Botanika - Tentr(2.8 km)\n4.Tentr - Buiukani(2.1 km)" << endl;
	int m;
	cin >> m;

	cout << "What route?\n1.Person\n2.Bike\n3.Bus\n4.Car" <<endl;
	int n;
	cin >> n;
	switch (n)
	{
		case 1:route->set_strategy(per); break;
		case 2: route->set_strategy(bike); break;
		case 3: route->set_strategy(bus); break;
		case 4: route->set_strategy(car); break;
	}
	
	
	route->do_route_strategy(m);

	return 0;
}