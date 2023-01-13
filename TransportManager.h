#ifndef TRANSPORT_MANAGER
#define TRANSPORT_MANAGER

#include "Map.h"

#include "Vehicle.h"
#include "Road.h"
#include "Point.h"

#include <vector>
#include <unordered_map>

struct Vehicles {
    std::vector<Vehicle*> vehicles;
    std::vector<Bus*> busses;
    std::vector<Truck*> trucks;
    std::vector<Bicycle*> bicycles;
};

struct Points {
    std::vector<EntertainmentPoint*> entertainments;
    std::vector<GasStationPoint*> gasStations;
    std::vector<BusStopPoint*> busStops;
    std::vector<ParkingPoint*> parkings;
    std::vector<WarehousePoint*> warehouses;
};

class TransportManager {
    private:
        // Current number of vehicles in the run
        unsigned int numberOfVehicles;

        // Map of the run represented by weighted graph
        Map map;                                        

        // Structures for storing current vehicles, roads and points that are currently in the run
        Vehicles allVehicles;
        std::vector<Road*> roads;                            
        Points allPoints;
        

        void setUpRandomVehicleStats();
        void setUpRoads();
        void setUpPoints();

        void setUpSimulation();
    public:
        // Method to create the interface for inputting data for the next simulational run
        void inputData();
        // Method to print current run stats into the console
        void printStats() const;                        
        // Method to start simulation
        void simulate();                                

        // Getters
        unsigned int getNumberOfVehicles() const;
        std::vector<std::vector<unsigned int>> getMap() const;
        Vehicles getVehicles() const;
        std::vector<Road*> getRoads() const;
        Points getPoints() const;

        // Setters
        void setNumberOfVehicles(unsigned int);
        void setMap(const Map&);

        // Adders
        void addVehicle(Vehicle*);
        void addBus(Bus*);
        void addTruck(Truck*);
        void addBicycle(Bicycle*);

        void addRoad(Road*);                            
        
        void addEntertainment(EntertainmentPoint*);
        void addGasStation(GasStationPoint*);
        void addBusStop(BusStopPoint*);
        void addParking(ParkingPoint*);
        void addWarehouse(WarehousePoint*);
};

#endif