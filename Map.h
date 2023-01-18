#ifndef MAP_H
#define MAP_H

#include <vector>

class Map {
private:
	unsigned int size;

	std::vector<std::vector<unsigned int>> map;
public:
	Map();
	Map(const std::vector<std::vector<unsigned int>>&);
	Map(const Map&);

	unsigned int getSize() const;
	std::vector<std::vector<unsigned int>> getMap() const;

	Map& setMap(std::vector<std::vector<unsigned int>>);

	~Map();
};

#endif
