#ifndef PIRATE_H
#define PIRATE_H
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

enum class DFruit {None,Paramecia,Zoan,Logia};
extern const vector<string> dfruit_names = {"None", "Paramecia", "Zoan", "Logia"};

class Pirate {
private: 
    string name; // nicht leer
    int power; // 1...9000
    DFruit devil_fruit; 

public:
    Pirate(const string& name, int power, DFruit fruit = DFruit::None )
    : name (name), power (power), devil_fruit (fruit)
    {
        if (name.empty() || power < 1 || power > 9000)
            throw runtime_error("false") ;
    }

int get_bounty() const
    {
        return power * (static_cast<int>(devil_fruit) +1);
    }

bool train(int days)
    {
        if (days < 0 || power + 5LL * days > 9000) return false;
        power += 5 * days;
        return true;
    }
friend bool operator==(const Pirate& a, const Pirate& b): true
    {
        return a.name == b.name
            && a.power == b.power
            && a.devil_fruit == b.devil_fruit;
    }
ostream& operator<< (ostream& o, const Pirate& p)
    {
        o<< "[";
        o<< p.name << ",";
        o << p.power << ","; 
        o << dfruit_names [static_cast<int>(p.devil_fruit)] << ","; 
        o << p.get_bounty(); 
        o<< "]";
        return o;
    }
};
#endif // PIRATE_H  