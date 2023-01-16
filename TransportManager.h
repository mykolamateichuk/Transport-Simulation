#ifndef TRANSPORT_MANAGER
#define TRANSPORT_MANAGER

#include "Map.h"

#include "Vehicle.h"
#include "Point.h"
#include "Navigator.h"

#include <vector>

struct Vehicles {
    std::vector<Vehicle*> vehicles;
    std::vector<Bus*> busses;
    std::vector<Truck*> trucks;
    std::vector<Bicycle*> bicycles;

    Vehicles();
};

struct Points {
    std::vector<EntertainmentPoint*> entertainments;
    std::vector<GasStationPoint*> gasStations;
    std::vector<BusStopPoint*> busStops;
    std::vector<WarehousePoint*> warehouses;

    Points();
};

class TransportManager {
    private:
        unsigned int numberOfVehicles;

        Map map;                                        

        Vehicles allVehicles;
        Points allPoints;

        void setUpRandomVehicleStats();
        void setUpPoints();

        
    public:
        TransportManager();

        void inputData();                                                    

        void setUpSimulation();

        // Getters
        unsigned int getNumberOfVehicles() const;
        std::vector<std::vector<unsigned int>> getMap() const;
        Vehicles getVehicles() const;
        Points getPoints() const;

        // Setters
        void setNumberOfVehicles(unsigned int);
        void setMap(const Map&);

        // Adders
        void addVehicle(Vehicle*);
        void addBus(Bus*);
        void addTruck(Truck*);
        void addBicycle(Bicycle*);                            
        
        void addEntertainment(EntertainmentPoint*);
        void addGasStation(GasStationPoint*);
        void addBusStop(BusStopPoint*);
        void addWarehouse(WarehousePoint*);

        ReturnPoint getPointById(unsigned int);
        
        void printAllVehicles() const;
        void printAllPoints() const;
};

#endif