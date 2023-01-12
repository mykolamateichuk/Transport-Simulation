#include "Vehicle.h"

Truck::Truck()
	: Vehicle(),
	  maxMassOfCargo(10),
	  currMassOfCargo(0)
{}

Truck::Truck
(
	float _maxMassOfCargo, 
	float _currMassOfCargo, 
	std::string _number,
	unsigned int _speed, 
	bool _canMove, 
	unsigned int _gasCapacity, 
	float _gasLevel, 
	std::queue<Point*> _route
)
	: Vehicle(_number, _speed, _canMove, _gasCapacity, _gasLevel, _route),
	  maxMassOfCargo(_maxMassOfCargo),
	  currMassOfCargo(_currMassOfCargo)
{}

Truck::Truck(const Truck& _vehicle)
	: Vehicle(_vehicle),
	  maxMassOfCargo(_vehicle.maxMassOfCargo),
	  currMassOfCargo(_vehicle.currMassOfCargo)
{}

float Truck::getMaxMassOfCargo() const {
	return maxMassOfCargo;
}

float Truck::getCurrMassOfCargo() const {
	return currMassOfCargo;
}

Truck& Truck::setMaxMassOfCargo(float _maxMassOfCargo) {
	maxMassOfCargo = _maxMassOfCargo;
	return *this;
}

Truck& Truck::setCurrMassOfCargo(float _currMassOfCargo) {
	currMassOfCargo = _currMassOfCargo;
	return *this;
}