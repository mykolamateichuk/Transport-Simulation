#include "TransportManager.h"

#include <string>
#include <array>

std::string generateRandomCarNumber() {
	std::string number;

	number += char(rand() % 90 - 65) + char(rand() % 90 - 65);
	number += std::to_string(rand() % 10000);
	number += char(rand() % 90 - 65) + char(rand() % 90 - 65);
	
	return number;
}

void TransportManager::setUpSimulation(unsigned int _numberOfVehicles, const Map& _map) {
	allVehicles.vehicles.resize(numberOfVehicles);
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
	for (const auto& vehicle : allVehicles.vehicles) {
		//std::cout << "********************************" << std::endl;
		std::cout << "Vehicle:    " << vehicle->getNumber() << std::endl;
		//std::cout << "Next point: " << vehicle->getAppointment() << std::endl;
		std::cout << "Gas level:  " << vehicle->getGasLevel() << std::endl;
	}
};


// Getters
unsigned int TransportManager::getNumberOfVehicles() const {
	return numberOfVehicles;
};

std::vector<std::vector<unsigned int>> TransportManager::getMap() const {
	return map.getMap();
};

Vehicles TransportManager::getVehicles() const {
	return allVehicles;
};

std::vector<Road*> TransportManager::getRoads() const {
	return roads;
}

Points TransportManager::getPoints() const {
	return allPoints;
}


// Setters
void TransportManager::setNumberOfVehicles(unsigned int _numberOfVehicles) {
	numberOfVehicles = _numberOfVehicles;
};

void TransportManager::addVehicle(Vehicle* _vehicle) {
	allVehicles.vehicles.push_back(_vehicle);
	numberOfVehicles++;
};

void TransportManager::addBus(Bus* _bus) {
	allVehicles.busses.push_back(_bus);
	numberOfVehicles++;
}

void TransportManager::addTruck(Truck* _truck) {
	allVehicles.trucks.push_back(_truck);
	numberOfVehicles++;
}

void TransportManager::addBicycle(Bicycle* _bicycle) {
	allVehicles.bicycles.push_back(_bicycle);
	numberOfVehicles++;
}

void TransportManager::addRoad(Road* _road) {
	roads.push_back(_road);
}

void TransportManager::addEntertainment(EntertainmentPoint* _point) {
	allPoints.entertainments.push_back(_point);
}

void TransportManager::addGasStation(GasStationPoint* _point) {
	allPoints.gasStations.push_back(_point);
}

void TransportManager::addBusStop(BusStopPoint* _point) {
	allPoints.busStops.push_back(_point);
}

void TransportManager::addParking(ParkingPoint* _point) {
	allPoints.parkings.push_back(_point);
}

void TransportManager::addWarehouse(WarehousePoint* _point) {
	allPoints.warehouses.push_back(_point);
}