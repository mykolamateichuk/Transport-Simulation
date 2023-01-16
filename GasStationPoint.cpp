#include "Point.h"

GasStationPoint::GasStationPoint() 
	: Point(),
	  refuellingSpeedCoef(0.0f)
{}

GasStationPoint::GasStationPoint
(float _coef, PointType _type, unsigned int _id, unsigned int _numberOfSlots, unsigned int _currSlots) 
	: Point(_type, _id, _numberOfSlots, _currSlots),
	  refuellingSpeedCoef(_coef)
{}

GasStationPoint::GasStationPoint(const GasStationPoint& _point) 
	: Point(_point),
	  refuellingSpeedCoef(_point.refuellingSpeedCoef)
{}

GasStationPoint::GasStationPoint(const Point& _point)
	: Point(_point),
	  refuellingSpeedCoef((rand() % 81) / 100)
{}

float GasStationPoint::getRefuellingSpeedCoef() const {
	return refuellingSpeedCoef;
}

GasStationPoint& GasStationPoint::setRefuellingSpeedCoef(float _coef) {
	refuellingSpeedCoef = _coef;
	return *this;
}
