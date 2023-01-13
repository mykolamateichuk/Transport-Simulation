#ifndef ROAD_H
#define ROAD_H

#include "Point.h"

class Road {
private:
	float length;
	unsigned int speedLimit;
	float massLimit;

	Point* startPoint;
	Point* endPoint;
public:
	Road();
	Road(float, unsigned int, float, Point*, Point*);
	Road(const Road&);

	float getLength() const;
	unsigned int getSpeedLimit() const;
	float getMassLimit() const;
	Point* getStartPoint() const;
	Point* getEndPoint() const;

	Road& setLength(float);
	Road& setSpeedLimit(unsigned int);
	Road& setMassLimit(float);
	Road& setStartPoint(Point*);
	Road& setEndPoint(Point*);
};

#endif
