#include <iostream>
#include <memory>
#include <vector>


using namespace std;

void illustrationOfMoveSemantics();

class Shape{
public:
	Shape()
	{

	}

	Shape( int verticesCount )
	: vertices ( new int(verticesCount))
	{
	
	}

	Shape( const Shape& param )
	{
		cout<<"Copy constructor of shape "<<endl;
		if( param.vertices != nullptr )
		{
			vertices = new int( *param.vertices); // expensive heap allocation
		}
	}

	Shape( Shape&& param )
	{
		cout<<"move constructor of shape"<<endl;
		if( param.vertices != nullptr )
		{
			vertices = param.vertices; // just swap the ptr's ! no expensive heap allocation
			param.vertices = nullptr;
		}
	}

	Shape& operator=(const Shape& param )
	{
		cout<<"Assignment operator of shape"<<endl;
		if( param.vertices != nullptr )
		{
			vertices = new int( *param.vertices); // expensive heap allocation
		}
		return *this;
	}

	Shape& operator=( Shape&& param ) // && says that is rvalue reference
 	{
		cout<<"move assignment operator of shape"<<endl;
		if( param.vertices != nullptr )
		{
			vertices = param.vertices; // just swap the ptr's ! no expensive heap allocation
			param.vertices = nullptr;
		}
		return *this;
	}

	virtual	~Shape()
	{
		if( vertices != nullptr )
		{
			delete vertices;
			vertices = nullptr;
			cout<<"dtor of shape is called"<<endl;
		}
	}
private:
	int* vertices;
};



int main(void){

	
	illustrationOfMoveSemantics();
	Shape s1; // conversion ctor
	{
		Shape s2 = s1;
		Shape s3 = 10;
		s3 = move(s2); // xvalue
		Shape s4(move(s3)); // prvalue
	}
	return 0;
}


void illustrationOfMoveSemantics(){
	vector<int> myVector{1,2,4,5,123};
	cout<<"Hello world from move semantics example "<<endl;
	cout<<"Size of first vector before move operation: "<< myVector.size()<<endl;
	auto secondVector = move(myVector);
	cout<<"Size of first vector after move operation: "<< myVector.size()<<endl;
	// But how it can invalidate the stack memory?
	cout<<"Size of the second vector after move operation : "<< secondVector.size()<<endl;

}