#include"Header.h"
#include<iostream>


using namespace std;

int main()
{
    EventGenerator* gen = new EventGenerator();
    UP_DOWN_price* event_price = new UP_DOWN_price();
    gen->addEvent(event_price);
    float rate = 0.f;
    srand(time(NULL));

    Cash* cash = new Cash();
    Credit_card* card = new Credit_card(cash);

    Client* client1 = new Client(1500, cash, 1);
    Client* client2 = new Client(200, card, 1);
    Client* client3 = new Client(500, card, 0);
    Client* client4 = new Client(1500, card, 1);
    Client* client5 = new Client(50, cash, 0);
    Client* client6 = new Client(200, card, 0);
    Client* client7 = new Client(100, cash, 1);
    Client* client8 = new Client(1800, cash, 1);
    Client* client9 = new Client(300, cash, 0);

    int const length = 10;
    Client* mas[length];

    for (int i = 0; i < length; i++)
    {
        mas[i] = 0;

    }
    client1->add(mas);
    client2->add(mas);
    client3->add(mas);
    client4->add(mas);
    client5->add(mas);
    client6->add(mas);
    client7->add(mas);
    client8->add(mas);
    client9->add(mas);


    int flagg[3] = { 1,0,0 };
    // first: 1 - if exists queue 
    // second: number of remaining people
    // third: number of person who need to be handled
    ObjectPool* admin = ObjectPool::getInstance();

    Ñash_register* a = new Ñash_register_Simple("first", 2);
    Ñash_register* a2 = new Ñash_register_Simple();
    Ñash_register* b = new Ñash_register_Simple("second", 1);
    Ñash_register* c = new Ñash_register_Simple("third", 2);

    Ñash_register* apas = (Ñash_register*) new Ñash_register_Bonus_card(a);
    Ñash_register* bpas = (Ñash_register*) new Ñash_register_Bonus_card(b);
    Ñash_register* cpas = (Ñash_register*) new Ñash_register_Bonus_card(c);

    int event_count = 0;
    int handl1 = 0;

    /// 
    /// 
    Handle_clients* handleee = new Handle_clients();
    Recalculation* handleee1 = new Recalculation();



    while (flagg[0] == 1)
    {
        if (event_count == 0)
        {
            rate += gen->generate(1);
            event_count++;
        }
        apas = admin->getÑash_register(apas);
        cout << apas << " - " << apas->getname() << endl;
        handl1++;
        if (handl1 == 2)
        {
            handleee1->set_pool(admin);
            handleee1->do_Business(apas, mas, length, flagg, rate);
        }
        else
        {
            handleee->set_pool(admin);
            handleee->do_Business(apas, mas, length, flagg, rate);
        }
        if (flagg[0] == 1)
        {
            bpas = admin->getÑash_register(bpas);
            cout << bpas << " - " << bpas->getname() << endl;
            handleee->set_pool(admin);
            handleee->do_Business(bpas, mas, length, flagg, rate);
            if (flagg[0] == 1)
            {
                if (event_count == 1)
                {
                    rate += gen->generate(0);
                    event_count++;
                }
                cpas = admin->getÑash_register(cpas);
                cout << cpas << " - " << cpas->getname() <<endl;
                handleee->set_pool(admin);
                handleee->do_Business(cpas, mas, length, flagg, rate);
            }
        }
        admin->returnÑash_register(apas);
        admin->returnÑash_register(bpas);
        admin->returnÑash_register(cpas);
    }

    cout << "Queue is finished;\n" << endl;

    apas->Get_stats();
    cout << endl;
    bpas->Get_stats();
    cout << endl;
    cpas->Get_stats();
    cout << endl;

    return 0;
}