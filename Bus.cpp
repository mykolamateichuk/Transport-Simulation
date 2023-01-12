#include "Vehicle.h"

Bus::Bus() 
	: Vehicle(),
	  maxNumberOfPassengers(20),
	  currNumberOfPassengers(0)
{}

Bus::Bus
(
	unsigned int _maxNumberOfPassengers, 
	unsigned int _currNumberOfPassengers, 
	std::string _number, 
	unsigned int _speed, 
	bool _canMove, 
	unsigned int _gasCapacity,
	float _gasLevel, 
	std::queue<Point*> _route
)
	: Vehicle(_number, _speed, _canMove, _gasCapacity, _gasLevel, _route),
	  maxNumberOfPassengers(_maxNumberOfPassengers),
	  currNumberOfPassengers(_currNumberOfPassengers)
{}

Bus::Bus(const Bus& _vehicle) 
	: Vehicle(_vehicle),
	  maxNumberOfPassengers(_vehicle.maxNumberOfPassengers),
	  currNumberOfPassengers(_vehicle.currNumberOfPassengers)
{}

unsigned int Bus::getMaxNumberOfPassengers() const {
	return maxNumberOfPassengers;
}

unsigned int Bus::getCurrNumberOfPassengers() const {
	return currNumberOfPassengers;
}

Bus& Bus::setMaxNumberOfPassengers(unsigned int _maxNumberOfPassengers) {
	maxNumberOfPassengers = _maxNumberOfPassengers;
	return *this;
}

Bus& Bus::setCurrNumberOfPassengers(unsigned int _currNumberOfPassengers) {
	currNumberOfPassengers = _currNumberOfPassengers;
	return *this;
}