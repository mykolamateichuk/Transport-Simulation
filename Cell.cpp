#include "Map.h"

Cell::Cell() 
	: point(NoType),
	  pointId(0),
	  numberOfRoads(0),
	  connectedPointIds(0)
{}

Cell::Cell(PointType _point, unsigned int _pointId, unsigned int _numberOfRoads, const std::vector<unsigned int>& _roadLengths)
	: point(_point),
	  pointId(_pointId),
	  numberOfRoads(_numberOfRoads),
	  connectedPointIds(_roadLengths)
{}

Cell::Cell(const Cell& _cell) 
	: point(_cell.point),
	  pointId(_cell.pointId),
	  numberOfRoads(_cell.numberOfRoads),
	  connectedPointIds(_cell.connectedPointIds)
{}

PointType Cell::getPoint() const {
	return point;
}

unsigned int Cell::getPointId() const {
	return pointId;
}
 
unsigned int Cell::getNumberOfRoads() const {
	return numberOfRoads;
}

std::vector<unsigned int> Cell::getConnectedPointIds() const {
	return connectedPointIds;
}

Cell& Cell::setPoint(PointType _point) {
	point = _point;
	return *this;
}

Cell& Cell::setPointId(unsigned int _pointId) {
	pointId = _pointId;
	return *this;
}

Cell& Cell::setNumberOfRoads(unsigned int _numberOfRoads) {
	numberOfRoads = _numberOfRoads;
	return *this;
}

Cell& Cell::setConnectedPointIds(const std::vector<unsigned int>& _roadLengths) {
	connectedPointIds = _roadLengths;
	return *this;
}

std::istream& operator >> (std::istream& in, Cell& _cell) {
	std::string pointType;

	in >> pointType;
	if (pointType == "entertainment") {
		_cell.setPoint(Entertainment);
	}
	else if (pointType == "gas_station") {
		_cell.setPoint(GasStation);
	}
	else if (pointType == "bus_stop") {
		_cell.setPoint(BusStop);
	}
	else if (pointType == "parking") {
		_cell.setPoint(Parking);
	}
	else if (pointType == "warehouse") {
		_cell.setPoint(Warehouse);
	}
	else {
		return in;
	}

	unsigned int pointId;

	in >> pointId;
	_cell.setPointId(pointId);

	unsigned int numberOfRoads;

	in >> numberOfRoads;
	_cell.setNumberOfRoads(numberOfRoads);

	std::vector<unsigned int> pointIds(numberOfRoads, 0);

	for (auto& id : pointIds) {
		in >> id;
	}

	_cell.setConnectedPointIds(pointIds);

	return in;
}

std::ostream& operator << (std::ostream& out, const Cell& _cell) {
	switch (_cell.getPoint()) {
		case NoType:
			out << "none";
			break;
		case Entertainment:
			out << "Entertainment" << _cell.getPointId();
			break;
		case GasStation:
			out << "GasStation" << _cell.getPointId();
			out << "   ";
			break;
		case BusStop:
			out << "BusStop" << _cell.getPointId();
			out << "      ";
			break;
		case Parking:
			out << "Parking" << _cell.getPointId();
			out << "      ";
			break;
		case Warehouse:
			out << "Warehouse" << _cell.getPointId();
			out << "    ";
			break;
	}

	out << "\t";

	for (const auto& id : _cell.getConnectedPointIds()) {
		out << id << " ";
	}

	return out;
}