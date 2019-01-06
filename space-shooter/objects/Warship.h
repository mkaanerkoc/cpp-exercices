#ifndef WARSHIP_H
#define WARSHIP_H

#include "Point.h"
#include <vector>

class Warship
{
public:
	Warship();
	~Warship();
	draw();
	move( int x, int y);
private:
	Point2D center;
};



#endif