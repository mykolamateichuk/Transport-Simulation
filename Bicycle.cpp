#include "Vehicle.h"

Bicycle::Bicycle()
	: Vehicle(),
	  chanceOfGoingOffRoad(0.5f)
{}

Bicycle::Bicycle
(
	float _chanceOfGoingOffRoad, 
	std::string _number, 
	unsigned int _speed, 
	bool _canMove, 
	unsigned int _gasCapacity, 
	float _gasLevel, 
	std::queue<Point*> _route
)
	: Vehicle(_number, _speed, _canMove, _gasCapacity, _gasLevel, _route),
	  chanceOfGoingOffRoad(_chanceOfGoingOffRoad)
{}

Bicycle::Bicycle(const Bicycle& _vehicle) 
	: Vehicle(_vehicle),
	  chanceOfGoingOffRoad(_vehicle.chanceOfGoingOffRoad)
{}

float Bicycle::getChanceOfGoingOffRoad() const {
	return chanceOfGoingOffRoad;
}

Bicycle& Bicycle::setChanceOfGoingOffRoad(float _chanceOfGoingOffRoad) {
	chanceOfGoingOffRoad = _chanceOfGoingOffRoad;
	return *this;
}