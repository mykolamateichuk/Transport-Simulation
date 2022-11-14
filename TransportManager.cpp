#include "TransportManager.h"
#include <string>

TransportManager::TransportManager() = default;
TransportManager::~TransportManager() = default;

std::string generateRandomCarNumber() {
	std::string number;

	number += char(rand() % 90 - 65) + char(rand() % 90 - 65);
	number += to_string(rand() % 10000);
	number += char(rand() % 90 - 65) + char(rand() % 90 - 65);
	
	return number;
}

void TransportManager::setUpSimulation() {};

void TransportManager::inputData() {};

void TransportManager::printStats() {
	for (auto vehicle : vehicles) {
		std::cout << "********************************" << std::endl;
		std::cout << "Vehicle: " << vehicle->getNumber() << std::endl;
		std::cout << "Next Point: " << vehicle->getAppointment() << std::endl;
		std::cout << "Fuel Left: " << vehicle->getGasLevel() << std::endl;
	}
};


// Getters
unsigned int TransportManager::getNumberOfVehicles() {
	return numberOfVehicles;
};

vector<vector<unsigned int>> TransportManager::getMap() {
	return map;
};

vector<Vehicle*> TransportManager::getVehicles() {
	return vehicles;
};


// Setters
void TransportManager::setNumberOfVehicles(unsigned int new_numberOfVehicles) {
	numberOfVehicles = new_numberOfVehicles;
};

void TransportManager::addVehicle(Vehicle* new_vehicle) {
	vehicles.push_back(new_vehicle);
	numberOfVehicles++;
};
