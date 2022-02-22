#ifndef Header_h_h
#define Header_h_h
#include<iostream>

using namespace std;

class calculator 
{
private:
	static calculator* instance;
	calculator();
	~calculator();
public:
	static calculator* get_instance();
	void addition();
	void subtraction();
	void multiplication();
	void division();
	
};


#endif // Header_h_h
