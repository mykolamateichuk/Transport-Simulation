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
	unsigned int _number,
	unsigned int _speed, 
	bool _canMove, 
	unsigned int _gasCapacity, 
	float _gasLevel, 
	std::vector<int> _route,
	Navigator* _nav,
	int _currPoint,
	unsigned int _stopCount
)
	: Vehicle(_number, _speed, _canMove, _gasCapacity, _gasLevel, _route, _nav, _currPoint, _stopCount),
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

void Truck::print() const {
	Vehicle::print();
	std::cout << "Max mass: " << maxMassOfCargo << "\n";
	std::cout << "Current mass: " << currMassOfCargo << "\n";
}
