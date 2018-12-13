#include "Point.h"

Point::Point()
: x(0),y(0)
{

}

Point::Point( int xCoordParam, int yCoordParam )
: x( xCoordParam ), y( yCoordParam )
{

}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}

void Point::setX( int param )
{
	x = param;
}

void Point::setY( int param )
{
	y = param;
}