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
	unsigned int _number,
	unsigned int _speed,
	bool _canMove,
	unsigned int _gasCapacity,
	float _gasLevel,
	std::vector<unsigned int> _route,
	Navigator* _nav,
	int _currPoint,
	unsigned int _stopCount
)
	: Vehicle(_number, _speed, _canMove, _gasCapacity, _gasLevel, _route, _nav, _currPoint, _stopCount),
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

void Bus::print() const {
	Vehicle::print();
	std::cout << "Max number of passengers: " << maxNumberOfPassengers << "\n";
	std::cout << "Current number of passengers: " << currNumberOfPassengers << "\n";
}

void Bus::update(float _consumption) {
	if (route.empty() && (currentPoint == 8 || currentPoint == 3)) {
		route = navigator->findRoute(currentPoint, 0);
	}
	else if (currentPoint == 1) {
		route = navigator->findRoute(currentPoint, 7);
	}

	update_currPoint();
	update_gasLevel(_consumption);
}