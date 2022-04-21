#include<iostream>
#include"Header.h"
#include<string>

using namespace std;

int main()
{
    //{"crust","sweet sauce","spicy sauce","tomatoes","sausage","meat(chicken)","meat(fish)","olives","cheese"};

    string pizza_classic[] = { "crust","sweet sauce","tomatoes","sausage","cheese" };
    string pizza_chicken[] = { "crust","sweet sauce","tomatoes","meat(chicken)","cheese" };
    string pizza_fish[] = { "crust","sweet sauce","tomatoes","meat(fish)","olives" };
    string pizza_diablo[] = { "crust","spicy sauce","tomatoes","sausage","olives","cheese" };

    Cheese_olives* cheese_olives = new Cheese_olives();
    Sausage_meat* sausage_meat = new Sausage_meat(cheese_olives);
    Tomatoes* tomatoes = new Tomatoes(sausage_meat);
    Sauce* sauce = new Sauce(tomatoes);
    Crust* crust = new Crust(sauce);
    Main_Handler* main_handler = new Main_Handler(crust);

    cout << "Execution order - Pizza Classic is: "; Recepient(pizza_classic); cout << endl << endl;
    main_handler->Adding_ingredient(pizza_classic);
    cout << "Execution order - Pizza with chicken meat is: "; Recepient(pizza_chicken); cout << endl << endl;
    main_handler->Adding_ingredient(pizza_chicken);
    cout << "Execution order - Pizza with fish meat is: "; Recepient(pizza_fish); cout << endl << endl;
    main_handler->Adding_ingredient(pizza_fish);
    cout << "Execution order - Diablo is: "; Recepient(pizza_diablo); cout << endl << endl;
    main_handler->Adding_ingredient(pizza_diablo);
   
    return 0;
}