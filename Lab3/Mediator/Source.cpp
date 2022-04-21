#include<iostream>
#include"Header.h"

using namespace std;

int main()
{
	Member_Vertical_car* v_car = new Member_Vertical_car();
	Member_Horizontal_car* h_car = new Member_Horizontal_car();

	ConcreteMediator* med = new ConcreteMediator(v_car,h_car);

	v_car->see("red");
	v_car->see("green");
	h_car->see("red");
	h_car->see("green");

	return 0; 
}