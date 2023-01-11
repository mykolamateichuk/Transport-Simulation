#include "Map.h"

Map::Map() {
	map.resize(0);
}

Map::Map(std::vector<std::vector<unsigned int>> _map) 
	: map(_map)
{}

Map::Map(Map& _mapClass) 
	: map(_mapClass.map)
{}

std::vector<std::vector<unsigned int>> Map::getMap() const {
	return map;
}

Map& Map::setMap(std::vector<std::vector<unsigned int>> _map) {
	map = _map;
	return *this;
}

Map::~Map() {
	map.clear();
}