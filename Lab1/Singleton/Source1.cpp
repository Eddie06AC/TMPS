#include"Header.h"

#include<iostream>

calculator* calculator::instance = 0;

calculator::calculator() {};

calculator::~calculator() {};

calculator* calculator::get_instance()
{
	if (instance == 0) 
	{
		instance = new calculator();
	}
	return instance;
}

void calculator::addition()
{
	float a, b, c = 0; int m = 0;
	cout << "With what numbers do you want to work?\n With real(1) or integer(2): ";
	cin >> m;
	if (m == 1)
	{
		cout<<"Enter the numbers you want to add: ";
		cin >> a >> b;
		c = a + b;
		cout<<"Result: "<<c<<endl;
	}
	else
	{
		int a1, b1, c1 = 0;
		cout<<"Enter the numbers you want to add: ";
		cin >> a1 >> b1;
		c1 = a1 + b1;
		cout<<"Result: "<< c1<<endl;
	}
}

void calculator::subtraction() 
{
	float a, b, c = 0; int m = 0;
	cout<< "With what numbers do you want to work?\n With real(1) or integer(2): ";
	cin >> m;
	if (m == 1)
	{
		cout<<"Enter the numbers you want to use for subtraction.\nExample(a-b): ";
		cin >> a >> b;
		c = a - b;
		cout<<"Result: "<<c<<endl;
	}
	else
	{
		int a1, b1, c1 = 0;
		cout << "Enter the numbers you want to use for subtraction.\nExample(a-b): ";
		cin >> a1 >> b1;
		c1 = a1 - b1;
		cout << "Result: "<<c1<<endl;
	}
}

void calculator::multiplication() 
{
	float a, b, c = 0; int m = 0;
	cout << "With what numbers do you want to work?\n With real(1) or integer(2): ";
	cin >> m;
	if (m == 1)
	{
		cout<<"Enter the numbers you want to use for multiplication: ";
		cin >> a >> b;
		c = a * b;	
		cout << "Result: " << c << endl;
	}
	else
	{
		int a1, b1, c1 = 0;
		cout << "Enter the numbers you want to use for multiplication: ";
		cin >> a1 >> b1;
		c1 = a1 * b1;
		cout << "Result: " << c1 << endl;
	}
}

void calculator::division() 
{
	float a, b, c = 0; int m = 0;
	cout << "With what numbers do you want to work?\n With real(1) or integer(2): ";
	cin >> m;
	if (m == 1)
	{
		cout << "Enter the numbers you want to use for division.\nExample(a/b): ";
		cin >> a >> b;
		while  (b == 0)
		{
			cout<<"Do not enter zero(0)!!!"<<endl;
			cin >> b;
		}
		c = a / b;
		cout << "Result: " << c << endl;
	}
	else
	{
		int a1, b1;
		float c1 = 0;
		cout << "Enter the numbers you want to use for division.\nExample(a/b): ";
		cin >> a1>> b1;
		while (b1 == 0)
		{
			cout << "Do not enter zero(0)!!!" << endl;
			cin >> b1;
		}
		c1 = (float)a1 / (float)b1; 
		cout.precision(3); 
		cout << "Result: " << c1<<endl;;
	}
}