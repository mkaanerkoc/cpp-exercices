#ifndef EVENT_OBSERVER_H
#define EVENT_OBSERVER_H

class EventObserver{
public:
	virtual void update( int keyParam, int payloadParam ) = 0;
private:

};


#endif // EVENT_OBSERVER_H