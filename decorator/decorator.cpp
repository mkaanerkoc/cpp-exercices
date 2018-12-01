/* 	
	author : mkerkoc 
	date : 18.11.18
	title : implementation of decarator design pattern in cpp
*/

#include <iostream>
#include <string>

using namespace std;

/* abstract base class for coffee */
class Coffee{
public:
	Coffee()
	{

	}
	virtual ~Coffee()
	{

	}
	virtual int getCost()
	{
		return cost;
	}
	virtual string getName()
	{
		return name;
	}
protected:
	int cost;
	string name;
};


class Espresso : public Coffee{
public:
	Espresso()
	{
		cost = 20;
		name = "Espresso";
	}
};

class Mocha : public Coffee{
public:
	Mocha()
	{
		cost = 30;
		name = "Mocha";
	}
};

class Condiment : public Coffee{
public:
	Condiment( Coffee* coffeeParam )
	{
		coffee = coffeeParam;
	}
	int getCost() override
	{
		return coffee->getCost();
	}
	string getName() override
	{
		return coffee->getName();
	}
private:
	Coffee *coffee; // composition node
};

class SugarCondiment : public Condiment{
public:
	SugarCondiment( Coffee* coffeeParam )
	: Condiment( coffeeParam )
	{
		cost = 3;
		name = "Sugar";
	}
	int getCost() override
	{
		return cost + Condiment::getCost();
	}
	string getName() override
	{
		return Condiment::getName() + " with "+ name;
	}
};

class MilkCondiment : public Condiment{
public:
	MilkCondiment( Coffee* coffeeParam )
	: Condiment( coffeeParam )
	{
		cost = 4;
		name = "Milk";
	}
	int getCost() override
	{
		return cost + Condiment::getCost();
	}
	string getName() override
	{
		return Condiment::getName() + " with "+ name;
	}
};

class ExtraShotCondiment : public Condiment{
public:
	ExtraShotCondiment( Coffee* coffeeParam )
	: Condiment( coffeeParam )
	{
		cost = 6;
		name = "ExtraShot";
	}
	int getCost() override
	{
		return cost + Condiment::getCost();
	}
	string getName() override
	{
		return Condiment::getName() + " with "+ name;
	}
};


int main(void)
{
	cout<<"Hello world from Decorator example ! "<<endl;
	Coffee *myCoffee = new Espresso();
	cout<<"Price of the "<<myCoffee->getName()<<" is "<<myCoffee->getCost()<<endl;

	myCoffee = new ExtraShotCondiment(myCoffee);
	cout<<"Price of the "<<myCoffee->getName()<<" is "<<myCoffee->getCost()<<endl;


	myCoffee = new MilkCondiment(myCoffee);
	cout<<"Price of the "<<myCoffee->getName()<<" is "<<myCoffee->getCost()<<endl;

	return 0;
}