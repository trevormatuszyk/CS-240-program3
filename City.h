#ifndef CITY_H
#define CITY_H
#include <string>
#include <list>

class City {
private:
  std::string cityName;
  int xCoor;
  int yCoor;
  City * north;
  City * south;
  City * east;
  City * west;
public:
  City(std::string cityName, int xCoor, int yCoor);
  City();
  std::string getName();
  int getXCoor();
  int getYCoor();
  std::list<City *> getAdjacent();
  bool operator<(City &c);
  void addAdjacent(City * c, std::string d);
};

#endif
