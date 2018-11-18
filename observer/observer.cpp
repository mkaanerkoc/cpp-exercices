#include <iostream>
#include <vector>

using namespace std;


class Observer{
public:
	virtual void update( float valueParam ) = 0;
	virtual void display() = 0;
};

class Subject{
public:
	virtual void registerObserver( Observer* param  ) = 0;
	virtual void notify() = 0;
protected:
	vector<Observer*> observers;
};

class RoomTemperature : public Subject{
public: 
	void setTemperature( float param )
	{
		temperatureValue = param;
		notify();
	}
	void registerObserver( Observer* param ) override {
		observers.push_back( param );
	}
private:
	void notify() override {
		for (int i = 0; i < observers.size(); i++)
		{
			observers[i]->update( temperatureValue );
		}
	}

	float temperatureValue;
};


class LCDDisplay : public Observer{
public:
	void update( float valueParam ) override {
		cout << "LCD Display : value is : "<<valueParam<<endl;
	}
	
	void display() override {

	}
};

class RemoteDisplay : public Observer{
public:
	void update( float valueParam ) override {
		cout << "RemoteDisplay : value is : "<<valueParam<<endl;
	}
	
	void display() override {

	}
};

class MonolithicDisplay : public Observer{
public:
	void update( float valueParam ) override {
		cout << "MonolithicDisplay : value is : "<<valueParam<<endl;
	}
	
	void display() override {

	}
};

int main( void ){
	cout<<"Hello world from Observer exercise !"<<endl;
	
	RoomTemperature *rt = new RoomTemperature();
	rt->registerObserver( new MonolithicDisplay() );
	rt->registerObserver( new LCDDisplay() );

	rt->setTemperature( 32 );
	return 0;
}