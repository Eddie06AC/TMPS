#include"Header.h"
#include<iostream>


using namespace std;

int main()
{
    Cash* cash = new Cash();
    Credit_card* card = new Credit_card(cash);

    Client* client1 = new Client(1500, cash,1);
    Client* client2 = new Client(200, card,1);
    Client* client3 = new Client(500, card,0);
    Client* client4 = new Client(1500, card,1);
    Client* client5 = new Client(50, cash,0);
    Client* client6 = new Client(200, card,0);
    Client* client7 = new Client(100, cash,1);
    Client* client8 = new Client(1800, cash,1);
    Client* client9 = new Client(300, cash,0);
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

    �ash_register* a = new �ash_register_Simple("first", 5);
    �ash_register* a2 = new �ash_register_Simple();
    �ash_register* b = new �ash_register_Simple("second", 1);
    �ash_register* c = new �ash_register_Simple("third", 2);

    �ash_register* apas = (�ash_register*) new �ash_register_Bonus_card(a);
    �ash_register* bpas = (�ash_register*) new �ash_register_Bonus_card(b);
    �ash_register* cpas = (�ash_register*) new �ash_register_Bonus_card(c);
    

    while (flagg[0] == 1)
    {
        apas = admin->get�ash_register(apas);
        cout << apas << endl;
        admin->handler(apas, mas, length, flagg);
        // cout << flagg[0] << endl << flagg[1] << endl;
        if (flagg[0] == 1)
        {
            bpas = admin->get�ash_register(bpas);
            cout << bpas << endl;
            admin->handler(bpas, mas, length, flagg);
            // cout << flagg[0] << endl << flagg[1] << endl;
            if (flagg[0] == 1)
            {
                cpas = admin->get�ash_register(cpas);
                cout << cpas << endl;
                admin->handler(cpas, mas, length, flagg);
                // cout << flagg[0] << endl << flagg[1] << endl;
            }
        }
        admin->return�ash_register(apas);
        admin->return�ash_register(bpas);
        admin->return�ash_register(cpas);
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