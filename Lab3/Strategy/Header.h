#ifndef Header
#define Header 
#include<iostream>

using namespace std;

class Strategy
{
public:
	virtual int do_route()=0;
}; 

class Route
{
private:
	Strategy* strategy;
	int Cekani_Riskanovka;
	int Riskanovka_Botanika;
	int Botanika_Tentr;
	int Tentr_Buiukani;
public:
	Route() 
	{
		Cekani_Riskanovka = 3200;
		Riskanovka_Botanika = 4700;
		Botanika_Tentr = 2800;
		Tentr_Buiukani = 2100;
	}
	void set_strategy(Strategy* strategy) 
	{
		this->strategy = strategy;
	};
	void do_route_strategy(int choise) 
	{
		int route1;
		int route_k = strategy->do_route();
		cout << "The route is built according to the selected transport" << endl;
			switch (choise)
		{
		case 1: route1 = Cekani_Riskanovka / route_k;
			cout << "You route is Cekani - Riskanovka, time is " << route1 << endl; break;
		case 2: route1 = Riskanovka_Botanika / route_k;
			cout << "You route is Riskanovka - Botanika, time is " << route1 << endl; break;
		case 3: route1 = Botanika_Tentr / route_k;
			cout << "You route is Botanika - Tentr, time is " << route1 << endl; break;
		case 4: route1 = Tentr_Buiukani / route_k;
			cout << "You route is Tentr - Buiukani, time is " << route1 << endl; break;
		} 
		
	}
	
	~Route() { delete strategy; };
};

class Bus : public Strategy 
{
	int do_route()
	{
		cout << "The route is built for passing it by public transport." << endl;
		return 110;
	};
};

class Person : public Strategy
{
	int do_route()
	{
		cout << "The route is built for walking." << endl;
		return 70;
	};
};

class Bike : public Strategy
{
	int do_route()
	{
		cout << "The route is built for cycling." << endl;
		return 90;
	};
};

class Car : public Strategy
{
	int do_route()
	{
		cout << "The route is built for passing it by car." << endl;
		return 140;
	};
};
#endif // !Header
