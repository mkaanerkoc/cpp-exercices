#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <GL/freeglut.h>
#include "GameObject.h"
#include "EventObserver.h"
#include "MinigunFireSystem.h"
#include <iostream>



class Spaceship : public GameObject, public EventObserver{
	public:

		Spaceship()
		{
			fireSystem = new MinigunFireSystem();
			activeFireSystem = fireSystem;
		}

		~Spaceship()
		{
			if( nullptr != fireSystem )
			{
				delete fireSystem;
			}

		}

		Spaceship( int xParam, int yParam )
		{

		}
		void draw() override
		{
			glVertex2f(20.0, 10.0);
        	glVertex2f(40.0, 100.0);
        	glVertex2f(60.0, 10.0);
		}

		void update( int keyParam, int payloadParam ) override
		{
			if( 100 == keyParam )
			{
				std::cout<<"SpaceShip : LEFT ! "<<keyParam<<std::endl;

			}
			else if( 101 == keyParam )
			{
				std::cout<<"SpaceShip : UP ! "<<keyParam<<std::endl;
			}
			else if( 102 == keyParam )
			{
				std::cout<<"SpaceShip : RIGHT ! "<<keyParam<<std::endl;
			}
			else if( 103 == keyParam )
			{
				std::cout<<"SpaceShip : DOWN ! "<<keyParam<<std::endl;
			}	
			else if ( 32 == keyParam )
			{
				activeFireSystem->fire();
			}
		}	

		void setFireSystem( SpaceShipFireSystem *param )
		{
			activeFireSystem = param;
		}

	private:
		SpaceShipFireSystem *fireSystem; //kaanbak buna
		SpaceShipFireSystem *activeFireSystem;
		int x;
		int y;

};


#endif