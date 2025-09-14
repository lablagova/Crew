#ifndef PIRATE_H
#define PIRATE_H
#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

enum class DFruit {None,Paramecia,Zoan,Logia};
const vector<string> dfruit_names = {"None", "Paramecia", "Zoan", "Logia"};

class Pirate {
    public:
        Pirate (string name, int power, DFruit devil_fruit);
        int get_bounty() const;
        bool train(int days);
        bool operator==(const Pirate& p) const;
        friend ostream& operator<< (ostream& o, const Pirate& p);

    private:
        string name;
        int power;
        DFruit devil_fruit = DFruit::None;
    };


#endif // PIRATE_H