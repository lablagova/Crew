#ifndef PIRATE_H
#define PIRATE_H
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

enum class DFruit {None,Paramecia,Zoan,Logia};
const vector<std::string> dfruit_names = {"None", "Paramecia", "Zoan", "Logia"};

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
};


#endif // PIRATE_H  