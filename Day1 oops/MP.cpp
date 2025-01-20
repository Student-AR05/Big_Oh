// Task 1 :
// Write a program to depict Indian Politics.
// Consider the politics use cases :
// MP: is a person who won from a constituency
// getConstituency - return their winning constituency.
// getDriver - returns the driver assigned for their vehicle (default car).
// exceedsSpendingLimit - returns true or false if Mps exceeds to their spending limit.
// PM->Ministers->MP (All of them are MPS) - PM has special permissions such as it can give permission to arrest any minister.
// PM enjoys special benefits such as Aircraft (along with car) and its designated driver.
// Note: PM spending limit : 1 crore, Ministers: 10 lakhs, MP: 1 lakh.
// Need to design in a way  where Commisioner class can arrest MP, Ministers and PM when their expense exceeds their spending limit:
// canArrest - can arrest one or many MP.
//           Note: If PM  cant arrest.
//                 If minister can arrest with PM permission
//                 if mps they can be arrested without anyones permission.
// In Short, If the MP is not PM then he can be arrested by commisoner , If he is minister then can be arrested with PMs permisison.

#include <iostream>
#include <string>
using namespace std;

// Base class MP
class MP
{
protected:
    string name;
    string constituency;
    double spending_limit;
    double spending;
    string vehicle;
    string driver;

public:
    virtual string getRole() { return "MP"; } // Added virtual getRole()

    void setDetails(string mp_name, string mp_constituency, double mp_spending_limit = 1e5)
    {
        name = mp_name;
        constituency = mp_constituency;
        spending_limit = mp_spending_limit;
        spending = 0;
        vehicle = "Car";
        driver = "Default Driver";
    }

    string getConstituency()
    {
        return constituency;
    }

    string getDriver()
    {
        return driver;
    }

    bool exceedsSpendingLimit()
    {
        return spending > spending_limit;
    }

    void spend(double amount)
    {
        spending += amount;
    }

    string getName()
    {
        return name;
    }
};

// Derived class Minister
class Minister : public MP
{
public:
    virtual string getRole() override { return "Minister"; } // Overridden getRole()

    void setDetails(string minister_name, string minister_constituency, double minister_spending_limit = 1e6)
    {
        MP::setDetails(minister_name, minister_constituency, minister_spending_limit);
    }
};

// Derived class PM
class PM : public Minister
{
public:
    virtual string getRole() override { return "PM"; } // Overridden getRole()

    void setDetails(string pm_name, string pm_constituency, double pm_spending_limit = 1e7)
    {
        Minister::setDetails(pm_name, pm_constituency, pm_spending_limit);
        vehicle = "Car and Aircraft";
    }

    bool givePermission()
    {
        return true; // PM can give permission to arrest Ministers
    }
};

// Commissioner class
// Independent comissioner class  from above mentioned classes
class Commissioner
{
public:
    void canArrest(MP *mp, bool pmPermission = false)
    {
        if (mp->getRole() == "PM")
        { // If MP is PM
            cout << "Cannot arrest. " << endl;
        }
        else if (mp->getRole() == "Minister" && mp->exceedsSpendingLimit() && pmPermission)
        {
            // If MP is a minister and he has exceeded spending limit and PM has given arrest Permission
            cout << "Minister " << mp->getConstituency() << " arrested with PM permission." << endl;
        }
        else if (mp->getRole() == "MP" && mp->exceedsSpendingLimit())
        {
            // If HE/SHE is just MP and has exceeded spending limit we comissioner do not need
            // PM's permission to arrest him.
            cout << "MP " << mp->getConstituency() << " arrested." << endl;
        }
        else
        {
            // If the entered role is not MP, PM or a MINISTER
            cout << "Invalid Role or Spending Limit Not Exceeded" << endl;
        }
    }
};

// Main function
int main()
{
    MP mp;
    mp.setDetails("Amit", "District A");

    Minister minister;
    minister.setDetails("Nitin", "District B");

    PM pm;
    pm.setDetails("Narendra Modi", "Nationwide");

    Commissioner commissioner;

    // Spending
    mp.spend(120000);
    minister.spend(1200000);
    pm.spend(12000000);

    // Check spending limits
    cout << "MP " << mp.getName() << " exceeds limit? " << (mp.exceedsSpendingLimit() ? "Yes" : "No") << endl;
    cout << "Minister " << minister.getName() << " exceeds limit? " << (minister.exceedsSpendingLimit() ? "Yes" : "No") << endl;
    cout << "PM " << pm.getName() << " exceeds limit? " << (pm.exceedsSpendingLimit() ? "Yes" : "No") << endl;

    // Arrest scenarios
    commissioner.canArrest(&mp);             // Arrest MP
    commissioner.canArrest(&minister);       // Attempt to arrest Minister without PM's permission
    commissioner.canArrest(&minister, true); // Arrest Minister with PM's permission
    commissioner.canArrest(&pm);             // Attempt to arrest PM

    return 0;
}