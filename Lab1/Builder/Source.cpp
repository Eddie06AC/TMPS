#include"Header.h"

#include<iostream>

using namespace std;

int main() 
{
	Smartphone* smartphone;
	Director director;
	Builder_Flagship_smartphone builder_1;
	Builder_Sub_flagship_smartphone builder_2;
	Builder_Budget_smartphone builder_3;

	director.setBuilder(&builder_1);
	smartphone = director.getSmartphone();
	smartphone->specifications();
	cout << endl;

	director.setBuilder(&builder_2);
	smartphone = director.getSmartphone();
	smartphone->specifications();
	cout << endl;

	director.setBuilder(&builder_3);
	smartphone = director.getSmartphone();
	smartphone->specifications();
	cout << endl;

	return 0;
}