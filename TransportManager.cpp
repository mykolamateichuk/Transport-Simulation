#include "TransportManager.h"

TransportManager::TransportManager() {
    this->numberOfVehicles = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            Map[i][j] = 0;
        }
    }

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