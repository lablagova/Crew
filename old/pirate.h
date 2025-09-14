#ifndef PIRATE_H
#define PIRATE_H
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

enum class DFruit {None,Paramecia,Zoan,Logia};
extern const vector<string> dfruit_names = {"None", "Paramecia", "Zoan", "Logia"};

class Pirate
{
private: 
    string name; // nicht leer
    int power; // 1...9000
    DFruit devil_fruit; 

public:
    Pirate(const string& name, int power, DFruit fruit = DFruit::None )
    : name (name), power (power), devil_fruit (fruit)
};
#endif // PIRATE_H