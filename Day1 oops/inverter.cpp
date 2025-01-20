// Task 2:
// suppose you are making a program for a very famous IoT Inverter company,
// company have multiple inverters with multiple business logic,
// use cases:
// company have PCU, GTI, Zelio, Regalia, iCruze Inverters,
// All Inverters have Power rating which is determined by ( Current * Operating Voltage )
// Only PCU, GTI and Regalia are solar Inverters other are not (solar inverters get charge by solar panels and solar energy),
// Solar Inverters have Solar Panels also
// Solar Inverters further have two option one Battery version that whatever energy is produced will be stored in battery other will not store any energy,
// so PCU comes with battery but GTI have no battery,
// Solar Inverter also have GRID On , system where you can sell your extra energy back, GTI is GRID On where as this feature is not available in PCU,
// Non Solar Inverters are Simple Home Inverters Which have a Battery,"

#include <iostream>
#include <string>
using namespace std;

// Base class for all Inverters
class Inverter
{
protected:
    string name;
    double current;          // In Amperes
    double operatingVoltage; // In Volts

public:
    void setDetails(string inverter_name, double inverter_current, double inverter_voltage)
    {
        this->name = inverter_name;
        this->current = inverter_current;
        this->operatingVoltage = inverter_voltage;
    }

    double getPowerRating() const
    {
        return current * operatingVoltage; // Power = Current * Voltage
    }

    string getName() const
    {
        return name;
    }

    virtual void displayFeatures() {};
};

// Solar Inverter class (Derived from Inverter)
class SolarInverter : public Inverter
{
protected:
    bool hasBattery;
    bool gridOn;

public:
    void setSolarFeatures(bool battery, bool grid)
    {
        hasBattery = battery;
        gridOn = grid;
    }

    void displayFeatures() override
    {
        cout << name << " (Solar Inverter):" << endl;
        cout << "Power Rating: " << getPowerRating() << " Watts" << endl;
        cout << "Has Battery: " << (hasBattery ? "Yes" : "No") << endl;
        cout << "Grid On System: " << (gridOn ? "Yes" : "No") << endl;
        cout << endl;
    }
};

// Non-Solar Inverter class (Derived from Inverter)
class NonSolarInverter : public Inverter
{
protected:
    bool hasBattery;

public:
    void setNonSolarFeatures(bool battery)
    {
        hasBattery = battery;
    }

    void displayFeatures() override
    {
        cout << name << " (Non-Solar Inverter):" << endl;
        cout << "Power Rating: " << getPowerRating() << " Watts" << endl;
        cout << "Has Battery: " << (hasBattery ? "Yes" : "No") << endl;
        cout << endl;
    }
};

// Specific Inverter Classes
class PCU : public SolarInverter
{
public:
    PCU()
    {
        name = "PCU";
        hasBattery = true;
        gridOn = false; // PCU is not Grid On
    }
};

class GTI : public SolarInverter
{
public:
    GTI()
    {
        name = "GTI";
        hasBattery = false;
        gridOn = true; // GTI is Grid On
    }
};

class Regalia : public SolarInverter
{
public:
    Regalia()
    {
        name = "Regalia";
        hasBattery = false; // Assuming Regalia has no battery by default
        gridOn = false;     // Assuming Regalia is not Grid On
    }
};

class Zelio : public NonSolarInverter
{
public:
    Zelio()
    {
        name = "Zelio";
        hasBattery = true; // Zelio is a simple home inverter with a battery
    }
};

class ICruze : public NonSolarInverter
{
public:
    ICruze()
    {
        name = "iCruze";
        hasBattery = true; // iCruze is a simple home inverter with a battery
    }
};

int main()
{
    // Create and initialize inverters
    PCU pcu;
    pcu.setDetails("PCU", 10, 48); // 10A, 48V

    GTI gti;
    gti.setDetails("GTI", 15, 60); // 15A, 60V

    Regalia regalia;
    regalia.setDetails("Regalia", 20, 50); // 20A, 50V

    Zelio zelio;
    zelio.setDetails("Zelio", 5, 24); // 5A, 24V

    ICruze icruze;
    icruze.setDetails("iCruze", 8, 36); // 8A, 36V

    // Display inverter details
    pcu.displayFeatures();
    gti.displayFeatures();
    regalia.displayFeatures();
    zelio.displayFeatures();
    icruze.displayFeatures();

    return 0;
}
