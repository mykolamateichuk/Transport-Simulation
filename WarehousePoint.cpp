#include "Point.h"

WarehousePoint::WarehousePoint()
	: Point(),
	  massOfCargo(0.0f)
{}

WarehousePoint::WarehousePoint
(float _massOfCargo, PointType _type, unsigned int _id, unsigned int _numberOfSlots, unsigned int _currSlots)
	: Point(_type, _id, _numberOfSlots, _currSlots),
	  massOfCargo(_massOfCargo)
{}

WarehousePoint::WarehousePoint(const WarehousePoint& _point)
	: Point(_point),
	  massOfCargo(_point.massOfCargo)
{}

WarehousePoint::WarehousePoint(const Point& _point) 
	: Point(_point),
	  massOfCargo(0)
{}

float WarehousePoint::getMassOfCargo() const {
	return massOfCargo;
}

WarehousePoint& WarehousePoint::setMassOfCargo(float _massOfCargo) {
	massOfCargo = _massOfCargo;
	return *this;
}
