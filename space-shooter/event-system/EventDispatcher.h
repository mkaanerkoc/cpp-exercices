#ifndef EVENT_DISPATCHER_H
#define EVENT_DISPATCHER_H

#include <vector>
#include "EventObserver.h"


class EventDispatcher
{
public:
	
	void registerObserver( EventObserver* param )
	{
		subscribers.push_back( param );
	}
	void dispatch( int eventKeyParam, int eventPayloadParam )
	{
		for( auto i : subscribers )
		{
			i->update( eventKeyParam, eventPayloadParam );
		}
	}

private:
	std::vector<EventObserver*> subscribers;
};


#endif // EVENT_DISPATCHER