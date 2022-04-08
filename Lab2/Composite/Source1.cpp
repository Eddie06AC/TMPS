#include"Header.h"
#include<iostream>

using namespace std;

Warrior::Warrior(int hp, int damage)
{
	this->hp = hp;
	this->damage = damage;
}

int Warrior::get_hp() const { return this->hp; }

int Warrior::get_damage() const { return this->damage; }


WarriorsType::WarriorsType(string name, string weapon, string armor)
{
	this->name = name;
	this->weapon = weapon;
	this->armor = armor;
}

string WarriorsType::get_name() const { return this->name; }

string WarriorsType::get_weapon() const { return this->weapon; }

string WarriorsType::get_armor() const { return this->armor; }

void WarriorsType::Information(const Warrior& warrior) const
{
	cout << "Name = " << this->get_name() << endl;
	cout << "Weapon = " << this->get_weapon() << endl;
	cout << "Armor = " << this->get_armor() << endl;
	cout << "Hp = " << warrior.get_hp() << endl;
	cout << "Damage = " << warrior.get_damage() << endl;
}

string WarriorFactory::GetKey(const WarriorsType& ss) const
{
	return ss.get_name() + " armed with " + ss.get_weapon() + " dressed in " + ss.get_armor();
}

WarriorFactory::WarriorFactory(std::initializer_list<WarriorsType> warriors_type)
{
	for (const WarriorsType& ss : warriors_type)
	{
		this->flyweights_.insert(std::make_pair<std::string, WarriorsType>(this->GetKey(ss), WarriorsType(ss)));
	}
}

WarriorsType WarriorFactory::GetFlyweight(const WarriorsType& warriors_type)
{
	std::string key = this->GetKey(warriors_type);
	if (this->flyweights_.find(key) == this->flyweights_.end())
	{
		cout << "Barracks(FlyweightFactory): Can't find a flyweight, creating new one.\n";
		this->flyweights_.insert(std::make_pair(key, WarriorsType(warriors_type)));
	}
	else
	{
		cout << "Barracks(FlyweightFactory): Reusing existing flyweight.\n";
	}
	return this->flyweights_.at(key);
}

void WarriorFactory::ListFlyweights() const
{
	size_t count = this->flyweights_.size();
	cout << "\nBarracks has " << count << " types of warriors:\n";
	int c = 0;
	for (std::pair<std::string, WarriorsType> pair : this->flyweights_)
	{
		c++;
		cout << " " << c << ") " << pair.first << "\n";
	}
}

void AddWarriorToBarracks(
	WarriorFactory& ff, const int damage, const int hp, const string& name, const string& weapon, const  string& armor)
{
	cout << "\nNext warrior added to the total number of armed forces of our land.\n";
	const WarriorsType& flyweight = ff.GetFlyweight({ name, weapon, armor });
	flyweight.Information(Warrior(hp, damage));
}

////////////////////////////////////////////////////////////////////////////


Infantryman::Infantryman(int count, int hp, int damage)
{
	this->count = count;
	this->hp = hp;
	this->damage = damage;
}

void Infantryman::get_name() { cout << "Infantryman" << endl; };

int Infantryman::get_count() { return this->count; };

int Infantryman::get_hp() { return this->hp * this->count; };

int Infantryman::get_damage() { return this->damage * this->count; };

Archer::Archer(int count, int hp, int damage)
{
	this->count = count;
	this->hp = hp;
	this->damage = damage;
}

void Archer::get_name() { cout << "Archer" << endl; };

int Archer::get_count() { return this->count; };

int Archer::get_hp() { return this->hp * this->count; };

int Archer::get_damage() { return this->damage * this->count; };

Spearman::Spearman(int count, int hp, int damage)
{
	this->count = count;
	this->hp = hp;
	this->damage = damage;
}

void Spearman::get_name() { cout << "Spearman" << endl; };

int Spearman::get_count() { return this->count; };

int Spearman::get_hp() { return this->hp * this->count; };

int Spearman::get_damage() { return this->damage * this->count; };

Cavalry::Cavalry(int n, int count, int hp, int damage)
{
	switch (n)
	{
	case 1: this->type = 1;
		this->count = count;
		this->hp = hp;
		this->damage = damage; break;
	case 2: this->type = 2;  this->count = count;
		this->hp = hp;
		this->damage = damage; break;
	case 3: this->type = 3;  this->count = count;
		this->hp = hp;
		this->damage = damage; break;
	}
}

void Cavalry::get_name() 
{
	switch (this->type)
	{
	case 1: cout << "Cavalry with sword" << endl; break;
	case 2: cout << "Cavalry with spear" << endl; break;
	case 3: cout << "Cavalry with bow" << endl; break;
	}
}

int Cavalry::get_count() { return this->count; };

int Cavalry::get_hp() { return this->hp * this->count; };

int Cavalry::get_damage() { return this->damage * this->count; };

void Squad::get_name() 
{
	for (list<Army*>::iterator squad = unit.begin(); squad != unit.end(); ++squad) {
		(*squad)->get_name();
	}
}

void Squad::Add_To_Squad(Army* squad)
{
	unit.push_back(squad);
}

void Squad::remove(Army* squad)
{
	unit.remove(squad);
}

void Squad::fight(Squad* other) 
{
	int hp_army = 0, damage_army = 0;
	for (list<Army*>::iterator squad = unit.begin(); squad != unit.end(); ++squad) {
		int hp_squad = (*squad)->get_hp();
		int damage_squad = (*squad)->get_damage();
		hp_army += hp_squad;
		damage_army += damage_squad;
	}
	cout << "Hp of first army = " << hp_army << endl;
	cout << "Damage of first army  = " << damage_army << endl;


	int hp_army2 = 0, damage_army2 = 0;
	for (list<Army*>::iterator squad = other->unit.begin(); squad != other->unit.end(); ++squad) {
		int hp_squad2 = (*squad)->get_hp();
		int damage_squad2 = (*squad)->get_damage();
		hp_army2 += hp_squad2;
		damage_army2 += damage_squad2;
	}
	cout << "-----------------------------------------" << endl;
	cout << "Hp of second army = " << hp_army2 << endl;
	cout << "Damage of second army = " << damage_army2 << endl;
	cout << "-----------------------------------------" << endl;
	int tmp_army1, tmp_army2;
	tmp_army1 = hp_army - damage_army2;
	tmp_army2 = hp_army2 - damage_army;
	if (tmp_army1 < 0 && tmp_army2 < 0)
		cout << "No one survived" << endl;
	else if (tmp_army1 > tmp_army2)
	{
		if (tmp_army2 < 0)
			cout << "Victory went to the first army!\nThe enemy is defeated" << endl;
		else
			cout << "Victory went to the first army!\nCongratulation!!! The enemy is captured" << endl;
	}
	else
	{
		if (tmp_army1 < 0)
			cout << "Victory went to the second army!\nThe enemy is defeated" << endl;
		else
			cout << "Victory went to the second army!\nCongratulation!!! The enemy is captured" << endl;
	}
}

int Squad::get_count() 
{
	int sum = 0;
	for (list<Army*>::iterator squad = unit.begin(); squad != unit.end(); ++squad) {
		sum += (*squad)->get_count();
	}
	return sum;
}

int Squad::get_hp()
{
	int sum = 0;
	for (list<Army*>::iterator squad = unit.begin(); squad != unit.end(); ++squad) {
		sum += (*squad)->get_hp();
	}
	return sum;
}

int Squad::get_damage() 
{
	int sum = 0;
	for (list<Army*>::iterator squad = unit.begin(); squad != unit.end(); ++squad) {
		sum += (*squad)->get_damage();
	}
	return sum;
}