#include "pirate.h"
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

Pirate::Pirate (string name, int power, DFruit devil_fruit)
        {
            if (name.empty())
                throw(runtime_error("is empty"));
            if (power < 0 || power > 9000)
                throw(runtime_error("power is invalid"));
        }

int Pirate::get_bounty() const
{
    int money;
    money = power * (static_cast<int>(devil_fruit) + 1);
    return money;
}

bool Pirate::train(int days)
{  
    if (days < 0)
        return false;
    power += days * 5;
    if (power > 9000)
        return false;
    return true;
}

bool Pirate::operator==(const Pirate& p) const
{
    if (name == p.name && power == p.power && devil_fruit == p.devil_fruit)
        return true;
    return false;
}

ostream& operator<< (ostream& o, const Pirate& p)
{
    string fruitname;
    switch (static_cast<int>(p.devil_fruit))
{
        case 0:
            fruitname = "None" ; break; 
        case 1:
            fruitname = "Paramecia";  break; 
        case 2:
            fruitname = "Zoan"; break; 
        case 3:
            fruitname = "Logia"; break; 
}
    o<< "[" << p.name << "," << p.power << "," << fruitname << "," << p.get_bounty() << "]";
    return o;
}

