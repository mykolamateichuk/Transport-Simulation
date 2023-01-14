#include "Point.h"

ParkingPoint::ParkingPoint() 
	: Point(),
	  chanceOfStaying(0.0f)
{}

ParkingPoint::ParkingPoint
(float _chanceOfStaying, PointType _type, unsigned int _id, unsigned int _numberOfSlots, const std::vector<Road>& _connectedRoads)
	: Point(_type, _id, _numberOfSlots, _connectedRoads),
	  chanceOfStaying(_chanceOfStaying)
{}

ParkingPoint::ParkingPoint(const ParkingPoint& _point) 
	: Point(_point),
	  chanceOfStaying(_point.chanceOfStaying)
{}

ParkingPoint::ParkingPoint(const Point& _point)
	: Point(_point),
	  chanceOfStaying((rand() % 26) + 25)
{}

float ParkingPoint::getChanceOfStaying() const {
	return chanceOfStaying;
}

ParkingPoint& ParkingPoint::setChanceOfStaying(float _chanceOfStaying) {
	chanceOfStaying = _chanceOfStaying;
	return *this;
}