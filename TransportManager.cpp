#include "TransportManager.h"

#include <string>
#include <array>

std::string generateRandomCarNumber() {
	std::string number;

	number += char(rand() % 90 - 65) + char(rand() % 90 - 65);
	number += to_string(rand() % 10000);
	number += char(rand() % 90 - 65) + char(rand() % 90 - 65);
	
	return number;
}

void TransportManager::setUpSimulation(unsigned int _numberOfVehicles, const Map& _map) {
	vehicles.resize(numberOfVehicles);
	const unsigned int num_trucks	= (int) (numberOfVehicles * 0.1);
	const unsigned int num_busses	= (int) (numberOfVehicles * 0.2);
	const unsigned int num_bicycles = (int) (numberOfVehicles * 0.1);

	std::vector<unsigned int> rand_trucks(num_trucks, rand() % numberOfVehicles);
	std::vector<unsigned int> rand_busses(num_busses, rand() % numberOfVehicles);
	std::vector<unsigned int> rand_bicycles(num_bicycles, rand() % numberOfVehicles);

	// To be continued
};

void TransportManager::inputData() {
	std::cout << "Number of vehicles > ";
	std::cin >> numberOfVehicles;

	char ans;
	std::cout << "Enter the map? (Y/n) > ";
	std::cin >> ans;

	if (ans == 'Y') {
		unsigned int rows, columns;
		std::cout << "Width of your map (matrix) > ";
		std::cin >> columns;

		std::cout << "Height of your map (matrix) > ";
		std::cin >> rows;
		
		unsigned int temp;
		std::vector<std::vector<unsigned int>> temp_map(rows, std::vector<unsigned int>(columns, 0));
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < columns; ++j) {
				std::cout << "[" << i << "][" << j << "]" << " = ";
				std::cin >> temp;
				temp_map[i][j] = temp;
			}
			std::cout << "\n";
		}

		map.setMap(temp_map);
	}
	else if (ans == 'n') {
		return;
	}
	else {
		std::cout << "The entered symbols was not 'Y' or 'n'! Try again!" << std::endl;
		inputData();
	}
}	

void TransportManager::printStats() const {
	for (const auto& vehicle : vehicles) {
		//std::cout << "********************************" << std::endl;
		std::cout << "Vehicle:    " << vehicle->getNumber() << std::endl;
		std::cout << "Next point: " << vehicle->getAppointment() << std::endl;
		std::cout << "Gas level:  " << vehicle->getGasLevel() << std::endl;
	}
};


// Getters
unsigned int TransportManager::getNumberOfVehicles() const {
	return numberOfVehicles;
};

vector<vector<unsigned int>> TransportManager::getMap() const {
	return map.getMap();
};

vector<Vehicle*> TransportManager::getVehicles() const {
	return vehicles;
};

vector<Road*> TransportManager::getRoads() const {
	return roads;
}

vector<Point*> TransportManager::getPoints() const {
	return points;
}


// Setters
void TransportManager::setNumberOfVehicles(unsigned int _numberOfVehicles) {
	numberOfVehicles = _numberOfVehicles;
};

void TransportManager::addVehicle(Vehicle* _vehicle) {
	vehicles.push_back(_vehicle);
	numberOfVehicles++;
};

void TransportManager::addRoad(Road* _road) {

}

void TransportManager::addPoint(Point* _point) {

}
