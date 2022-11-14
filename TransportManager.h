#ifndef TRANSPORT_MANAGER
#define TRANSPORT_MANAGER

#include "Vehicle.h"
#include <vector>

class TransportManager {
    private:
        unsigned int numberOfVehicles;          // Number of vehicles in the current simulation run

        vector<vector<unsigned int>> map;       // Adjacency matrix of weighted graph that represents simulation map

        vector<Vehicle*> vehicles;              // Array of all the vehicles that are in the current simulation run
        // Road* roads;
        // Point* points;


        
        // Creating needed number of vehicles and using the map - points and roads 
        // Assigning every subject a needed values, either predetermined or random
        void setUpSimulation();                
    public:
        TransportManager();

        
        void inputData();                       // Creates an interface for inputing all the data needed for simulation
        void printStats();                      // Prints statistics of every vehicle 
        void simulate();                        // Runs the simulation

        unsigned int getNumberOfVehicles();
        vector<vector<unsigned int>> getMap();
        vector<Vehicle*> getVehicles();
        //Road* getRoads();
        //Point* getPoints();

        void setNumberOfVehicles(unsigned int); 
        void addVehicle(Vehicle*);              // Adds an existing vehicle to the array
        
       
        ~TransportManager();
};

#endif