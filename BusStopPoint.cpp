#include "Point.h"

BusStopPoint::BusStopPoint() 
	: Point(),
	  numberOfPassengers(0)
{}

BusStopPoint::BusStopPoint
(unsigned int _numberOfPassengers, PointType _type, unsigned int _id, unsigned int _numberOfSlots, unsigned int _currSlots)
	: Point(_type, _id, _numberOfSlots, _currSlots),
	  numberOfPassengers(_numberOfPassengers)
{}

BusStopPoint::BusStopPoint(const BusStopPoint& _point) 
	: Point(_point),
	  numberOfPassengers(_point.numberOfPassengers)
{}

BusStopPoint::BusStopPoint(const Point& _point)
	: Point(_point),
	  numberOfPassengers(0)
{}

unsigned int BusStopPoint::getNumberOfPassengers() const {
	return numberOfPassengers;
}

BusStopPoint& BusStopPoint::setNumberOfPassengers(unsigned int _numberOfPassengers) {
	numberOfPassengers = _numberOfPassengers;
	return *this;
}