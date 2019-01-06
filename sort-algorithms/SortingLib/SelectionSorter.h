#ifndef SELECTION_SORTER_H
#define SELECTION_SORTER_H

#include "ISorter.h"
#include <iostream>

class SelectionSorter : public ISorter
{
public:
	void sort( std::vector<int>& param ) override
	{
		std::cout<<"Hello from Selection sort"<<std::endl;
		for( int k = 0; k < param.size() - 1; k++ )
		{
			int tempSwapValue = 0;
			int localMinIndex = k;
			for( int j = k; j < param.size(); j++ )
			{
				if( param[j] < param[localMinIndex] )
				{
					localMinIndex = j;
				}
			}
			tempSwapValue = param[ localMinIndex ];
			param[ localMinIndex ] = param[ k ];
			param[ k ] = tempSwapValue;  
		}
	}
};


#endif // SELECTION_SORTER_H