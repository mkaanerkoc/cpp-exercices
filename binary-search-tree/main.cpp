#include <iostream>
#include <memory>
#include "BinarySearchTree.h"

using namespace std;

class BinarySearchTreeNode
{
	public:
		BinarySearchTreeNode( int valueParam ) 
		: value( valueParam ), left( nullptr ), right( nullptr ), parent( nullptr )
		{

		}
		~BinarySearchTreeNode()
		{

		}
		void addNode( BinarySearchTreeNode& nodeParam )
		{
			if( nodeParam.getValue() == value )
			{
				return;
			}
			else if( nodeParam.getValue() < value )
			{
				if ( left != nullptr )
				{
					left->addNode( nodeParam );
				}
				else if ( left == nullptr )
				{
					left = &nodeParam;
				}
			}
			else if( nodeParam.getValue() > value )
			{
				if ( right != nullptr )
				{
					right->addNode( nodeParam );
				}
				else if ( right == nullptr )
				{
					right = &nodeParam;	
				}
			}
		}
		void removeNode( BinarySearchTreeNode& nodeParam )
		{
			int removeCase = nodeParam.getChildCount();
			if( 0 == removeCase )
			{

			}
			else if( 1 == removeCase )
			{

			}
			else if( 2 == removeCase )
			{

			}
			else
			{
				// some problem here...
				return;
			}
		}

		BinarySearchTreeNode* getNode( const int valueParam )
		{
			BinarySearchTreeNode* iterator;	
			if( valueParam == value )
			{
				return this;
			}
			else if( ( left != nullptr ) && ( valueParam < value ) )
			{
				return left->getNode( valueParam );
			}
			else if( ( right != nullptr ) && ( valueParam > value ) )
			{
				return right->getNode( valueParam );
			}
			return nullptr;
		}
		void printTree()
		{
			cout<<"["<<value<<"]"<<endl;
			if( left != nullptr )
			{
				cout<<"/";
			}
			if( right != nullptr )
			{	
				cout<<'\\'<<endl;
			}
			if( left != nullptr )
			{
				left->printTree();
			}
			if( right != nullptr )
			{	
				right->printTree();
			}
		}
		int getHeightOfTree()
		{
			int retValueTemp = 0;
			int leftDepth = 0;
			int rightDepth = 0;
			if( ( nullptr == left ) && ( nullptr == right )  )
			{
				retValueTemp = 0;
				return retValueTemp;
			}
			else
			{
				if( nullptr != left )
				{
					leftDepth = left->getHeightOfTree();
				}
				if ( nullptr != right )
				{
					rightDepth = right->getHeightOfTree();
				}
				if( leftDepth >= rightDepth )
				{
					retValueTemp = leftDepth;
				}
				else
				{
					retValueTemp = rightDepth;
				}
				return retValueTemp + 1;
			}
			return retValueTemp;	
		}
		int getValue() const {
			return value;
		}
		bool hasLeftChild()
		{
			return left != nullptr;
		}
		bool hasRightChild()
		{
			return right != nullptr;
		}
		int getChildCount()
		{
			int retValueTemp = 0;
			if( nullptr != left )
			{
				retValueTemp++;
			}
			if( nullptr != right )
			{
				retValueTemp++;
			}
			return retValueTemp;
		}
	private:
		int value;
		BinarySearchTreeNode *parent;
		BinarySearchTreeNode *left;
		BinarySearchTreeNode *right;
};

int main( void )
{
	cout<<"Hello world from binary search tree example "<<endl;
	BinarySearchTree<int> tree;
	return 0;
}