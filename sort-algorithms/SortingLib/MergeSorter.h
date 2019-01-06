#ifndef MERGE_SORTER_H
#define MERGE_SORTER_H


#include "ISorter.h"
#include <iostream>

class MergeSorter : public ISorter
{
public:
	void sort( std::vector<int>& param ) override 
	{
		std::cout<<"Hello from Merge Sorter ! "<<std::endl;
		param = mergeSort( param );
	}

private:
	std::vector<int> merge( std::vector<int>& left, std::vector<int>& right )
	{
		int leftIndex = 0;
		int rightIndex = 0;
		std::vector<int> retVector;
		while( ( leftIndex < left.size() ) && ( rightIndex < right.size() ) ) 
		{
			if( left[leftIndex] < right[rightIndex] )
			{
				retVector.push_back( left[leftIndex]);
				leftIndex++;
			}
			else
			{
				retVector.push_back( right[rightIndex]);
				rightIndex++;
			}
		}
		while( leftIndex < left.size() )
		{
			retVector.push_back( left[leftIndex]);
			leftIndex++;
		}
		while( rightIndex < right.size() )
		{
			retVector.push_back( right[rightIndex]);
			rightIndex++;
		}
		return retVector;
	}

	std::vector<int> mergeSort( std::vector<int>& param )
	{
		if( 1 == param.size() )
		{
			//base point of recursive algorithm
			return param;
		}
		
		int midIndex = param.size() / 2;
		std::vector<int> left( param.begin(), param.begin()+midIndex );
		std::vector<int> right( param.begin() + midIndex, param.end() );
		left = mergeSort( left );
		right = mergeSort ( right );
		return merge( left, right );
	}	
};


#endif // MERGE_SORTER_H