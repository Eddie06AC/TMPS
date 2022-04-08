#include"Header.h"
#include<iostream>

using namespace std;

int main() 
{
	Socket* USA = new Socket(120, 50);

	USA_Smartphone* a = new USA_Smartphone();
	cout << "Smartphone USA is connected to USA socket" << endl;
	a->USA_charging(USA);
	EU_Tablet* b = new EU_Tablet();	
	cout << "Tablet EU is connected to USA socket with simple unprotected adapter" << endl;
	b->EU_charging(USA);

		
	USA_Device* aaa = new Adapter_EU_TO_USA(b);
	cout << "Now let's check with good professional adapter.\nTablet EU is connected to USA socket with protected adapter" << endl;
	aaa->USA_charging(USA);
	

	return 0;
}