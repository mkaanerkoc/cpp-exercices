#ifndef QUICK_SORTER_H
#define QUICK_SORTER_H

#include "ISorter.h"
#include <iostream>
#include "SortingUtils.h"

class QuickSorter : public ISorter
{
public:
	void sort( std::vector<int>& param )
	{
		std::cout<<"Hello from Quick Sorter ! "<<std::endl;
		quickSort( param, 0, param.size() - 1 );
	}
private:
	int partition( std::vector<int>& param, int leftIndexParam, int rightIndexParam )
	{
		int rightIndex = rightIndexParam;
		int leftIndex = leftIndexParam;
		int pivotValue = param[ rightIndexParam ];
		std::vector<int> tempVector = param;
		for( int k = leftIndexParam; k < rightIndexParam; k++ )
		{
			if( tempVector[k] > pivotValue )
			{
				param[ rightIndex ] = tempVector[k];
				rightIndex--;
			}
			else if( tempVector[k] < pivotValue )
			{
				param[leftIndex] = tempVector[k];
				leftIndex++;
			}
		}
		param[ leftIndex ] = pivotValue;
		return leftIndex;
	}
	void quickSort( std::vector<int>& param, int leftIndexParam, int rightIndexParam )
	{
		if( leftIndexParam >= rightIndexParam )
		{
			return;
		}

		int partitionIndex = partition( param, leftIndexParam, rightIndexParam );
		quickSort( param, leftIndexParam, partitionIndex - 1);
		quickSort( param, partitionIndex + 1, rightIndexParam );
	}
};

#endif // QUICK_SORTER_H