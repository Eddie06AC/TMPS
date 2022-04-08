#include"Header.h"
#include<iostream>

using namespace std;

int main()
{

    WarriorFactory* factory = new WarriorFactory({ {"Infantryman", "Sword", "heavyweight"},
                                                   {"Archer", "Bow", "lightweight"},
                                                   {"Spearman", "Spear", "average weight"},
                                                   {"Cavalry", "Spear", "average weight"},
                                                   {"Cavalry", "Sword", "average weight"} });
    factory->ListFlyweights();

    AddWarriorToBarracks(*factory, 80, 70, "Infantryman", "Sword", "heavyweight");

    AddWarriorToBarracks(*factory, 75, 50, "Infantryman", "Sword", "heavyweight");

    AddWarriorToBarracks(*factory, 100, 96, "Archer", "Bow", "lightweight");

    AddWarriorToBarracks(*factory, 50, 100, "Cavalry", "Bow", "lightweight");

    factory->ListFlyweights();
    
    delete factory;  

    Infantryman* infartryman = new Infantryman(20,20,50);  // hp = 100 --> второй случай 
    Archer* archer = new Archer(10,50,100);
    Spearman* spearman = new Spearman(15,75,75);
    Cavalry* cavalry_sword = new Cavalry(1,20,100,50);
    Cavalry* cavalry_spear = new Cavalry(2,10,75,75);
    Cavalry* cavalry_bow = new Cavalry(3,15,50,100);

    Squad* army = new Squad();
    Squad* Close_damage = new Squad();
    Squad* Distant_damage = new Squad();
    Squad* Cavalry_squad_close = new Squad();
    Squad* Cavalry_squad_distant = new Squad();

    army->Add_To_Squad(Close_damage);
    army->Add_To_Squad(Distant_damage);
    Close_damage->Add_To_Squad(infartryman);
    Close_damage->Add_To_Squad(spearman);
    Close_damage->Add_To_Squad(Cavalry_squad_close);
    Cavalry_squad_close->Add_To_Squad(cavalry_sword);
    Cavalry_squad_close->Add_To_Squad(cavalry_spear);
    Distant_damage->Add_To_Squad(archer);
    Distant_damage->Add_To_Squad(Cavalry_squad_distant);
    Cavalry_squad_distant->Add_To_Squad(cavalry_bow);

    cout << "Army ---------->"<<endl;
    army->get_name();

    cout << "//////////////////////////////////////////////" << endl;
    
    cout << "Close damage ---------->" << endl;
    Close_damage->get_name();

    cout << "//////////////////////////////////////////////" << endl;

    cout << "Cavalry squad close ---------->" << endl;
    Cavalry_squad_close->get_name();

    cout << "//////////////////////////////////////////////" << endl;
    
    cout << "Distant damage ---------->" << endl;
    Distant_damage->get_name();

    cout << "//////////////////////////////////////////////" << endl;
    
    cout << "Cavalry squad distant ---------->" << endl;
    Cavalry_squad_distant->get_name();
    
    cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;


    Infantryman* infartryman2 = new Infantryman(40, 50, 50);  // hp = 100 && сверху поменять --> третий случай 
    Archer* archer2 = new Archer(30, 50, 100);
    Cavalry* cavalry_sword2 = new Cavalry(1, 20, 100, 50);

    Squad* army2 = new Squad();
    Squad* Close_damage2 = new Squad();
    Squad* Distant_damage2 = new Squad();

    army2->Add_To_Squad(Close_damage2);
    army2->Add_To_Squad(Distant_damage2);
    Close_damage2->Add_To_Squad(infartryman2);
    Close_damage2->Add_To_Squad(cavalry_sword2);
    Distant_damage2->Add_To_Squad(archer2);


    army->fight(army2);

    // Необходимо добавить нормаьную печать элементов
    // Необходимо придумать логику
    return 0;
}
