#ifndef CREW_H
#define CREW_H
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "pirate.h"

using namespace std;

class Crew {
    public:
        Crew (string name, Pirate captain);
        friend ostream& operator<< (ostream o, const Crew& c)


    private:
        string name;
        Pirate captain;
    };

#endif // CREW_H
