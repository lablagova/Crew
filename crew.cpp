#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "pirate.h"
#include "crew.h"

using namespace std;

Crew::Crew (string name, Pirate captain)
    : name(name), captain(captain)
        {
            if (name.empty())
                throw runtime_error("is empty");
        }
void Crew::add_member(const Pirate& p)
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

int Crew::total_bounty() const
{   
    int sum = 0;
    sum += captain.get_bounty() * 2;

    for (int i = 0; i < members.size(); ++i)
    {
        sum += members[i].get_bounty();
    }
    return sum;
}

ostream& operator<< (ostream& o, const Crew& c)
{
    o << "[" << c.name << ", " << c.captain << ", "  <<  "{";
    for (int i = 0; i < c.members.size(); ++i)
            {
                o << c.members[i];
                if (i + 1 < c.members.size())
                    o << ", ";
            }
    o << "}";
    o << ", " << c.total_bounty() << "]";
    return o; 
}