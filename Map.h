#ifndef MAP_H
#define MAP_H

#include <vector>

class Map {
private: 
	std::vector<std::vector<unsigned int>> map;
public:
	Map();
	Map(std::vector<std::vector<unsigned int>>);
	Map(Map&);

	std::vector<std::vector<unsigned int>> getMap() const;

	Map& setMap(std::vector<std::vector<unsigned int>>);

	~Map();
};

#endif
