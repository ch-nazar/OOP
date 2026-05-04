#include <iostream>
#include "Hardware.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Device* myMobo = new Motherboard("ASUS", "TUF GAMING B450M-PRO II", "Micro-ATX", "B450");
    Device* myMonitor = new Monitor("BenQ", "ZOWIE XL2411K", "DisplayPort", 144);
    Device* myIEMs = new IEM("Simgot", "EM6L", "3.5mm Jack", 4);

    std::cout << "--- Ініціалізація системи ---" << std::endl;
    
    myMobo->PrintInfo();
    myMobo->TurnOn();
    std::cout << "---------------------------" << std::endl;

    myMonitor->PrintInfo();
    myMonitor->TurnOn();
    std::cout << "---------------------------" << std::endl;

    myIEMs->PrintInfo();
    myIEMs->TurnOn();
    std::cout << "---------------------------" << std::endl;

    std::cout << "\n--- Тест перевантаження методів ---" << std::endl;
    Device genericDevice;
    
    genericDevice.SetInfo("Logitech");
    genericDevice.PrintInfo();
    
    genericDevice.SetInfo("Logitech", "G Pro Superlight");
    genericDevice.PrintInfo();

    delete myMobo;
    delete myMonitor;
    delete myIEMs;

    return 0;
}