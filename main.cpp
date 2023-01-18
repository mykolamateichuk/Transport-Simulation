#include <iostream>
#include "windows.h"
#include "TransportManager.h"


int main() {
    srand(time(nullptr));
    system("cls");

    TransportManager manager;
    Navigator navigator;
    std::vector<std::vector<unsigned int>> map = { {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                                                   {1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                                                   {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                                                   {0, 1, 1, 0, 1, 0, 0, 0, 0, 0},
                                                   {0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
                                                   {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                                                   {0, 0, 0, 0, 1, 0, 0, 1, 1, 0},
                                                   {0, 0, 0, 0, 0, 1, 1, 0, 0, 1},
                                                   {0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                                                   {0, 0, 0, 0, 0, 0, 0, 1, 1, 0} };

    manager.setMap(map);
    navigator = Navigator(map);
    manager.setNumberOfVehicles(5);

    manager.setUpSimulation();

    bool process = true;
    char chr;

    for (auto& vehicle : manager.getVehicles().vehicles) {
        vehicle->setNavigator(&navigator);
        vehicle->setRoute(vehicle->getNavigator()->findRoute(vehicle->getCurrentPoint(), rand() % 10));
    }

    for (auto& vehicle : manager.getVehicles().trucks) {
        vehicle->setNavigator(&navigator);
        vehicle->setRoute(vehicle->getNavigator()->findRoute(vehicle->getCurrentPoint(), rand() % 10));
    }

    for (auto& vehicle : manager.getVehicles().busses) {
        vehicle->setNavigator(&navigator);
        vehicle->setRoute(vehicle->getNavigator()->findRoute(vehicle->getCurrentPoint(), 0));
    }

    for (auto& vehicle : manager.getVehicles().bicycles) {
        vehicle->setNavigator(&navigator);
        vehicle->setRoute(vehicle->getNavigator()->findRoute(vehicle->getCurrentPoint(), rand() % 10));
    }
    
    while (process) {

        std::cout << "\n\n\n\n\n";

        manager.printAllVehicles();
        for (auto& vehicle : manager.getVehicles().vehicles) {
            if (vehicle->getRoute().size() == 0) {
                switch (vehicle->getCurrentPoint()) {
                    case 2:
                    case 5:
                    case 9:
                    case 10:
                        if (vehicle->getStopCount() >= 5) {
                            vehicle->setCanMove(true);
                            vehicle->setStopCount(0);
                            break;
                        };
                        vehicle->setCanMove(false);
                        vehicle->setStopCount(vehicle->getStopCount() + 1);
                        break;
                    case 3:
                        vehicle->setGasLevel(1);
                        break;
                    default:
                        break;
                }
            }
            vehicle->update(0.05);
        }

        for (auto& truck : manager.getVehicles().trucks) {
            if (truck->getRoute().size() == 0) {
                float mass;
                switch (truck->getCurrentPoint()) {
                    case 2:
                    case 5:
                    case 9:
                    case 10:
                        if (truck->getStopCount() >= 2) {
                            truck->setCanMove(true);
                            truck->setStopCount(0);
                            truck->setCurrMassOfCargo(truck->getCurrMassOfCargo() - 1);
                            break;
                        };
                        truck->setCanMove(false);
                        truck->setStopCount(truck->getStopCount() + 1);
                        break;
                    case 6:
                    case 7:
                        mass = manager.getPointById(truck->getCurrentPoint()).massOfCargo;
                        manager.getPointById(truck->getCurrentPoint()).warehouse->setMassOfCargo(truck->getCurrMassOfCargo());
                        truck->setCurrMassOfCargo(mass);
                        break;
                    case 3:
                        truck->setGasLevel(1);
                        break;
                    default:
                        break;
                }
            }
            truck->update(0.09);
        }

        for (auto& bus : manager.getVehicles().busses) {
            unsigned int passengersIn;
            unsigned int passengersOut;
            switch (bus->getCurrentPoint()) {
                case 1:
                case 4:
                case 8:
                    if (bus->getCurrNumberOfPassengers() != 0) {
                        passengersOut = rand() % bus->getCurrNumberOfPassengers();
                    }
                    else {
                        passengersOut = 0;
                    }
                    bus->setCurrNumberOfPassengers(bus->getCurrNumberOfPassengers() - passengersOut);
                    if (manager.getPointById(bus->getCurrentPoint()).numberOfPassengers != 0) {
                        passengersIn = rand() % manager.getPointById(bus->getCurrentPoint()).numberOfPassengers;
                    }
                    else {
                        passengersIn = 0;
                    }
                    if (bus->getMaxNumberOfPassengers() >= bus->getCurrNumberOfPassengers() + passengersIn) {
                        bus->setCurrNumberOfPassengers(bus->getCurrNumberOfPassengers() + passengersIn);
                    }
                    else {
                        bus->setCurrNumberOfPassengers(bus->getCurrNumberOfPassengers() + (bus->getMaxNumberOfPassengers() - (bus->getCurrNumberOfPassengers() + passengersIn)));
                    }
                    break;
                case 3:
                    bus->setGasLevel(1);
                    break;
                default:
                    break;
            }
            bus->update(0.07);
        }

        for (auto& bicycle : manager.getVehicles().bicycles) {
            if (bicycle->getRoute().size() == 0) {
                switch (bicycle->getCurrentPoint()) {
                    case 2:
                    case 5:
                    case 9:
                    case 10:
                        if (bicycle->getStopCount() >= 5) {
                            bicycle->setCanMove(true);
                            bicycle->setStopCount(0);
                            break;
                        };
                        bicycle->setCanMove(false);
                        bicycle->setStopCount(bicycle->getStopCount() + 1);
                        break;
                    default:
                        break;
                }
            }
            bicycle->update();
        }


        std::cout << "Press any key to continue or 'x' to exit...";
        std::cin >> chr;
        if (chr == 'x') {
            process = false;
        }
    }
   
    //system("pause");
    return 0;
}