#ifndef HEADER
#define HEADER
#include<iostream>
#include<unordered_map>

using namespace std;

class Warrior
{
private:
	int hp;
	int damage;

public:
	Warrior(int hp, int damage);
	int get_hp() const;
	int get_damage() const;
};

class WarriorsType
{
private:
	string name;
	string weapon;
	string armor;

public:
	WarriorsType(string name, string weapon, string armor);
	string get_name() const;
	string get_weapon() const;
	string get_armor() const;
	void Information(const Warrior& warrior) const;
};

class WarriorFactory
{
private:
	unordered_map<string, WarriorsType> flyweights_;
	string GetKey(const WarriorsType& ss) const;

public:
	WarriorFactory(std::initializer_list<WarriorsType> warriors_type);

	WarriorsType GetFlyweight(const WarriorsType& warriors_type);

	void ListFlyweights() const;
};

void AddWarriorToBarracks(
	WarriorFactory& ff, const int damage, const int hp, const string& name, const string& weapon, const  string& armor);



////////////////////////////////////////////////////////////////////////////


class Army 
{
public:
	virtual void get_name()=0;
	virtual int get_count()=0;
	virtual int get_hp()=0;
	virtual int get_damage()=0;
};

class Infantryman : public Army
{
private:
	int count;
	int hp;
	int damage;
public:
	Infantryman(int count, int hp, int damage);
	void get_name();
	int get_count();
	int get_hp();
	int get_damage();
};

class Archer : public Army
{
private:
	int count;
	int hp;
	int damage;
public:
	Archer(int count, int hp, int damage);	
	void get_name();
	int get_count();
	int get_hp();
	int get_damage();
};

class Spearman : public Army
{
private:
	int count;
	int hp;
	int damage;
public:
	Spearman(int count, int hp, int damage);
	void get_name();
	int get_count();
	int get_hp();
	int get_damage();
};

class Cavalry : public Army
{
private:
	int count;
	int hp;
	int damage;
	int type;
public:
	Cavalry(int n, int count, int hp, int damage);
	void get_name();
	int get_count();
	int get_hp();
	int get_damage();
};

class Squad : public Army
{
private:
	list<Army*> unit;
public:
	void get_name();
	void Add_To_Squad(Army* squad);
	void remove(Army* squad);
	void fight(Squad* other);
	int get_count();
	int get_hp();
	int get_damage();
};


#endif // !HEADER
