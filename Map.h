#ifndef MAP_H
#define MAP_H

#include <vector>
#include "Point.h"

class Cell {
private:
	PointType point;
	unsigned int roadLength;
public:
	Cell();
	Cell(PointType, unsigned int);
	Cell(const Cell&);

	PointType getPoint() const;
	unsigned int getRoadLength() const;

	Cell& setPoint(PointType);
	Cell& setRoadLength(unsigned int);
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
