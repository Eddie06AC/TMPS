#ifndef Header
#define Header
#include<iostream>
#include<string>
#pragma warning(disable : 4996)

using namespace std;

class Main_Handler
{
private:
Main_Handler* pizza_handler;
public:
Main_Handler(Main_Handler* s = nullptr) : pizza_handler(s) {}
~Main_Handler() {}
virtual void Adding_ingredient(string recepient[])
{
    if (pizza_handler)
        pizza_handler->Adding_ingredient(recepient);
}
};

class Crust : public Main_Handler
{
public:
Crust(Main_Handler* s = nullptr) : Main_Handler(s) {}
~Crust() {}
void Adding_ingredient(string recepient[])
{
    for (int i = 0; i < recepient->length(); i++)
    {
        if (recepient[i] == "crust")
        {
            cout << "Baked crust for pizza" << endl;
        }
    }
    Main_Handler::Adding_ingredient(recepient);
}
};

class Sauce : public Main_Handler
{
public:
Sauce(Main_Handler* s = nullptr) : Main_Handler(s) {}
~Sauce() {}
void Adding_ingredient(string recepient[])
{
    for (int i = 0; i < recepient->length(); i++)
    {
        if (recepient[i] == "sweet sauce")
        {
            cout << "The crust was smeared with sweet sauce" << endl;
        }

        else if (recepient[i] == "spicy sauce")
        {
            cout << "The crust was smeared with spicy sauce" << endl;
        }
    }
    Main_Handler::Adding_ingredient(recepient);
}
};

class Tomatoes : public Main_Handler
{
public:
Tomatoes(Main_Handler* s = nullptr) : Main_Handler(s) {}
~Tomatoes() {}
void Adding_ingredient(string recepient[])
{
    for (int i = 0; i < recepient->length(); i++)
    {
        if (recepient[i] == "tomatoes")
        {
            cout << "Tomatoes were added to the pizza." << endl;
        }
    }
    Main_Handler::Adding_ingredient(recepient);
}
};

class Sausage_meat : public Main_Handler
{
public:
Sausage_meat(Main_Handler* s = nullptr) : Main_Handler(s) {}
~Sausage_meat() {}
void Adding_ingredient(string recepient[])
{
    for (int i = 0; i < recepient->length(); i++)
    {
        if (recepient[i] == "sausage")
        {
            cout << "Sliced sausage was added to the pizza." << endl;
        }
        else if (recepient[i] == "meat(chicken)")
        {
            cout << "Chicken meat was added to the pizza" << endl;
        } 
        else if (recepient[i] == "meat(fish)")
        {
            cout << "Fish meat was added to the pizza" << endl;
        }
    }
    Main_Handler::Adding_ingredient(recepient);
}
};

class Cheese_olives : public Main_Handler
{
public:
Cheese_olives(Main_Handler* s = nullptr) : Main_Handler(s) {}
~Cheese_olives() {}
void Adding_ingredient(string recepient[])
{
    for (int i = 0; i < recepient->length(); i++)
    {
        if (recepient[i] == "olives")
    {
        cout << "Olives were added to the pizza." << endl;
    } 
        else if (recepient[i] == "cheese")
    {
        cout << "The pizza was sprinkled with grated cheese." << endl;
    }
}
    cout << "\nYour pizza is being cooked, the total waiting time is 20 to 30 minutes." << endl;
    _sleep(3000);
    cout << "Your pizza is ready. Bon appetit!\n" << endl;
}
};

void Recepient(string recepient[])
{
    for (int i = 0; i < recepient->length(); i++)
    {
        if(i == recepient->length()-1)
            cout << recepient[i]<<".";
        else
        cout << recepient[i]<< " with ";
    }
}


#endif // !Header
