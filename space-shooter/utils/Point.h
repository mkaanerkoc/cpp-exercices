#ifndef POINT2D_H
#define POINT2D_H

class Point2D{
public:
	Point2D();
	Point2D( int xCoordParam, int yCoordParam );
	
	int getX() const;
	int getY() const;
	void setX( int param );
	void setY( int param );
private:
	int x;
	int y;
};

#endif