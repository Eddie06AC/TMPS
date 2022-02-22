#include"Header.h"
#include<iostream>


using namespace std;

int main()
{
    int flagg[2] = {1,15};
    ObjectPool* admin = ObjectPool::getInstance();
   
    Ñash_register* a = new Ñash_register("first",4);
    Ñash_register* b = new Ñash_register("second",3);
    Ñash_register* c = new Ñash_register("third",5);

    while (flagg[0]==1)
    {
        a = admin->getÑash_register(a);
        cout << a << endl;
        admin->handler_queue(a, flagg[1], flagg);
       // cout << flagg[0] << endl << flagg[1] << endl;
        if (flagg[0] == 1)
        {
            b = admin->getÑash_register(b);
            cout << b << endl;
            admin->handler_queue(b, flagg[1], flagg);
           // cout << flagg[0] << endl << flagg[1] << endl;
            if (flagg[0] == 1)
            {
                c = admin->getÑash_register(c);
                cout << c << endl;
                admin->handler_queue(c, flagg[1], flagg);
               // cout << flagg[0] << endl << flagg[1] << endl;
            }
        }
        admin->returnÑash_register(a);
        admin->returnÑash_register(b);
        admin->returnÑash_register(c);
    }
    cout << "Queue is finished;" << endl;


   

   /* a= admin->getÑash_register(a); 
    cout << "first= " << a->getmax_people()<< a <<endl;
    b = admin->getÑash_register(b);
    cout << "second= " << b->getmax_people() << endl;
    c = admin->getÑash_register(c);
    cout << "third= " << c->getmax_people() << endl;
    admin->returnÑash_register(a);
    admin->returnÑash_register(b);
    admin->returnÑash_register(c);
    a = admin->getÑash_register(a);
    cout << "first= " << a->getmax_people()<< a << endl;*/


    //a = admin-> getÑash_register(a);
    //a->setmax_people(10);
    //std::cout << "one = " << a->getmax_people()<< " [" << a << "]" << std::endl;
    //b = admin->getÑash_register(b);
    //b->setmax_people(20);
    //std::cout << "two = " << b->getmax_people() << " [" << b << "]" << std::endl;
    //admin->returnÑash_register(a);
    //admin->returnÑash_register(b);
    ///* Resources will be reused.
    // * Notice that the value of both resources were reset back to zero.
    // */
    //a = admin->getÑash_register(a);
    //std::cout << "one = " << a->getmax_people() << " [" << a << "]" << std::endl;
    //b = admin->getÑash_register(b);
    //std::cout << "two = " << b->getmax_people() << " [" << b << "]" << std::endl;


    return 0;
}