#include "TransportManager.h"

TransportManager::TransportManager() {
    this->numberOfVehicles = 0;

    /*
        ...
    */

}

TransportManager::~TransportManager() {
    this->numberOfVehicles = 0;

    delete Map;

    /*
        ...
    */
}

void TransportManager::inputData() {
    cout << "Number of vehicles to simulate: ";
    cin >> numberOfVehicles;

    cout << "Number of points on the map: ";
    cin >> numberOfPoints;

    cout << "Weighted graph representation of the map:" << endl;
    for (int i = 0; i < numberOfPoints; i++) {
        for (int j = 0; j < numberOfPoints; j++) {
            cout << "Map[" << i << "][" << j << "]: ";
            cin >> Map[i][j];
        }
    }
}