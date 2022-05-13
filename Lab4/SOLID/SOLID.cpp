#include <iostream>
#include"SOLID.h"
#include<iomanip>
int main()
{
	Triangle* triagnle = new Triangle();
	Square* square = new Square();
	Rectangle* rectangle = new Rectangle();

	int const array_size = 5;
	Figure* avaible_figures[array_size];
	for (int i = 0; i < array_size; i++)
		avaible_figures[i] = 0;
	DrawingSkills(avaible_figures, 9);
	cout << "After adding some figures.\n" << endl;
	add_to_array(avaible_figures, array_size, triagnle);
	add_to_array(avaible_figures, array_size, square);
	add_to_array(avaible_figures, array_size, rectangle);
	/*add_to_array(avaible_figures, array_size, triagnle);
	add_to_array(avaible_figures, array_size, triagnle);
	add_to_array(avaible_figures, array_size, triagnle);*/
	DrawingSkills(avaible_figures, 10);

	cout << "Diagonal(square) with part - 8sm x 8sm = " << std::fixed << std::setprecision(2) << square->calc_diagonal(8.f, 8.f) << endl;;
	cout << "Diagonal(rectangle) with part - 8sm x 12sm  = " << std::fixed << std::setprecision(2) << rectangle->calc_diagonal(5.f, 14.f) << endl;

	return 0;
}

