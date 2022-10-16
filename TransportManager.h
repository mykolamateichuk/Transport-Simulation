#ifndef TRANSPORT_MANAGER
#define TRANSPORT_MANAGER

class TransportManager {
    private:
        /*
            ...
        */
    public:
        unsigned int numberOfVehicles;
        // Vehicle* allVehicles;

        unsigned int **Map;
        // Road* roads;
        // Point* points;

        TransportManager();

        /*
        void inputData();
        void setUpSimulation();
        void addVehicle();
        void editMap();
        void printStats();
        void simulate();
        */

        ~TransportManager();
};

#endif