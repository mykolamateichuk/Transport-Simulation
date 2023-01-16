#include "Point.h"

Point::Point() 
	: type(NoType), id(0), numberOfSlots(0), currTakenSlots(0)
{}

Point::Point(PointType _type, unsigned int _id, unsigned int _numberOfSlots, unsigned int _currSlots)
	: type(_type), 
	  id(_id),
	  numberOfSlots(_numberOfSlots),
	  currTakenSlots(_currSlots)
{}

Point::Point(const Point& _point) 
	: type(_point.type),
	  id(_point.id),
	  numberOfSlots(_point.numberOfSlots),
	  currTakenSlots(_point.currTakenSlots)
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

unsigned int Point::getCurrTakenSlots() const {
	return currTakenSlots;
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

Point& Point::setCurrTakenSlots(unsigned int _currSlots) {
	currTakenSlots = _currSlots;
	return *this;
}

void Point::print() const {
	switch (type) {
		case NoType:
			std::cout << "NoType";
			break;
		case Entertainment:
			std::cout << "Entertainment";
			break;
		case GasStation:
			std::cout << "GasStation";
			break;
		case BusStop:
			std::cout << "BusStop";
			break;
		case Parking:
			std::cout << "Parking";
			break;
		case Warehouse:
			std::cout << "Warehouse";
			break;
	}

	std::cout << "\n";
	std::cout << "Id: " << id << "\n";
}

Point& Point::operator ++ () {
	currTakenSlots++;
	return *this;
}

Point& Point::operator -- () {
	currTakenSlots--;
	return *this;
}

//Point::~Point() {
//	connectedRoads.clear();
//}