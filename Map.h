#ifndef MAP_H
#define MAP_H
#include "City.h"
#include <string>
#include <vector>

class Map {
private:
  std::vector<City *> map;
public:
  Map(std::string filename);
  City * findByName(std::string cityName);
  std::vector<City *> getMap();
  void findAdjacents(City * c);
};

#endif
