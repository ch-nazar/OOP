#include "Hardware.h"

Device::Device() : brand("Unknown"), model("Unknown") {}

Device::Device(std::string b, std::string m) : brand(b), model(m) {}

void Device::TurnOn() {
    std::cout << "[Device] Пристрій " << brand << " " << model << " вмикається..." << std::endl;
}

void Device::PrintInfo() {
    std::cout << "Пристрій: " << brand << " " << model << std::endl;
}

void Device::SetInfo(std::string b) {
    brand = b;
}

void Device::SetInfo(std::string b, std::string m) {
    brand = b;
    model = m;
}

PCComponent::PCComponent(std::string b, std::string m, std::string ff) 
    : Device(b, m), formFactor(ff) {}

void PCComponent::TurnOn() {
    std::cout << "[PC Component] Подача живлення на компонент (" << formFactor << ")..." << std::endl;
}

void PCComponent::PrintInfo() {
    std::cout << "Комплектуюча: " << brand << " " << model << " (Форм-фактор: " << formFactor << ")" << std::endl;
}

Motherboard::Motherboard(std::string b, std::string m, std::string ff, std::string cs) 
    : PCComponent(b, m, ff), chipset(cs) {}

void Motherboard::TurnOn() {
    std::cout << "[Motherboard] Ініціалізація чипсету " << chipset << ". Запуск POST..." << std::endl;
}

void Motherboard::PrintInfo() {
    std::cout << "Материнська плата: " << brand << " " << model 
              << " | Чипсет: " << chipset << " | Форм-фактор: " << formFactor << std::endl;
}

Peripheral::Peripheral(std::string b, std::string m, std::string conn) 
    : Device(b, m), connectionType(conn) {}

void Peripheral::TurnOn() {
    std::cout << "[Peripheral] Підключення периферії через " << connectionType << "..." << std::endl;
}

void Peripheral::PrintInfo() {
    std::cout << "Периферія: " << brand << " " << model << " (Підключення: " << connectionType << ")" << std::endl;
}

Monitor::Monitor(std::string b, std::string m, std::string conn, int hz) 
    : Peripheral(b, m, conn), refreshRate(hz) {}

void Monitor::TurnOn() {
    std::cout << "[Monitor] Виведення зображення. Частота оновлення: " << refreshRate << "Hz." << std::endl;
}

void Monitor::PrintInfo() {
    std::cout << "Монітор: " << brand << " " << model 
              << " | Підключення: " << connectionType << " | " << refreshRate << "Hz" << std::endl;
}

IEM::IEM(std::string b, std::string m, std::string conn, int drivers) 
    : Peripheral(b, m, conn), driverCount(drivers) {}

void IEM::TurnOn() {
    std::cout << "[IEM Audio] Відтворення звуку. Задіяно драйверів: " << driverCount << "." << std::endl;
}

void IEM::PrintInfo() {
    std::cout << "IEM Навушники: " << brand << " " << model 
              << " | Кабель: " << connectionType << " | К-ть драйверів: " << driverCount << std::endl;
}