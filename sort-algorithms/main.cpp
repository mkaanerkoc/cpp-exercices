#include "SortingLibrary.h"

using namespace std;

int main( void ){
	ISorter *sorter = new QuickSorter();

	cout<<"Hello world from Sorting exercises !"<<endl;
	vector<int> myVector{ 45, 23, 12, 33, 13, 65, 123, 66, 31, 24 };
	printVector( myVector );
	sorter->sort( myVector );
	printVector( myVector );
	return 0;
}