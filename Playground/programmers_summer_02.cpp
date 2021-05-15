#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Guest{
  int id;
  int rank;
  int time;
};

bool cmp(const Guest &g1, const Guest &g2){
  if(g1.rank < g2.rank) return true;
  return false;
}

int main(){
  vector<Guest> guests;

  Guest guest = {0, 0, 0};
  guests.push_back(guest);
  Guest guest1 = {1, 1, 1};
  guests.push_back(guest1);
  Guest guest2 = {2, 3, 2};
  guests.push_back(guest2);
  Guest guest3 = {3, 0, 3};
  guests.push_back(guest3);

  // guests.push_back({0, 0, 0});
  // guests.push_back({1, 1, 1});
  // guests.push_back({2, 3, 2});
  // guests.push_back({3, 0, 3});

  sort(guests.begin(), guests.end(), cmp);

  for(auto guest:guests){
    cout << guest.id << " " << guest.rank << " " << guest.time << endl;
  }

  return 0;
}
