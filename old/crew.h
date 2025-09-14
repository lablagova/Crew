#ifndef CREW_H
#define CREW_H
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "pirate.h"

using namespace std;

class Crew 
{

private:
   string name; // nicht leer
   Pirate captain;
   vector<Pirate>members;

public:
    Crew(const string& name, const Pirate captain)
    :name (name), captain (captain)
};
#endif // CREW_H
