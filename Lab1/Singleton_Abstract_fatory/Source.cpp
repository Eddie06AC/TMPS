#include"Header.h"
#include<iostream>

using namespace std;

int main()
{
	int k = 0;
	Calculator* kal1 = Calculator::get_instance();
	Calculator* kal2 = Calculator::get_instance();
	cout << "First instance: " << kal1 << endl;
	cout << "Second instance: " << kal2 << endl;
	while (k != 5)
	{
		cout << "Menu:" << endl;
		cout << "1.Addition()\n2.Subtraction()\n3.Multiplication()\n4.Division()\n5.Exit...\n";
		cout << "Enter your choise: ";
		cin >> k;
		switch (k)
		{
		case 1: kal1->addition(); break;
		case 2: kal1->subtraction(); break;
		case 3: kal1->multiplication(); break;
		case 4: kal1->division(); break;
		default: if (k == 5)
			break;
			   else
		{
			cout << "\nERROR! Try again...\n\n";
		}
			   break;
		}
	}
	return 0;
}