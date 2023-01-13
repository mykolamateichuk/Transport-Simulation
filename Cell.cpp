#include "Map.h"

Cell::Cell() 
	: point(NoType),
	  roadLength(0)
{}

Cell::Cell(PointType _point, unsigned int _roadLength)
	: point(_point),
	  roadLength(_roadLength)
{}

Cell::Cell(const Cell& _cell) 
	: point(_cell.point),
	  roadLength(_cell.roadLength)
{}

PointType Cell::getPoint() const {
	return point;
}

unsigned int Cell::getRoadLength() const {
	return roadLength;
}

Cell& Cell::setPoint(PointType _point) {
	point = _point;
	return *this;
}

Cell& Cell::setRoadLength(unsigned int _roadLength) {
	roadLength = _roadLength;
	return *this;
}