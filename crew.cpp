#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "pirate.h"
#include "crew.h"

using namespace std;

Crew (string name, Pirate captain)
        {
            if (name.empty())
                throw runtime_error("is empty");
        }
