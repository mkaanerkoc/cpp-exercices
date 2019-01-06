#ifndef INSERTION_SORTER_H
#define INSERTION_SORTER_H

#include "ISorter.h"
#include <vector>

class InsertionSorter : public ISorter
{	
	void sort( std::vector<int>& param ) override
	{
		int tempSwapValue = 0;
		std::cout<<"Hello world from Insertion Sorter ! "<<std::endl;
		for( int k = 1; k < param.size(); k++ )
		{
			for( int j = k; j > 0; j-- )
			{
				if( param[ j ] < param[ j -1 ] )
				{
					tempSwapValue = param[ j ];
					param[ j ] = param[ j -1  ];
					param[ j - 1 ] = tempSwapValue;
				}
			}
		}	
	}
};


#endif // INSERTION_SORTER_H