#include <vector>
#include <iostream>

using namespace std;

int search( std::vector<int>&param, int leftIndexParam, int rightIndexParam, int searchValue );


int main(void)
{
	std::vector<int> myVect{1,3,5,6,7,8,13,15,18};
	cout<<"Hello world from binary search on sorted array example"<<endl;
	int searchValue = 0;
	int index = 0;
	for( int k = 0; k < myVect.size(); k++ )
	{
		searchValue = myVect[k];
		index = search( myVect, 0, myVect.size()-1, searchValue );
		cout<<"Index of "<<searchValue<<" is : "<<index<<endl;
	}
	
	searchValue = 2312;
	index = search( myVect, 0, myVect.size()-1, searchValue );
	cout<<"Index of "<<searchValue<<" is : "<<index<<endl;

	searchValue = -231;
	index = search( myVect, 0, myVect.size()-1, searchValue );
	cout<<"Index of "<<searchValue<<" is : "<<index<<endl;

	searchValue = -1;
	index = search( myVect, 0, myVect.size()-1, searchValue );
	cout<<"Index of "<<searchValue<<" is : "<<index<<endl;


	return 0;
}


int search( std::vector<int>&param, int leftIndexParam, int rightIndexParam, int searchValue )
{
	int retValueTemp = -1;
	int midIndex = (( rightIndexParam - leftIndexParam ) / 2 ) + leftIndexParam;
	if( leftIndexParam == rightIndexParam )
	{
		if( searchValue == param[leftIndexParam] )
		{
			return leftIndexParam;
		}
		else
		{
			return -1;
		}
	}
	//cout<<"Left Index : "<<leftIndexParam<<"  Right Index "<<rightIndexParam<<endl;
	if( param[midIndex] < searchValue )
	{
		retValueTemp = search( param, midIndex + 1, rightIndexParam, searchValue);
	}
	else if( param[midIndex] > searchValue )
	{
		retValueTemp = search( param, leftIndexParam, midIndex - 1 , searchValue);
	}
	else
	{
		retValueTemp = midIndex;
	}
	return retValueTemp;
}