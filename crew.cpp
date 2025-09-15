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
void add_member(const Pirate& p)
{
    if (p == captain)
        throw runtime_error("captain is there");
    for (int i = 0; i < members.size(); ++i)
    {
        if (p == members[i])
            throw runtime_error("this member is there");
    }
    members.push_back(p);
}

int total_bounty() const
{


}

ostream& operator<< (ostream o, const Crew& c)
{
    o << "[" << c.name << "," << c.captain << "," << "list of members"  << "," << c.get_bounty() << "]"; 
    return o; 
}