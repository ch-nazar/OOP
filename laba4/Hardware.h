#ifndef HARDWARE_H
#define HARDWARE_H

#include <iostream>
#include <string>

class Device {
protected:
    std::string brand;
    std::string model;

public:
    Device();
    Device(std::string b, std::string m);
    virtual ~Device() {}

    virtual void TurnOn();
    virtual void PrintInfo();

    void SetInfo(std::string b);
    void SetInfo(std::string b, std::string m);
};

class PCComponent : public Device {
protected:
    std::string formFactor;

public:
    PCComponent(std::string b, std::string m, std::string ff);
    void TurnOn() override;
    void PrintInfo() override;
};

class Motherboard : public PCComponent {
private:
    std::string chipset;

public:
    Motherboard(std::string b, std::string m, std::string ff, std::string cs);
    void TurnOn() override;
    void PrintInfo() override;
};

class Peripheral : public Device {
protected:
    std::string connectionType;

public:
    Peripheral(std::string b, std::string m, std::string conn);
    void TurnOn() override;
    void PrintInfo() override;
};

class Monitor : public Peripheral {
private:
    int refreshRate;

public:
    Monitor(std::string b, std::string m, std::string conn, int hz);
    void TurnOn() override;
    void PrintInfo() override;
};

class IEM : public Peripheral {
private:
    int driverCount;

public:
    IEM(std::string b, std::string m, std::string conn, int drivers);
    void TurnOn() override;
    void PrintInfo() override;
};

#endif