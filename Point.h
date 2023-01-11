#ifndef POINT_H 
#define POINT_H

#include <vector>
#include "Road.h"

enum Type {
	NoType,
	Entertainment,
	GasStation,
	BusStop,
	Parking,
	Warehouse
};

class Point {
private:
	Type type;
	unsigned int id;
	unsigned int numberOfSlots;
	std::vector<Road> connectedRoads;

public:
	Point();
	Point(Type, unsigned int, unsigned int, const std::vector<Road>&);
	Point(const Point&);

	Type getType() const;
	unsigned int getId() const;
	unsigned int getNumberOfSlots() const;
	std::vector<Road> getConnectedRoads() const;

	Point& setType(Type _type);
	Point& setId(unsigned int _id);
	Point& setNumberOfSlots(unsigned int _numberOfSlots);
	Point& setConnectedRoads(const std::vector<Road>&);

	~Point();
};

class EntertainmentPoint : public Point {
private:
	unsigned int durationOfStop;

public:
	EntertainmentPoint();
	EntertainmentPoint(unsigned int, Type, unsigned int, unsigned int, const std::vector<Road>&);
	EntertainmentPoint(const EntertainmentPoint&);

	unsigned int getDurationOfStop() const;

	EntertainmentPoint& setDurationOfStop(unsigned int);
};

class GasStationPoint : public Point {
private:
	float refuellingSpeedCoef;

public:
	GasStationPoint();
	GasStationPoint(float, Type, unsigned int, unsigned int, const std::vector<Road>&);
	GasStationPoint(const GasStationPoint&);

	float getRefuellingSpeedCoef() const;

	GasStationPoint& setRefuellingSpeedCoef(float);
};

class BusStopPoint : public Point {
private:
	unsigned int numberOfPassengers;

public:
	BusStopPoint();
	BusStopPoint(unsigned int, Type, unsigned int, unsigned int, const std::vector<Road>&);
	BusStopPoint(const BusStopPoint&);

	unsigned int getNumberOfPassengers() const;

	BusStopPoint& setNumberOfPassengers(unsigned int);
};

class ParkingPoint : public Point {
private:
	float chanceOfStaying;

public:
	ParkingPoint();
	ParkingPoint(float, Type, unsigned int, unsigned int, const std::vector<Road>&);
	ParkingPoint(const ParkingPoint&);

	float getChanceOfStaying() const;

	ParkingPoint& setChanceOfStaying(float);
};

class WarehousePoint : public Point {
private:
	float massOfCargo;

public:
	WarehousePoint();
	WarehousePoint(float, Type, unsigned int, unsigned int, const std::vector<Road>&);
	WarehousePoint(const WarehousePoint&);

	float getMassOfCargo() const;

	WarehousePoint& setMassOfCargo(float);
};

#endif
