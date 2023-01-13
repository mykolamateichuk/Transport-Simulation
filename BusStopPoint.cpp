#include "Point.h"

BusStopPoint::BusStopPoint() 
	: Point(),
	  numberOfPassengers(0)
{}

BusStopPoint::BusStopPoint
(unsigned int _numberOfPassengers, PointType _type, unsigned int _id, unsigned int _numberOfSlots, const std::vector<Road>& _connectedRoads)
	: Point(_type, _id, _numberOfSlots, _connectedRoads),
	  numberOfPassengers(_numberOfPassengers)
{}

BusStopPoint::BusStopPoint(const BusStopPoint& _point) 
	: Point(_point),
	  numberOfPassengers(_point.numberOfPassengers)
{}

unsigned int BusStopPoint::getNumberOfPassengers() const {
	return numberOfPassengers;
}

BusStopPoint& BusStopPoint::setNumberOfPassengers(unsigned int _numberOfPassengers) {
	numberOfPassengers = _numberOfPassengers;
	return *this;
}