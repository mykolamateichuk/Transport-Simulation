#include "Road.h"

Road::Road() 
	: length(0.0f), speedLimit(50), massLimit(10.0f) 
{}

Road::Road(float _length, unsigned int _speedLimit, float _massLimit) 
	: length(_length), speedLimit(_speedLimit), massLimit(_massLimit)
{}

Road::Road(Road& _road) 
	: length(_road.length), speedLimit(_road.speedLimit), massLimit(_road.massLimit) 
{}

float Road::getLength() const {
	return length;
}

unsigned int Road::getSpeedLimit() const {
	return speedLimit;
}

float Road::getMassLimit() const {
	return massLimit;
}

Road& Road::setLength(float _length) {
	length = _length;
	return *this;
}

Road& Road::setSpeedLimit(unsigned int _speedLimit) {
	speedLimit = _speedLimit;
	return *this;
}

Road& Road::setMassLimit(float _massLimit) {
	massLimit = _massLimit;
	return *this;
}