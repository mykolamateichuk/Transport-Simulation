#include "Map.h"

Cell::Cell() 
	: point(NoType),
	  numberOfRoads(0),
	  roadLengths(0)
{}

Cell::Cell(PointType _point, unsigned int _numberOfRoads, const std::vector<unsigned int>& _roadLengths)
	: point(_point),
	  numberOfRoads(_numberOfRoads),
	  roadLengths(_roadLengths)
{}

Cell::Cell(const Cell& _cell) 
	: point(_cell.point),
	  numberOfRoads(_cell.numberOfRoads),
	  roadLengths(_cell.roadLengths)
{}

PointType Cell::getPoint() const {
	return point;
}

unsigned int Cell::getNumberOfRoads() const {
	return numberOfRoads;
}

std::vector<unsigned int> Cell::getRoadLengths() const {
	return roadLengths;
}

Cell& Cell::setPoint(PointType _point) {
	point = _point;
	return *this;
}

Cell& Cell::setNumberOfRoads(unsigned int _numberOfRoads) {
	numberOfRoads = _numberOfRoads;
	return *this;
}

Cell& Cell::setRoadLengths(const std::vector<unsigned int>& _roadLengths) {
	roadLengths = _roadLengths;
	return *this;
}