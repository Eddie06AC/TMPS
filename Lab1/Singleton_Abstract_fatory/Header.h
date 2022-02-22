#pragma once
#ifndef Header_h_h
#define Header_h_h
#include<iostream>

using namespace std;

class Reshenie
{
public:
	virtual void addition() = 0;
	virtual void subtraction() = 0;
	virtual void multiplication() = 0;
	virtual void division() = 0;
};

class Only_Int :public Reshenie
{
public:
	virtual void addition();
	virtual void subtraction();
	virtual void multiplication();
	virtual void division();
};

class Int_Float_Numbres :public Reshenie
{
public:
	virtual void addition();
	virtual void subtraction();
	virtual void multiplication();
	virtual void division();
};

class factory 
{
public:
	virtual Reshenie* create_reshenie()=0;
};

class factory_Int :public factory
{
	virtual Reshenie* create_reshenie();
};

class factory_Int_Float :public factory 
{
	virtual Reshenie* create_reshenie();
};

class Calculator
{
private:
	static Calculator* instance;
	Calculator();
	~Calculator();
	Reshenie* interface_reshenia;
public:
	static Calculator* get_instance();
	void addition();
	void subtraction();
	void multiplication();
	void division();
};


#endif // Header_h_h
