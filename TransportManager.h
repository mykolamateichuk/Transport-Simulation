#ifndef TRANSPORT_MANAGER
#define TRANSPORT_MANAGER

#include "Vehicle.h"

class TransportManager {
    private:
        unsigned int numberOfVehicles;
        //unsigned int numberOfPoints;

        unsigned int** map;

        Vehicle* vehicles;
        // Road* roads;
        // Point* points;
    public:
        TransportManager();

        
        void inputData();
        void setUpSimulation();
        void addVehicle();
        void editMap();
        void printStats();
        void simulate();

        unsigned int getNumberOfVehicles();
        unsigned int** getMap();
        Vehicle* getVehicles();
        //Road* getRoads();
        //Point* getPoints();

        void setNumberOfVehicles(unsigned int new_numberOfVehicles);
        void setMap(unsigned int** new_map);
        void setVehicles(Vehicle* new_vehicles);
        //void setRoads(Road* new_roads);
       // void setPoints(Point* new_points);
        

        ~TransportManager();
};

#endif