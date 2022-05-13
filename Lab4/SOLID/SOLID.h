#ifndef SOLID
#define SOLID
#include<iostream>
using namespace std;

// Open Closed 
// Liskov
// Interface Segregation 

class Figure
{
public:
	virtual void draw(int heght) = 0;
};

class Diagonal_figure 
{
public: 
	virtual float calc_diagonal(float a, float b) = 0;
};

void DrawingSkills(Figure* array[], int heght);
void add_to_array(Figure* array[], int length, Figure* a);	

class Square :public Figure, public Diagonal_figure
{
public:
	virtual void draw(int heght)
	{
		for (int i = 0; i < heght; i++)
		{
			if (i == 0 || i == heght - 1)
			{
				for (int j = 0; j < heght; j++)
				{
					cout << "* ";
				}
			}
			else
			{
				cout << "*";
				for (int j = 0; j < heght * 2 - 3; j++)
					cout << " ";
				cout << "*";
			}
			cout << endl;
		}

	}
	virtual float calc_diagonal(float a, float b) 
	{
		return sqrt(2) * a;
	}
};

class Rectangle :public Figure, public Diagonal_figure
{
public:
	virtual void draw(int heght)
	{
		for (int i = 0; i < heght; i++)
		{
			if (i == 0 || i == heght - 1)
			{
				for (int j = 0; j < heght*2; j++)
				{
					cout << "* ";
				}
			}
			else
			{
				cout << "*";
				for (int j = 0; j < heght*4-3; j++)
					cout << " ";
				cout << "*";
			}
			cout << endl;
		}

	}
	virtual float calc_diagonal(float a, float b)
	{
		return sqrt(a*a+b*b);
	}
};

class Triangle :public Figure
{
public:
	virtual void draw(int heght)
	{
		for (int i = 0; i < heght; i++)
		{
			for (int j = heght - 1; j > i; j--)
			{
				cout << " ";
			}
			for (int j = 0; j < 2 * i + 1; j++)
			{
				cout << "*";
			}
			cout << endl;
		}
	}
};

void DrawingSkills(Figure* array[],int heght)
{
	if (array[0] == 0)
		cout << "Error! Array is empty.\n";
	else
	{
		for (int i = 0; array[i]; i++)
		{
			array[i]->draw(heght);
			cout << endl;
		}
	}
}

void add_to_array(Figure* array[], int length, Figure* a)
{
	for (int i = 0; i < length; i++)
	{
		if (array[length - 1] != 0)
		{
			cout << "Error! Array is full. Free up space!\n";
			break;
		}
		else if (array[i] == 0)
		{
			array[i] = a;
			break;
		}
	}
}
#endif // !SOLID
