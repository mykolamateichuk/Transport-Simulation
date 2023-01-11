#include "TransportManager.h"
#include <string>

std::string generateRandomCarNumber() {
	std::string number;

	number += char(rand() % 90 - 65) + char(rand() % 90 - 65);
	number += to_string(rand() % 10000);
	number += char(rand() % 90 - 65) + char(rand() % 90 - 65);
	
	return number;
}

void TransportManager::setUpSimulation() {};

void TransportManager::inputData() {};

void TransportManager::printStats() const {
	for (auto vehicle : vehicles) {
		std::cout << "********************************" << std::endl;
		std::cout << "Vehicle: " << vehicle->getNumber() << std::endl;
		std::cout << "Next Point: " << vehicle->getAppointment() << std::endl;
		std::cout << "Fuel Left: " << vehicle->getGasLevel() << std::endl;
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
