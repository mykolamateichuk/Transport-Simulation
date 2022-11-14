/*#include <iostream>
#include <windows.h>

#include "Vehicle.cpp"

#define TIMEOUT 100

using namespace std;

void print_route(queue<int> route)
{
    while (!route.empty())
    {
        cout << route.front() << " ";
        route.pop();
    }
}

void print_vehicle(Vehicle vehicle)
{
    cout << "Номер: " << vehicle.getNumber() << endl;
    cout << "Position: " << vehicle.getPosition() << endl;
    cout << "Appointment: " << vehicle.getAppointment() << endl;
    cout << "Відстань: " << vehicle.getAppointment() << endl;
    cout << "Маршрут: ";
    print_route(vehicle.getRoute());
    cout << endl;
    cout << "Ємність баку: " << vehicle.getGasCapacity() << endl;
    cout << "Паливо: " << vehicle.getGasLevel() << endl;
    cout << "Швидкість: " << vehicle.getSpeed() << endl;
}

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    srand(time(NULL));
    system("cls");

    vector<vector<int>> map = {{0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                               {1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                               {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                               {0, 1, 1, 0, 1, 0, 0, 0, 0, 0},
                               {0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
                               {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                               {0, 0, 0, 0, 1, 0, 0, 1, 1, 0},
                               {0, 0, 0, 0, 0, 1, 1, 0, 0, 1},
                               {0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                               {0, 0, 0, 0, 0, 0, 0, 1, 1, 0}};

    Navigator *navigator = new Navigator(map);

    Vehicle bus = Vehicle("CD9582BK", 40, 200, 120, 10, navigator);
    bus.addAppointment(3);
    bus.addAppointment(1);

    while (true)
    {
        system("cls");

        print_vehicle(bus);

        bus.update();

        if (bus.getGasLevel() <= bus.getGasCapacity() / 10)
            bus.refuel();

        Sleep(TIMEOUT);
    }

    return 0;
}
*/