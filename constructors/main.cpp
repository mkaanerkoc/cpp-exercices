#include <iostream>
#include <vector>
#include <memory>

//#define ENABLE_DTOR_LINE 
using namespace std;


class Student{
	public:
		Student()
		: StudentId ( 0 )
		{
			cout<<"default Ctor of Student is called"<<endl;
		}
		~Student()
		{
			#ifdef ENABLE_DTOR_LINE
				cout<<"default Dtor of Student is called"<<endl;
			#endif
		}
		Student( const Student& param )
		{
			cout<<"copy constructor of Student is called"<<endl;
		}

		void setStudentId( int idParam ){
			StudentId = idParam;
		}

		int StudentId;
};

class Manager{
	public:
		Manager()
		: managerId( 0 )
		{
			cout<<"default Ctor of manager is called"<<endl;
		}
		~Manager()
		{
			#ifdef ENABLE_DTOR_LINE
				cout<<"default Dtor of manager is called"<<endl;
			#endif
		}
		Manager( const Manager& param )
		{
			cout<<"copy ctor of manager is called"<<endl;
		}

		Manager& operator = (const Manager &t)
		{
			cout<<"assignment operator of manager is called "<<endl;
		}
		Manager( Manager&& param )
		{
			cout<<"move constructor of manager is called"<<endl;
		}

		void setManagerId( int idParam ){
			managerId = idParam;
		}

		int managerId;
};

class Library{
	public:
		Library()
		{
			cout<<"default Ctor of library is called"<<endl;
		}
		~Library()
		{
			#ifdef ENABLE_DTOR_LINE
				cout<<"default Dtor of library is called"<<endl;
			#endif
		}
		void setManager( Manager managerParam )
		{	
			_manager = managerParam;
		}
		Manager getManager()
		{
			return _manager;
		}

	private:
		Manager _manager;
		Student _student;
};

class LibraryItem{
	public:
		LibraryItem()
		: type(0), price(10)
		{
			cout<<"default Ctor of library item is called"<<endl;
		}

		LibraryItem( int typeParam, int priceParam )
		: type( typeParam ), price( priceParam )
		{
			cout<<"second Ctor of library item is called"<<endl;
		}

		void setPrice( int priceParam )
		{
			price = priceParam;
		}

		int getPrice()
		{
			return price;
		}

		LibraryItem operator+( const LibraryItem& param )
		{
			LibraryItem li;
			li.setPrice( price + param.price );
			return li;
		}

		LibraryItem& operator = (const LibraryItem &t)
		{
			cout<<"assignment operator of LibraryItem is called "<<endl;
		}

		LibraryItem( LibraryItem&& param )
		{
			cout<<"move constructor of LibraryItem is called"<<endl;
		}

		LibraryItem& operator=(LibraryItem&& a)
		{
			// Self-assignment detection
			cout<<"move assignment operator of LibraryItem is called"<<endl;
		}

	private:
		int type;
		int price;
};


int main(void)
{
	Manager myManager;
	Library myLib;
	LibraryItem book;
	LibraryItem pdf(2,23);
	cout<<"\n";

	myLib.setManager( myManager );
	cout<<"\n";

	Manager newManager = myLib.getManager();
	newManager = myManager;
	Manager newManager2 = newManager;

	cout<<"\n";

	LibraryItem newItem = book + pdf;
	cout << "New items price is : "<< newItem.getPrice() << endl;

	auto item1 = new LibraryItem();
	shared_ptr<LibraryItem> sptr_item1(item1);
	cout << sptr_item1.use_count() << endl; 
	shared_ptr<LibraryItem> sptr_item2(sptr_item1);
	cout << sptr_item1.use_count() << endl; 
 	cout << sptr_item2.use_count() << endl; 
 	if( item1 == nullptr ){
 		cout<<"item1 is null : <1>"<<endl;
 	}
 	sptr_item1.reset();

 	if( item1 == nullptr ){
 		cout<<"item1 is null : <2>"<<endl;
 	}
 	cout << sptr_item2.use_count() << endl; 
	return 0;
}