#include"Header.h"
#include<iostream>


using namespace std;

int main()
{
    int flagg[2] = {1,15};
    ObjectPool* admin = ObjectPool::getInstance();
   
    �ash_register* a = new �ash_register("first",4);
    �ash_register* b = new �ash_register("second",3);
    �ash_register* c = new �ash_register("third",5);

    while (flagg[0]==1)
    {
        a = admin->get�ash_register(a);
        cout << a << endl;
        admin->handler_queue(a, flagg[1], flagg);
       // cout << flagg[0] << endl << flagg[1] << endl;
        if (flagg[0] == 1)
        {
            b = admin->get�ash_register(b);
            cout << b << endl;
            admin->handler_queue(b, flagg[1], flagg);
           // cout << flagg[0] << endl << flagg[1] << endl;
            if (flagg[0] == 1)
            {
                c = admin->get�ash_register(c);
                cout << c << endl;
                admin->handler_queue(c, flagg[1], flagg);
               // cout << flagg[0] << endl << flagg[1] << endl;
            }
        }
        admin->return�ash_register(a);
        admin->return�ash_register(b);
        admin->return�ash_register(c);
    }
    cout << "Queue is finished;" << endl;


   

   /* a= admin->get�ash_register(a); 
    cout << "first= " << a->getmax_people()<< a <<endl;
    b = admin->get�ash_register(b);
    cout << "second= " << b->getmax_people() << endl;
    c = admin->get�ash_register(c);
    cout << "third= " << c->getmax_people() << endl;
    admin->return�ash_register(a);
    admin->return�ash_register(b);
    admin->return�ash_register(c);
    a = admin->get�ash_register(a);
    cout << "first= " << a->getmax_people()<< a << endl;*/


    //a = admin-> get�ash_register(a);
    //a->setmax_people(10);
    //std::cout << "one = " << a->getmax_people()<< " [" << a << "]" << std::endl;
    //b = admin->get�ash_register(b);
    //b->setmax_people(20);
    //std::cout << "two = " << b->getmax_people() << " [" << b << "]" << std::endl;
    //admin->return�ash_register(a);
    //admin->return�ash_register(b);
    ///* Resources will be reused.
    // * Notice that the value of both resources were reset back to zero.
    // */
    //a = admin->get�ash_register(a);
    //std::cout << "one = " << a->getmax_people() << " [" << a << "]" << std::endl;
    //b = admin->get�ash_register(b);
    //std::cout << "two = " << b->getmax_people() << " [" << b << "]" << std::endl;


    return 0;
}