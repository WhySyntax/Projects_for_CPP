#include "Room.h"
using namespace std;

//defining room functions
Room::Room(char desc[80]) {
  description = desc;
}
Room::~Room() {
  cout << "Something has gone horribly wrong";
}
Room::setExit((char dir, Room* location) {
    location->exits.push_back(make_tuple(dir,location));
}
//defining item functions
Item::Item(char n[20],char d[80]) {
  name = n;
  description = d;
}
