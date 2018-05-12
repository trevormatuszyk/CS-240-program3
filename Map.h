#ifndef MAP_H
#define MAP_H
#include "City.h"
#include <string>
#include <vector>
#include <list>
#include <set>

class Map {
private:
  std::vector<City *> map;
public:
  Map(std::string filename);
  City * findByName(std::string cityName);
  std::vector<City *> getMap();
  void findAdjacents(City * c);
  std::vector<City *> shortestPath(City * start, City * dest);
  std::vector<City *> shortestPathHelp(City * orig, City * start, City * dest, std::vector<City *> cityPath);
  unsigned int pathDistance(City * start, City * dest);
  std::vector<City *> sortShortest(std::list<City *> cities);
  //std::list<City *> sortShortestHelp(int length, City * city, std::list<City *> cities, std::list<City *> shortest);
};

#endif
