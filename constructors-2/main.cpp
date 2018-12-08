#include <iostream>
#include <utility>
#include <memory>

using namespace std;


class MyResource {
public:
	MyResource()
	: holder(new int[100]), capacity(100)
	{
		holder[0] = 100;
		cout << "MyResource default ctor" << endl;
	}
	MyResource(int param)
	: holder(new int[param]), capacity(param)
	{
		holder[0] = capacity;
		cout << "MyResource modified ctor" << endl;
	}

	int getCapacity() {
		return capacity;
	}

	~MyResource() {
		cout << "MyResource dtor" << endl;
		if (holder != nullptr) {
			delete[] holder;
			holder = nullptr;
		}
	}

private:
	int* holder;
	int capacity;
};

class MyClass{
	public:
		MyClass()
		: ptr(new MyResource()), value(0)
		{

		}

		MyClass(int capacityParam, int valueParam)
		: ptr(new MyResource(capacityParam)), value( valueParam )
		{
			
		}

		MyClass( const MyClass& param ){ // copy constructor
			ptr = unique_ptr<MyResource>(new MyResource(param.getResourceCapacity()));
			value = param.getValue();
		}
		MyClass& operator=( const MyClass& param ){ // copy assignment operator
			ptr = unique_ptr<MyResource>(new MyResource(param.getResourceCapacity()));
			value = param.getValue();
		}
		~MyClass(){

		}
		
		void printValues(){
			//cout<< "Ptr : "<< static_cast<int>(*ptr) <<" Value : "<< value << endl;
		}
		void setPtr( MyResource param ){
			*ptr = param;
		}
		MyResource getResource() const{
			return *ptr;
		}

		int getResourceCapacity() const{
			return ptr->getCapacity();
		}

		int getValue() const{
			return value;
		}
		void printOwnerCount(){
			//cout<<"User Count : "<<ptr.use_count()<<endl;
		}
		int getPtrOwnerCount(){
			//return ptr.use_count();
			return 0;
		}
	private:
		unique_ptr<MyResource> ptr;
		int value;
};

class TwoDPoint{
	public:
		TwoDPoint()
		: x( 0 ), y( 0 )
		{
			cout<<"Default Constructor of 2DPoint["<<x<<","<<y<<"]"<<endl;
		}
		TwoDPoint( int xParam , int yParam )
		: x( xParam), y( yParam )
		{
			cout<<"Modified Constructor of 2DPoint["<<x<<","<<y<<"]"<<endl;
		}
		TwoDPoint( const TwoDPoint& param )
		{

			x = param.x;
			y = param.y;
			cout<<"Copy constructor of 2DPoint ["<<x<<","<<y<<"]"<<endl;
		}
		TwoDPoint& operator=(const TwoDPoint& param )
		{
			x = param.x;
			y = param.y;
			cout<<"Copy assignment operator of 2DPoint ["<<x<<","<<y<<"]"<<endl;
		}
		TwoDPoint( TwoDPoint&& param )
		{
			x = param.x;
			y = param.y;
			cout<<"Move constructor of 2DPoint ["<<x<<","<<y<<"]"<<endl;
		}
		TwoDPoint operator+( const TwoDPoint& param )
		{
			TwoDPoint temp( x + param.x, y + param.y );
			return move(temp);
		}
		~TwoDPoint()
		{
			cout<<"Destructor of 2DPoint ["<<x<<","<<y<<"]"<<endl;
		}
	private:
		int x,y;
};




int main(void)
{
	cout<<"Hello world from another constructor example yeeey!"<<endl;
	TwoDPoint tw6( 10, 20 );
	{
		TwoDPoint tw(2,3);
		TwoDPoint tw2(tw);
		TwoDPoint tw3 = tw + tw2;
		TwoDPoint tw4 = move( tw6 );
	}
	MyClass mc1( 30,60);
	mc1.printOwnerCount();
	//MyClass mc2 ( 40 ,90 );
	{
		MyClass mc2 = mc1;
		MyClass mc3;
		mc3 = mc1;
		mc1.printValues();
		mc2.printValues();
		mc1.printOwnerCount();

		mc2.setPtr( 20 );
		mc3.setPtr( 150 );
		mc2.printValues();
		mc3.printValues();
		mc3 = mc1;
		mc3.printValues();
		MyResource myResource;
	}
	mc1.printValues();
	mc1.printOwnerCount();


	return 0;
}