#include "Point.h"

WarehousePoint::WarehousePoint()
	: Point(),
	  massOfCargo(0.0f)
{}

WarehousePoint::WarehousePoint
(float _massOfCargo, Type _type, unsigned int _id, unsigned int _numberOfSlots, const std::vector<Road>& _connectedRoads)
	: Point(_type, _id, _numberOfSlots, _connectedRoads),
	  massOfCargo(_massOfCargo)
{}

WarehousePoint::WarehousePoint(const WarehousePoint& _point)
	: Point(_point),
	  massOfCargo(_point.massOfCargo)
{}

float WarehousePoint::getMassOfCargo() const {
	return massOfCargo;
}

WarehousePoint& WarehousePoint::setMassOfCargo(float _massOfCargo) {
	massOfCargo = _massOfCargo;
	return *this;
}
