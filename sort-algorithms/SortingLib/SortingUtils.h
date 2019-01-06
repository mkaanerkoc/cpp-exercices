#ifndef SORTING_UTILS_H
#define SORTING_UTILS_H

#include <vector>
#include <iostream>

void printVector( std::vector<int> param )
{
	for( auto k : param )
	{
		std::cout<<k<<" ";
	}
	std::cout<<"\n";
}
#endif