#include "Point.h"

Point::Point() 
	: type(NoType), id(0), numberOfSlots(0) 
{
	connectedRoads.resize(0);
}

Point::Point(PointType _type, unsigned int _id, unsigned int _numberOfSlots, const std::vector<Road>& _connectedRoads)
	: type(_type), 
	  id(_id),
	  numberOfSlots(_numberOfSlots),
	  connectedRoads(_connectedRoads)
{}

Point::Point(const Point& _point) 
	: type(_point.type),
	  id(_point.id),
	  numberOfSlots(_point.numberOfSlots),
	  connectedRoads(_point.connectedRoads)
{}

PointType Point::getType() const {
	return type;
}

unsigned int Point::getId() const {
	return id;
}

unsigned int Point::getNumberOfSlots() const {
	return numberOfSlots;
}

std::vector<Road> Point::getConnectedRoads() const {
	return connectedRoads;
}

Point& Point::setType(PointType _type) {
	type = _type;
	return *this;
}

Point& Point::setId(unsigned int _id) {
	id = _id;
	return *this;
}

Point& Point::setNumberOfSlots(unsigned int _numberOfSlots) {
	numberOfSlots = _numberOfSlots;
	return *this;
}

Point& Point::setConnectedRoads(const std::vector<Road>& _connectedRoads) {
	connectedRoads = _connectedRoads;
	return *this;
}

Point::~Point() {
	connectedRoads.clear();
}