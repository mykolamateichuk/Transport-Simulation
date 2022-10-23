#include <iostream>
#include <windows.h>

#include "Vehicle.cpp"

#define RAND(min, max) (min + rand() % (max + 1 - min))

#define TIMEOUT 100

using namespace std;

void print_vehicle(Vehicle vehicle)
{
    cout << "Номер: " << vehicle.getNumber() << endl;
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

    Navigator* navigator = new Navigator();

    Vehicle car = Vehicle("CB0001AX", 60, 100, 30, new Point(), navigator);
    Vehicle bus = Vehicle("AA9582BK", 40, 200, 120, new Point(), navigator);

    while (true)
    {
        system("cls");

        print_vehicle(car);
        cout << "\n\n";
        print_vehicle(bus);

        car.update();
        bus.update();
        
        if (car.getGasLevel()) car.setSpeed(RAND(40, 100));
        if (bus.getGasLevel() <= bus.getGasCapacity()/10) bus.refuel();

        Sleep(500);
    }

    return 0;
}