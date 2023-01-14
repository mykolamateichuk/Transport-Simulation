#include <iostream>
#include "windows.h"
#include "TransportManager.h"

int main() {
    srand(time(NULL));
    system("cls");

    TransportManager manager;

    manager.inputData();

    for (const auto& row : manager.getMap()) {
        for (const auto& column : row) {
            std::cout << column << "\n";
        }
        std::cout << "\n";
    }

    std::cout << manager.getNumberOfVehicles() << std::endl;
   
    system("pause");
    return 0;
}