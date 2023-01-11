#ifndef ROAD_H
#define ROAD_H

class Road {
private:
	float length;
	unsigned int speedLimit;
	float massLimit;
public:
	Road();
	Road(float, unsigned int, float);
	Road(Road&);

	float getLength() const;
	unsigned int getSpeedLimit() const;
	float getMassLimit() const;

	Road& setLength(float);
	Road& setSpeedLimit(unsigned int);
	Road& setMassLimit(float);
};

#endif
