#ifndef TRANSPORT_MANAGER
#define TRANSPORT_MANAGER

#include "Map.h"

#include "Vehicle.h"
#include "Road.h"
#include "Point.h"

#include <vector>

class TransportManager {
    private:
        // Current number of vehicles in the run
        unsigned int numberOfVehicles;

        // Map of the run represented by weighted graph
        Map map;                                        

        // Vectors for storing current vehicles, roads and points that are currently in the run
        vector<Vehicle*> vehicles;                      
        vector<Road*> roads;                            
        vector<Point*> points;                          
        
        void setUpSimulation(unsigned int, const Map&);                
    public:
        // Method to create the interface for inputting data for the next simulational run
        void inputData();
        // Method to print current run stats into the console
        void printStats() const;                        
        // Method to start simulation
        void simulate();                                

        // Getters
        unsigned int getNumberOfVehicles() const;
        vector<vector<unsigned int>> getMap() const;
        vector<Vehicle*> getVehicles() const;
        vector<Road*> getRoads() const;
        vector<Point*> getPoints() const;

        // Setters
        void setNumberOfVehicles(unsigned int);
        void setMap(const Map&);

        // Adders
        void addVehicle(Vehicle*);                      
        void addRoad(Road*);                            
        void addPoint(Point*);                          
};

#endif