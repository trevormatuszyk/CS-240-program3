#include "City.h"
#include <string>
#include <cstdlib>
#include <list>
#include <iostream>


using namespace std;

City::City() {

}

City::City(string cityName, int xCoor, int yCoor) {
  this->cityName = cityName;
  this->xCoor = xCoor;
  this->yCoor = yCoor;
  this->north = nullptr;
  this->south = nullptr;
  this->east = nullptr;
  this->west = nullptr;
  this->visited = NULL;
  this->distance = 10000000;
}

void City::setDistance(int val) {
  this->distance = val;
}

int City::getDistance() {
  return this->distance;
}

string City::getName() {
  return this->cityName;
}

void City::setVisited(bool val) {
  this->visited = val;
}

bool City::getVisited() {
  return this->visited;
}

int City::getXCoor() {
  return this->xCoor;
}

int City::getYCoor() {
  return this->yCoor;
}

list<City *> City::getAdjacent() {
  list<City *> adj;
  if (north != NULL) {
    adj.push_back(north);
  }
  if (south != NULL) {
    adj.push_back(south);
  }
  if (east != NULL) {
    adj.push_back(east);
  }
  if (west != NULL) {
    adj.push_back(west);
  }

  return adj;
}

void City::addAdjacent(City * c, string d) {
  if (d == "n") {
    this->north = c;
  } else if(d == "s") {
    this->south = c;
  } else if (d == "e") {
    this->east = c;
  } else {
    this->west = c;
  }
}

bool City::operator<(City &c) {
  int temp1, temp2;
  for (int i = 0; i < c.getName().length(); i++) {
    temp1 += c.getName().at(i);
  }
  for (int i = 0; i < getName().length(); i++) {
    temp2 += getName().at(i);
  }
  if (temp1 > temp2) {
    return false;
  } else {
    return true;
  }
}
