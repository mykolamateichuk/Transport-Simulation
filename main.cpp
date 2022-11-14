#include <iostream>
#include "windows.h"
#include "TransportManager.h"

int main() {
    srand(time(NULL));
    system("cls");

    TransportManager manager;

    vector<vector<int>> map = { {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                {1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                                {0, 1, 1, 0, 1, 0, 0, 0, 0, 0},
                                {0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                {0, 0, 0, 0, 1, 0, 0, 1, 1, 0},
                                {0, 0, 0, 0, 0, 1, 1, 0, 0, 1},
                                {0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                                {0, 0, 0, 0, 0, 0, 0, 1, 1, 0} };

    Navigator* navigator = new Navigator(map);


    Vehicle* bus = new Vehicle("CD9582BK", 40, 200, 120, 10, navigator);
    bus->addAppointment(3);
    bus->addAppointment(1);
    
    manager.addVehicle(bus);

    while (true)
    {
        system("cls");

        manager.printStats();

        bus->update();

        if (bus->getGasLevel() <= bus->getGasCapacity() / 10)
            bus->refuel();

        Sleep(500);
    }
    system("pause");
    return 0;
}