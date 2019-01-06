#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Shape.h"


class GameObject{
public:
	GameObject()
	{

	}
	virtual void draw() = 0;
protected:
	Shape2D shape;
private:

};


#endif