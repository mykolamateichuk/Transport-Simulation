#include "Map.h"

Map::Map() : size(0) {
	map.resize(0);
}

Map::Map(std::vector<std::vector<unsigned int>> _map) 
	: map(_map),
	  size(_map.size())
{}

Map::Map(Map& _mapClass) 
	: map(_mapClass.map),
	  size(_mapClass.map.size())
{}

std::vector<std::vector<unsigned int>> Map::getMap() const {
	return map;
}

unsigned int Map::getSize() const {
	return size;
}

Map& Map::setMap(std::vector<std::vector<unsigned int>> _map) {
	map = _map;
	size = _map.size();
	return *this;
}

Map::~Map() {
	map.clear();
}