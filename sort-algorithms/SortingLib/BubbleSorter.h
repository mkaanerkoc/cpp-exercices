#ifndef BUBBLE_SORTER_H
#define BUBBLE_SORTER_H

#include "ISorter.h"
#include <iostream>

class BubbleSorter : public ISorter
{
	void sort( std::vector<int>& param ) override
	{
		std::cout<<"Hello world from bubble sort"<<std::endl;
		bool swapMadeFlag = false;
		for( int k = 0; k < param.size(); k++ )
		{
			swapMadeFlag = false;
			for( int j = 0; j < param.size() - 1; j++ )
			{
				if( param[j] > param[j+1] )
				{
					swapMadeFlag = true;
					int tempSwapValue = param[ j + 1 ];
					param[ j + 1 ] = param[ j ];
					param[ j ] = tempSwapValue;
				}
			}
			if( false == swapMadeFlag )
			{
				return; // sorted list
			}	
		}
	}
};

#endif // BUBBLE_SORTER