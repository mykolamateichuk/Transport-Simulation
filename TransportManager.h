#ifndef TRANSPORT_MANAGER
#define TRANSPORT_MANAGER

#include "Map.h"

#include "Vehicle.h"
#include "Road.h"
#include "Point.h"

#include <vector>

class TransportManager {
    private:
        unsigned int numberOfVehicles;          // Number of vehicles in the current simulation run

        Map map;                                // Adjacency matrix of weighted graph that represents simulation map

        vector<Vehicle*> vehicles;              // Array of all the vehicles that are in the current simulation run
        vector<Road*> roads;                    // Array of all the roads that are in the current simulation run
        vector<Point*> points;                  // Array of all the points that are in the current simulation run
        
        // Creating needed number of vehicles and using the map - points and roads 
        // Assigning every subject a needed values, either predetermined or random
        void setUpSimulation();                
    public:
        void inputData();                               // Creates an interface for inputing all the data needed for simulation
        void printStats() const;                        // Prints statistics of every vehicle 
        void simulate();                                // Runs the simulation

        unsigned int getNumberOfVehicles() const;
        vector<vector<unsigned int>> getMap() const;
        vector<Vehicle*> getVehicles() const;
        vector<Road*> getRoads() const;
        vector<Point*> getPoints() const;

        void setNumberOfVehicles(unsigned int); 
        void addVehicle(Vehicle*);                      // Adds an existing vehicle to the array
};

#endif