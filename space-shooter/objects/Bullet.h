#ifndef BULLET_H
#define BULLET_H

#include "GameObject.h"

class Bullet : public GameObject
{
public:
	Bullet()
	{

	}
	void draw() override
	{
		
	}
private:
	int damage;
};

#endif // BULLET_H