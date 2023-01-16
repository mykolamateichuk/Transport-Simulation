#include "Vehicle.h"

Bicycle::Bicycle()
	: Vehicle(),
	  chanceOfGoingOffRoad(0.5f)
{}

Bicycle::Bicycle
(
	float _chanceOfGoingOffRoad, 
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

void Bicycle::print() const {
	Vehicle::print();
	std::cout << "Chance of going off road: " << chanceOfGoingOffRoad << "\n";
}

void Bicycle::update_currPoint() {
	if (route.empty()) return;

	if ((rand() % 101) / 100 < chanceOfGoingOffRoad) {
		currentPoint = route.back();
		route = navigator->findroad(currentPoint, rand() % 10);
		return;
	}

	currentPoint = route.front();
	std::reverse(route.begin(), route.end());
	route.pop_back();
	std::reverse(route.begin(), route.end());
}

void Bicycle::update() {
	if (!canMove) return;

	if (route.empty()) {
		route = navigator->findroad(currentPoint, rand() % 10);
	}

	update_currPoint();
}