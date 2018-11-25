#include <map>
#include <iostream>
#include "TypeDefinitions.h"

using namespace std;

typedef pair<Actions, States> actionStatePair;

class StateManager{
public:
	StateManager(){
		_state = INITIAL;
		_stateMap.insert( pair<States, actionStatePair>( INITIAL, actionStatePair(SEND_PACKAGE, TRANSMITTING )));
		_stateMap.insert( pair<States, actionStatePair>( LISTENING, actionStatePair(SEND_PACKAGE, TRANSMITTING )));
		_stateMap.insert( pair<States, actionStatePair>( TRANSMITTING, actionStatePair( TX_DONE, WAITING_RX_DONE )));
		_stateMap.insert( pair<States, actionStatePair>( TRANSMITTING, actionStatePair( TX_DONE_TIMEOUT, LISTENING )));
	}
	~StateManager(){

	}
	States run( Actions param ){
		auto nextStates = _stateMap.equal_range( _state );
		for( auto stateItr = nextStates.first; stateItr != nextStates.second; stateItr++ )
		{
			if( param == stateItr->second.first )
			{
				_state = stateItr->second.second;
				break;
			}
		}
		return _state;
	}
private:
	States _state;
	Actions _lastAction;
	multimap< States, actionStatePair> _stateMap;
};


int main( void )
{
	cout<<"Hello world from Automata example"<<endl;
	StateManager sm;
	States st = sm.run( SEND_PACKAGE );
	cout<<"Next State : "<< st << endl;
	st = sm.run( TX_DONE_TIMEOUT );
	cout<<"Next State : "<< st << endl;
	st = sm.run( SEND_PACKAGE );
	cout<<"Next State : "<< st << endl;
	return 0;
}