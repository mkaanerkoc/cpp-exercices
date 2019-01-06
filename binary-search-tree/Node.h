#ifndef NODE_H
#define NODE_H

template <typename T>
class Node{
public:
	Node( T valueParam )
	: value( valueParam )
	{

	}
	~Node();
private:
	T value;
	Node<T> *left;
	Node<T> *right;
};


#endif // NODE_H