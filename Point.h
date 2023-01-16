#ifndef POINT_H 
#define POINT_H

#include <iostream>
#include <vector>

enum PointType {
	NoType,
	Entertainment,
	GasStation,
	BusStop,
	Parking,
	Warehouse
};

class Point {
private:
	PointType type;
	unsigned int id;
	unsigned int numberOfSlots;
	unsigned int currTakenSlots;

public:
	Point();
	Point(PointType, unsigned int, unsigned int, unsigned int);
	Point(const Point&);

	PointType getType() const;
	unsigned int getId() const;
	unsigned int getNumberOfSlots() const;
	unsigned int getCurrTakenSlots() const;

	Point& setType(PointType);
	Point& setId(unsigned int);
	Point& setNumberOfSlots(unsigned int);
	Point& setCurrTakenSlots(unsigned int);

	void print() const;

	Point& operator ++ ();
	Point& operator -- ();
};



class EntertainmentPoint : public Point {
private:
	unsigned int durationOfStop;

public:
	EntertainmentPoint();
	EntertainmentPoint(unsigned int, PointType, unsigned int, unsigned int, unsigned int);
	EntertainmentPoint(const EntertainmentPoint&);

	EntertainmentPoint(const Point&);

	unsigned int getDurationOfStop() const;

	EntertainmentPoint& setDurationOfStop(unsigned int);
};

class GasStationPoint : public Point {
private:
	float refuellingSpeedCoef;

public:
	GasStationPoint();
	GasStationPoint(float, PointType, unsigned int, unsigned int, unsigned int);
	GasStationPoint(const GasStationPoint&);

	GasStationPoint(const Point&);

	float getRefuellingSpeedCoef() const;

	GasStationPoint& setRefuellingSpeedCoef(float);
};

class BusStopPoint : public Point {
private:
	unsigned int numberOfPassengers;

public:
	BusStopPoint();
	BusStopPoint(unsigned int, PointType, unsigned int, unsigned int, unsigned int);
	BusStopPoint(const BusStopPoint&);

	BusStopPoint(const Point&);

	unsigned int getNumberOfPassengers() const;

	BusStopPoint& setNumberOfPassengers(unsigned int);
};

class WarehousePoint : public Point {
private:
	float massOfCargo;

public:
	WarehousePoint();
	WarehousePoint(float, PointType, unsigned int, unsigned int, unsigned int);
	WarehousePoint(const WarehousePoint&);

	WarehousePoint(const Point&);

	float getMassOfCargo() const;

	WarehousePoint& setMassOfCargo(float);
};

struct ReturnPoint {
	PointType type;
	Point* point;
	EntertainmentPoint* entertainment;
	GasStationPoint* gasStation;
	BusStopPoint* busStop;
	WarehousePoint* warehouse;

	unsigned int durationOfStop;
	float refuellingCoef;
	unsigned int numberOfPassengers;
	float massOfCargo;
};

#endif
