#ifndef MAP_H
#define MAP_H

#include <vector>
#include "Point.h"
#include "Road.h"

class Cell {
private:
	PointType point;
	unsigned int numberOfRoads;
	std::vector<unsigned int> roadLengths;
public:
	Cell();
	Cell(PointType, unsigned int, const std::vector<unsigned int>&);
	Cell(const Cell&);

	PointType getPoint() const;
	unsigned int getNumberOfRoads() const;
	std::vector<unsigned int> getRoadLengths() const;

	Cell& setPoint(PointType);
	Cell& setNumberOfRoads(unsigned int);
	Cell& setRoadLengths(const std::vector<unsigned int>&);
};

class Map {
private:
	unsigned int size;

	std::vector<std::vector<unsigned int>> map;
public:
	Map();
	Map(std::vector<std::vector<unsigned int>>);
	Map(Map&);

	unsigned int getSize() const;
	std::vector<std::vector<unsigned int>> getMap() const;

	Map& setMap(std::vector<std::vector<unsigned int>>);

	~Map();
};

#endif
