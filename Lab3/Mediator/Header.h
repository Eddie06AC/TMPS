#ifndef Header
#define Header
#include<iostream>

using namespace std;

class BaseComponent;

class Mediator 
{
public:
    virtual void Notify(BaseComponent* sender, string color, int parameter)=0;
};

class BaseComponent 
{
protected:
    Mediator* med;

public:
    BaseComponent(Mediator* mediator = nullptr) : med(mediator) {}
    void set_mediator(Mediator* mediator)
    {
        this->med = mediator;
    }
};

class Member_Vertical_car : public BaseComponent
{
private:
    int par;
public:
    Member_Vertical_car() :par(0) {};
    void see(string color)
    {
        cout << "Me and the drivers in my lane(vertical) see " <<color<< endl;
        this->med->Notify(this, color, par);
    }
    string get_lane()
    {
        return "vertical";
    }
    void run()
    {
        cout << "Traffic lights: 'Verticals, start engine and move'" << endl;
    }
    void stop()
    {
        cout << "Traffic lights: 'Verticals, don't move, wait your green lights'\n" << endl;
    }
};

class Member_Horizontal_car : public BaseComponent
{
private: 
    int par;
public:
    Member_Horizontal_car():par(1) {};
    void see(string color)
    {
        cout << "Me and the drivers in my lane(horizontal) see " << color << endl;
        this->med->Notify(this, color,par);
    }
    string get_lane() 
    {
        return "horizontal";
    }
    void run() 
    {
        cout << "Traffic lights: 'Horizontal, start engine and move'" << endl;
    }
    void stop() 
    {
        cout << "Traffic lights: 'Horizontal, don't move, wait your green lights'\n" << endl;
    }
};

class ConcreteMediator : public Mediator {
private:
    Member_Vertical_car* car1;
    Member_Horizontal_car* car2;

public:
    ConcreteMediator(Member_Vertical_car* car1, Member_Horizontal_car* car2) : car1(car1), car2(car2)
    {
        car1->set_mediator(this);
        car2->set_mediator(this);
    }
    void Notify(BaseComponent* sender, string color,int parameter) // parameter = 0 (Vertical) 
    {
        if (color == "green" && parameter == 1 || color == "red" && parameter == 0)
        {
            if(parameter==1)
                cout << "Traffic lights: 'For horizontal cars is green lighter, but for vertiacal cars is red'"<<endl;
            else 
                cout << "Traffic lights: 'For vertiacal cars is red lighter, but for horizontal cars is green'" << endl;
            car2->run();
            car1->stop();
           
        }
        else if (color == "green" && parameter == 0 || color == "red" && parameter == 1)
        {
            if (parameter == 0)
                cout << "Traffic lights: 'For vertiacal cars is green lighter, but for horizontal cars is red'" << endl;
            else
                cout << "Traffic lights: 'For horizontall cars is red lighter, but for vertiaca cars is green'" << endl;
            car1->run();
            car2->stop();
        }
    }
};

#endif // !Header
