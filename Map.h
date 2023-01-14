#ifndef MAP_H
#define MAP_H

#include <vector>
#include "Point.h"
#include <iostream>

class Cell {
private:
	PointType point;
	unsigned int pointId;
	unsigned int numberOfRoads;
	std::vector<unsigned int> connectedPointIds;

	// Point point;
public:
	Cell();
	Cell(PointType, unsigned int, unsigned int, const std::vector<unsigned int>&);
	Cell(const Cell&);

	PointType getPoint() const;
	unsigned int getPointId() const;
	unsigned int getNumberOfRoads() const;
	std::vector<unsigned int> getConnectedPointIds() const;

	Cell& setPoint(PointType);
	Cell& setPointId(unsigned int);
	Cell& setNumberOfRoads(unsigned int);
	Cell& setConnectedPointIds(const std::vector<unsigned int>&);

	friend std::istream& operator >> (std::istream&, Cell&);
	friend std::ostream& operator << (std::ostream&, const Cell&);
};

class Map {
private:
	unsigned int size;

	std::vector<std::vector<Cell>> map;
public:
	Map();
	Map(const std::vector<std::vector<Cell>>&);
	Map(const Map&);

	unsigned int getSize() const;
	std::vector<std::vector<Cell>> getMap() const;

	Map& setMap(std::vector<std::vector<Cell>>);

	~Map();
};

#endif
