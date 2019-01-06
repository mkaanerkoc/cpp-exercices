#ifndef MINIGUN_FIRE_SYSTEM_H
#define MINIGUN_FIRE_SYSTEM_H

#include "SpaceShipFireSystem.h"

class MinigunFireSystem : public SpaceShipFireSystem
{
	void fire()
	{
		std::cout<<"Minigun Fire System : FIRE ! "<<std::endl;
	}
};


#endif // MINIGUN_FIRE_SYSTEM_H