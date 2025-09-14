#ifndef CREW_H
#define CREW_H
#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "pirate.h"

using namespace std;

class Crew {

private:
   string name; // nicht leer
   Pirate captain;
   vector<Pirate>members;

public:
    Crew(const string& name, const Pirate captain)
    :name (name), captain (captain)

    {
        if (name.empty())
        throw runtime_error("wrong");
    }

void add member(const Pirate& p)
    {



    }

int total_bounty() const
    {
        int sum = 2 * captain.get_bounty();
        for (size_t i = 0; i < members.size(); ++i)
        {
            sum += members[i].get_bounty();
        }
        return sum;
    }

ostream& operator<< (ostream& o, const Crew& c)
    {
        o<< "[";
        o<< c.name << ",";
        o<< c.captain << ",";
        o<< "{";
        for (size_t i {0}; i < c.members.size(); ++i) 
            {
                o<< c.members[i];
                if (i < (c.members.size() - 1)) 
                o<< ", "; 
            }
        o<< "}";
        o<< c.total_bounty();
        o<< "]";
    return o; 
    }
};
#endif // CREW_H
