#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "pirate.h"
#include "crew.h"

using namespace std;

Crew (const string& name, const Pirate captain)
:name (name), captain (captain)
{
    {
        if (name.empty())
        throw runtime_error("wrong");
    }

void add_member(const Pirate& p)
    {
        if (p == captain)
             throw runtime_error("captain is already there");

        for (int i = 0; i < members.size(); ++i)
        {
            if (members[i] == p)
                throw runtime_error("this member is already there");
        }
        members.push_back(p);
    }

int total_bounty() const
    {
        int sum = 2 * captain.get_bounty();
        for (int i = 0; i < members.size(); ++i)
            {
                sum += members[i].get_bounty();
            }
        return sum;
    }

ostream& operator<< (ostream& o, const Crew& c)
    {
        o<< "[";
        o<< c.name << ", ";
        o<< c.captain << ", ";
        o<< "{";
        for (size_t i {0}; i < c.members.size(); ++i) 
            {
                o<< c.members[i];
                if (i + 1 < c.members.size()) 
                o<< ", "; 
            }
        o<< "}";
        o<< ", " << c.total_bounty();
        o<< "]";
    return o; 
    }
}