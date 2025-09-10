#include <iostream>
#include <string>
#include <vector>
#include "pirate.h"
#include "crew.h"

using namespace std;

int main() {
try {
  cout << "Class Pirate:\n";
  try {
    const Pirate p{"",4000};
    cout << "error 1" << p << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 1\n";
  }
  try {
    const Pirate p{"Luffy",9001};
    cout << "error 2" << p << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 2\n";
  }
  try {
    const Pirate p{"Luffy",0};
    cout << "error 3" << p << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 3\n";
  }

  vector<Pirate> vp{
    Pirate("Monkey D. Luffy",5000,DFruit::Zoan),
    Pirate("Zoro",4900,DFruit::None),
    Pirate("Sanji",4899,DFruit::None),
    Pirate("Nami",400,DFruit::None),
    Pirate("Robin",4000,DFruit::Paramecia),
    Pirate("Lysop",700,DFruit::None),
    Pirate("Franky",3123,DFruit::Zoan),
    Pirate("Chopper",5,DFruit::Zoan),
    Pirate("Brooke",1500,DFruit::Paramecia),
    Pirate("Jimbei",4700,DFruit::None),
    Pirate("Portgas  D. Ace",5000,DFruit::Logia),
  };

  for (const auto& p : vp)
    cout << p << '\n';
  cerr << vp.at(2) << '\n';
  
  for (const auto& p: vp)
    cout << p.get_bounty() << ' ';
  cout << '\n';

  vp.push_back(Pirate("Zoro",4899,DFruit::None));
  vp.push_back(Pirate("Zoro",4900,DFruit::Zoan));
  vp.push_back(Pirate("Zoro_Clone",4900,DFruit::None));

  Pirate  tmp{vp.at(1)};
  cout << tmp << '\n';
  for (const auto& p: vp)
    cout <<  (p == tmp) << ' ';
  cout << '\n';
  vp.pop_back();
  vp.pop_back();
  vp.pop_back();

  {  
    Pirate  training_dummy{"Training Dummy",8999,DFruit::None};
    cout << training_dummy << '\n';
    cout << training_dummy.train(1) << '\n';
    cout << training_dummy.train(0) << '\n';
    cout << training_dummy.train(-1) << '\n';
    cout << training_dummy << '\n';
  }
  {
    Pirate  training_dummy{"Training Dummy",8950,DFruit::None};
    cout << training_dummy << '\n';
    cout << training_dummy.train(1) << '\n';
    cout << training_dummy.train(0) << '\n';
    cout << training_dummy.train(-1) << '\n';
    cout << training_dummy << '\n';
    cout << training_dummy.train(3) << '\n';
    cout << training_dummy.train(3) << '\n';
    cout << training_dummy << '\n';
  }
  cout << "\nClass Crew:\n";
  try {
    const Crew c{"",vp.at(0)};
    cout << "error 4" << c << '\n';
  }
  catch (runtime_error& e) {
    cout << "catch 4\n";
  }
  {
    const Crew c{"Emtpy Crew",vp.at(0)};
    cout << c << '\n';
    cerr << c << '\n';
  }
  
  Crew c{"Straw Hat Pirates",vp.at(0)};
  cout << c << '\n';
  for (const auto& p : vp){
    try{
      c.add_member(p);
    } catch (runtime_error& e) {
      cout << "catch 5: " << "error 5" << '\n';
    }
  }
  try {
    c.add_member(vp.at(2));
  }
  catch (runtime_error& e) {
    cout << "catch 6: " << "error 6" << '\n';
  }

  cout << c.total_bounty() << '\n';

  cout << c << '\n';
  
  

// Dekommentieren fuer Zusatz remove_dfruit_users
/*
  cout << "\nAdditional task remove_dfruit_users:\n";
  Crew cpy{c};
  try{
    cpy.remove_dfruit_users(DFruit::Zoan);
  }
  catch (runtime_error& e) {
    cout << "catch 7: " << "error 7" << '\n';
  }
  vector<Pirate> removed = cpy.remove_dfruit_users(DFruit::Paramecia);
  for (const auto& p : removed)
    cout << p << '\n';
  cout << cpy << '\n';
  removed = cpy.remove_dfruit_users(DFruit::None);
  for (const auto& p : removed)
    cout << p << '\n';
  cout << cpy << '\n';
  removed = cpy.remove_dfruit_users(DFruit::None);
  for (const auto& p : removed)
    cout << p << '\n'; 
  cout << cpy << '\n';
*/

// Dekommentieren fuer Zusatz annex
/*
  cout << "\nAdditional task annex:\n";
  vector<Pirate> v_c1{
    Pirate("Monkey D. Luffy",5000,DFruit::Zoan),
    Pirate("Zoro",4900,DFruit::None),
    Pirate("Sanji",4899,DFruit::None),
    Pirate("Nami",400,DFruit::None),
    Pirate("Robin",4000,DFruit::Paramecia),
    Pirate("Lysop",700,DFruit::None),
    Pirate("Franky",3123,DFruit::Zoan),
    Pirate("Chopper",5,DFruit::Zoan),
    Pirate("Brooke",1500,DFruit::Paramecia),
    Pirate("Jimbei",4700,DFruit::None),
  };
  Crew c1{"Straw Hat Pirates",v_c1.at(0)};
  for (const auto& p : v_c1){
    try{
      c1.add_member(p);
    } catch (runtime_error& e) {
    }
  }
  vector<Pirate> v_c2{
    Pirate("Eustass Kid",4500,DFruit::Paramecia),
    Pirate("Killer",4900,DFruit::None),
    Pirate("Heart",4899,DFruit::None),
    Pirate("Wire",200,DFruit::None),
    Pirate("Gig",189,DFruit::None),
    Pirate("Robin",4000,DFruit::Paramecia),
  };
  Crew  c2{"Kid Pirates",v_c2.at(0)};
  for (const auto& p : v_c2){
    try{
      c2.add_member(p);
    } catch (runtime_error& e) {
    }
  }
  {
    vector<Pirate> v_c3{
      Pirate("Trafalgar D. Water Law",3000,DFruit::Zoan),
      Pirate("Bepo",4900,DFruit::None),
      Pirate("Shachi",4899,DFruit::None),
      Pirate("Penguin",200,DFruit::None),
      Pirate("Jean Bart",189,DFruit::None),
    };
    Crew  c3{"Heart Pirates",v_c3.at(0)};
    for (const auto& p : v_c3){
      try{
        c3.add_member(p);
      } catch (runtime_error& e) {
      }
    }
    cout << c3.annex(c2) << '\n';
    cout << c2.annex(c3) << '\n';
    cout << c3 << '\n';
    cout << c2 << '\n';
  }
  vector<Pirate> v_c3{
    Pirate("Trafalgar D. Water Law",2000,DFruit::Zoan),
    Pirate("Bepo",4900,DFruit::None),
    Pirate("Shachi",4899,DFruit::None),
    Pirate("Penguin",200,DFruit::None),
    Pirate("Gig",189,DFruit::None),
    Pirate("Jean Bart",189,DFruit::None),
    Pirate("Eustass Kid",4500,DFruit::Paramecia),
  };
  Crew  c3{"Heart Pirates",v_c3.at(0)};
  for (const auto& p : v_c3){
    try{
      c3.add_member(p);
    } catch (runtime_error& e) {
    }
  }
  cout << c2.annex(c3) << '\n';
  cout << c2 << '\n';
  cout << c3 << '\n';
  cout << c2.annex(c1) << '\n';
  cout << c1 << '\n';
  cout << c2 << '\n';
*/
}
catch (exception& e) {
  cout << "Unexpected exception: " << e.what() << '\n';
}
catch (...) {
  cout << "Non standard exception thrown!";
}
return 0;
}