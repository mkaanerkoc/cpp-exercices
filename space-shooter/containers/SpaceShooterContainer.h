#ifndef SPACESHOOTER_CONTAINER_H
#define SPACESHOOTER_CONTAINER_H


#include "EventDispatcher.h"
#include "Spaceship.h"
#include "Bullet.h"
#include "CollisionHandler.h"

class SpaceShooterContainer
{
public:
	SpaceShooterContainer()
	{
		eventDispatcher.registerObserver( &playerShip );
	}
	void draw()
	{
		playerShip.draw();
		for( auto i : enemyShips )
		{
			i.draw();
		}
		for( auto i : bullets )
		{
			i.draw();
		}
	}
	void update()
	{

	}
	void handleUserInput( int eventKeyParam, int eventPayloadParam )
	{
		eventDispatcher.dispatch( eventKeyParam, eventPayloadParam );
	}
private:
	Spaceship playerShip;
	std::vector<Spaceship> enemyShips;
	std::vector<Bullet> bullets;
	EventDispatcher eventDispatcher;
	CollisionHandler collisionHandler;
};


#endif // SPACESHOOTER_CONTAINER_H