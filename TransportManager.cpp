#include "TransportManager.h"

Vehicles::Vehicles() {
	vehicles.resize(0);
	trucks.resize(0);
	busses.resize(0);
	bicycles.resize(0);
}

Points::Points() {
	entertainments.resize(0);
	gasStations.resize(0);
	busStops.resize(0);
	warehouses.resize(0);
}

void TransportManager::printAllPoints() const {

	std::cout << "Entertainment:\n";
	for (const auto& point : allPoints.entertainments) {
		point->print();
		std::cout << "\n";
	}

	std::cout << "GasStation:\n";
	for (const auto& point : allPoints.gasStations) {
		point->print();
		std::cout << "\n";
	}

	std::cout << "BusStop:\n";
	for (const auto& point : allPoints.busStops) {
		point->print();
		std::cout << "\n";
	}

	std::cout << "Warehouse:\n";
	for (const auto& point : allPoints.warehouses) {
		point->print();
		std::cout << "\n";
	}
}

void TransportManager::printAllVehicles() const {
	std::cout << "Vehicles:\n";
	for (const auto& vehicle : allVehicles.vehicles) {
		vehicle->print();
		std::cout << "\n";
	}

	std::cout << "Trucks:\n";
	for (const auto& vehicle : allVehicles.trucks) {
		vehicle->print();
		std::cout << "\n";
	}

	std::cout << "Busses:\n";
	for (const auto& vehicle : allVehicles.busses) {
		vehicle->print();
		std::cout << "\n";
	}

	std::cout << "Bicycles:\n";
	for (const auto& vehicle : allVehicles.bicycles) {
		vehicle->print();
		std::cout << "\n";
	}
}

unsigned int generateRandomCarNumber() {
	return rand() % 10000;
}

unsigned int generateRandomBicycleNumber() {
	return rand() % 100;
}

void TransportManager::setUpRandomVehicleStats() {
	const unsigned int numTrucks	= (int)(numberOfVehicles * 0.2);
	const unsigned int numBusses	= (int)(numberOfVehicles * 0.3);
	const unsigned int numBicycles	= (int)(numberOfVehicles * 0.2);

	const unsigned int numVehicles = numberOfVehicles - (numTrucks + numBusses + numBicycles);

	for (int i = 0; i < numVehicles; ++i) {
		Vehicle* vehicle = new Vehicle();
		vehicle->setNumber(generateRandomCarNumber());

		vehicle->setSpeed(rand() % 31 + 50);
		vehicle->setGasLevel((float)(rand() % 81 + 20) / 100);
		vehicle->setGasCapacity(rand() % 11 + 10);
		unsigned int random = rand() % 9 + 1;
		if (getPointById(random).point->getCurrTakenSlots() < getPointById(random).point->getNumberOfSlots()) {
			vehicle->setCurrentPoint(random);
			++(*getPointById(random).point);
		}
		

		allVehicles.vehicles.push_back(vehicle);
	}

	for (int i = 0; i < numTrucks; ++i) {
		Truck* truck = new Truck();

		truck->setNumber(generateRandomCarNumber());
		truck->setSpeed(rand() % 31 + 30);
		truck->setGasLevel((float)(rand() % 81 + 20) / 100);
		truck->setGasCapacity(rand() % 11 + 10);
		unsigned int random = rand() % 9 + 1;
		if (getPointById(random).point->getCurrTakenSlots() < getPointById(random).point->getNumberOfSlots()) {
			truck->setCurrentPoint(random);
			++(*getPointById(random).point);
		}

		truck->setMaxMassOfCargo((float)(rand() % 16 + 5));
		float currMassCoef = (float) (rand() % 101) / 100;
		truck->setCurrMassOfCargo(truck->getMaxMassOfCargo() * currMassCoef);

		allVehicles.trucks.push_back(truck);
	}

	for (int i = 0; i < numBusses; ++i) {
		Bus* bus = new Bus();

		bus->setNumber(generateRandomCarNumber());

		bus->setSpeed(rand() % 31 + 30);
		bus->setGasLevel((float)(rand() % 81 + 20) / 100);
		bus->setGasCapacity(rand() % 11 + 10);
		bus->setCurrentPoint(1);
		std::vector<int> q = { 2, 4, 5, 7, 8 };
		bus->setRoute(q);

		bus->setMaxNumberOfPassengers(rand() % 20 + 20);
		float currPassNumberCoef = (float) (rand() % 101) / 100;
		bus->setCurrNumberOfPassengers(bus->getMaxNumberOfPassengers() * currPassNumberCoef);

		allVehicles.busses.push_back(bus);
	}

	for (int i = 0; i < numBicycles; ++i) {
		Bicycle* bicycle = new Bicycle();

		bicycle->setNumber(generateRandomBicycleNumber());
		unsigned int random = rand() % 9 + 1;
		if (getPointById(random).point->getCurrTakenSlots() < getPointById(random).point->getNumberOfSlots()) {
			bicycle->setCurrentPoint(random);
			++(*getPointById(random).point);
		}

		bicycle->setSpeed(rand() % 11 + 10);
		bicycle->setChanceOfGoingOffRoad((float)(rand() % 81) / 100);
		allVehicles.bicycles.push_back(bicycle);
	}
}

void TransportManager::setUpPoints() {
	BusStopPoint* point1 = new BusStopPoint(rand() % 10, BusStop, 1, 2, 0);
	EntertainmentPoint* point2 = new EntertainmentPoint(5, Entertainment, 2, 5, 0);
	GasStationPoint* point3 = new GasStationPoint(0.5, GasStation, 3, 5, 0);
	BusStopPoint* point4 = new BusStopPoint(rand() % 10, BusStop, 4, 5, 0);
	EntertainmentPoint* point5 = new EntertainmentPoint(5, Entertainment, 5, 5, 0);
	WarehousePoint* point6 = new WarehousePoint(8.2, Warehouse, 6, 5, 0);
	WarehousePoint* point7 = new WarehousePoint(4.5, Warehouse, 7, 5, 0);
	BusStopPoint* point8 = new BusStopPoint(rand() % 10, BusStop, 8, 5, 0);
	EntertainmentPoint* point9 = new EntertainmentPoint(5, Entertainment, 9, 5, 0);
	EntertainmentPoint* point10 = new EntertainmentPoint(5, Entertainment, 10, 5, 0);

	allPoints.entertainments.push_back(point2);
	allPoints.entertainments.push_back(point5);
	allPoints.entertainments.push_back(point9);
	allPoints.entertainments.push_back(point10);

	allPoints.busStops.push_back(point1);
	allPoints.busStops.push_back(point4);
	allPoints.busStops.push_back(point8);

	allPoints.gasStations.push_back(point3);

	allPoints.warehouses.push_back(point6);
	allPoints.warehouses.push_back(point7);
}

void TransportManager::setUpSimulation() {
	setUpPoints();
	setUpRandomVehicleStats();
};

void TransportManager::inputData() {
	std::cout << "Number of vehicles > ";
	std::cin >> numberOfVehicles;

	char ans;
	std::cout << "Enter the map? (Y/n) > ";
	std::cin >> ans;

	if (ans == 'Y') {
		unsigned int size;
		std::cout << "Size of your map (matrix) > ";
		std::cin >> size;

		unsigned int temp;
		std::vector<std::vector<unsigned int>> temp_map(size, std::vector<unsigned int>(size, 0));
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				std::cout << "[" << i << "][" << j << "]\n";
				std::cin >> temp;
				temp_map[i][j] = temp;
			}
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

Points TransportManager::getPoints() const {
	return allPoints;
}


// Setters
void TransportManager::setNumberOfVehicles(unsigned int _numberOfVehicles) {
	numberOfVehicles = _numberOfVehicles;
};

void TransportManager::setMap(const Map& _map) {
	map = _map;
}

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

void TransportManager::addEntertainment(EntertainmentPoint* _point) {
	allPoints.entertainments.push_back(_point);
}

void TransportManager::addGasStation(GasStationPoint* _point) {
	allPoints.gasStations.push_back(_point);
}

void TransportManager::addBusStop(BusStopPoint* _point) {
	allPoints.busStops.push_back(_point);
}

void TransportManager::addWarehouse(WarehousePoint* _point) {
	allPoints.warehouses.push_back(_point);
}

TransportManager::TransportManager() 
	: numberOfVehicles(0),
	  map(Map()),
	  allVehicles(),
	  allPoints()
{}

ReturnPoint TransportManager::getPointById(unsigned int _id) {
	ReturnPoint ret;

	for (auto& pointEnt : allPoints.entertainments) {
		if (pointEnt->getId() == _id) {
			ret.point = pointEnt;
			ret.entertainment = pointEnt;
			ret.type = pointEnt->getType();
			ret.durationOfStop = pointEnt->getDurationOfStop();
			return ret;
		}
	}

	for (auto& pointGas : allPoints.gasStations) {
		if (pointGas->getId() == _id) {
			ret.point = pointGas;
			ret.gasStation = pointGas;
			ret.type = pointGas->getType();
			ret.refuellingCoef = pointGas->getRefuellingSpeedCoef();
			return ret;
		}
	}

	for (auto& pointBus : allPoints.busStops) {
		if (pointBus->getId() == _id) {
			ret.point = pointBus;
			ret.busStop = pointBus;
			ret.type = pointBus->getType();
			ret.numberOfPassengers = pointBus->getNumberOfPassengers();
			return ret;
		}
	}

	for (auto& pointWarehouse : allPoints.warehouses) {
		if (pointWarehouse->getId() == _id) {
			ret.point = pointWarehouse;
			ret.warehouse = pointWarehouse;
			ret.type = pointWarehouse->getType();
			ret.massOfCargo = pointWarehouse->getMassOfCargo();
			return ret;
		}
	}
}