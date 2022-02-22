#include"Header.h"

#include<iostream>

Reshenie* factory_Int::create_reshenie() 
{
	return new Only_Int;
}

Reshenie* factory_Int_Float::create_reshenie()
{
	return new Int_Float_Numbres;
}

Calculator* Calculator::instance = 0;

Calculator::Calculator() 
{
	factory* factory_create;
	int j = 0;
	cout << "There are 2 calculators:\n1.Simple calculator(only integer numbers)\n2.Professional calculator(integer and float numbers)\n";
	cout << "Enter you choise:";
	cin >> j;
	if(j==1)
	 factory_create = new factory_Int;
	else
	 factory_create = new factory_Int_Float;
	interface_reshenia = factory_create->create_reshenie();
};

Calculator::~Calculator() {};

Calculator* Calculator::get_instance()
{
	if (instance == 0)
	{
		instance = new Calculator();
	}
	return instance;
}

void Calculator::addition() 
{
	interface_reshenia->addition();
}
void Calculator::subtraction()
{
	interface_reshenia->subtraction();
}
void Calculator::multiplication()
{
	interface_reshenia->multiplication();
}
void Calculator::division()
{
	interface_reshenia->division();
}

void Only_Int::addition()
{
	int a, b, c = 0;
	cout << "Enter the numbers you want to add: ";
	cin >> a >> b;
	c = a + b;
	cout << "Result: " << c << endl;
}

void Only_Int::subtraction()
{
	int a, b, c = 0;
	cout << "Enter the numbers you want to use for subtraction.\nExample(a-b): ";
	cin >> a >> b;
	c = a - b;
	cout << "Result: " << c << endl;
}

void Only_Int::multiplication()
{
	int a, b, c = 0;
	cout << "Enter the numbers you want to use for multiplication: ";
	cin >> a >> b;
	c = a * b;
	cout << "Result: " << c << endl;
}

void Only_Int::division()
{
	int a, b;
	float c = 0;
	cout << "Enter the numbers you want to use for division.\nExample(a/b): ";
	cin >> a >> b;
	while (b == 0)
	{
		cout << "Do not enter zero(0)!!!" << endl;
		cin >> b;
	}
	c = (float)a / (float)b;
	cout.precision(3);
	cout << "Result: " << c << endl;;
}

void Int_Float_Numbres::addition()
{
	float a, b, c = 0; int m = 0;
	cout << "With what numbers do you want to work?\n With real(1) or integer(2): ";
	cin >> m;
	if (m == 1)
	{
		cout << "Enter the numbers you want to add: ";
		cin >> a >> b;
		c = a + b;
		cout << "Result: " << c << endl;
	}
	else
	{
		int a1, b1, c1 = 0;
		cout << "Enter the numbers you want to add: ";
		cin >> a1 >> b1;
		c1 = a1 + b1;
		cout << "Result: " << c1 << endl;
	}
}

void Int_Float_Numbres::subtraction()
{
	float a, b, c = 0; int m = 0;
	cout << "With what numbers do you want to work?\n With real(1) or integer(2): ";
	cin >> m;
	if (m == 1)
	{
		cout << "Enter the numbers you want to use for subtraction.\nExample(a-b): ";
		cin >> a >> b;
		c = a - b;
		cout << "Result: " << c << endl;
	}
	else
	{
		int a1, b1, c1 = 0;
		cout << "Enter the numbers you want to use for subtraction.\nExample(a-b): ";
		cin >> a1 >> b1;
		c1 = a1 - b1;
		cout << "Result: " << c1 << endl;
	}
}

void Int_Float_Numbres::multiplication()
{
	float a, b, c = 0; int m = 0;
	cout << "With what numbers do you want to work?\n With real(1) or integer(2): ";
	cin >> m;
	if (m == 1)
	{
		cout << "Enter the numbers you want to use for multiplication: ";
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

void Int_Float_Numbres::division()
{
	float a, b, c = 0; int m = 0;
	cout << "With what numbers do you want to work?\n With real(1) or integer(2): ";
	cin >> m;
	if (m == 1)
	{
		cout << "Enter the numbers you want to use for division.\nExample(a/b): ";
		cin >> a >> b;
		while (b == 0)
		{
			cout << "Do not enter zero(0)!!!" << endl;
			cout << "Enter b:";
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
		cin >> a1 >> b1;
		while (b1 == 0)
		{
			cout << "Do not enter zero(0)!!!" << endl;
			cout << "Enter b:";
			cin >> b1;
		}
		c1 = (float)a1 / (float)b1;
		cout.precision(3);
		cout << "Result: " << c1 << endl;;
	}
}