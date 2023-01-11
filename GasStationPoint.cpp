#include "Point.h"

GasStationPoint::GasStationPoint() 
	: Point(),
	  refuellingSpeedCoef(0.0f)
{}

GasStationPoint::GasStationPoint
(float _coef, Type _type, unsigned int _id, unsigned int _numberOfSlots, const std::vector<Road>& _connectedRoads) 
	: Point(_type, _id, _numberOfSlots, _connectedRoads),
	  refuellingSpeedCoef(_coef)
{}

GasStationPoint::GasStationPoint(const GasStationPoint& _point) 
	: Point(_point),
	  refuellingSpeedCoef(_point.refuellingSpeedCoef)
{}

float GasStationPoint::getRefuellingSpeedCoef() const {
	return refuellingSpeedCoef;
}

GasStationPoint& GasStationPoint::setRefuellingSpeedCoef(float _coef) {
	refuellingSpeedCoef = _coef;
	return *this;
}
