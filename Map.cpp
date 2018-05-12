#include "Map.h"
#include "City.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

Map::Map(string filename) {
  ifstream myfile(filename);
  string name;
  int x,y;
  while (myfile >> name >> x >> y) {
    City * temp = new City(name, x, y);
    map.push_back(temp);

  }
  for (auto i: map) {
    findAdjacents(i);
  }
}

vector<City *> Map::sortShortest(list<City *> cities) {
  // set<City *> citySet;
  // for (auto i : cities) {
  //   citySet.insert(i);
  // }
  // int i, j;
  // bool swapped;
  // for (i = 0; i < citySet.size() - 1; i++) {
  //   swapped = false;
  //   for (j = 0; j < n - i - 1; j++) {
  //     if (citySet.at(j) > citySet.at(j + 1)) {
  //       City * temp = citySet.at(j);
  //       citySet.at(j) = citySet.at(j + 1);
  //       citySet.at(j + 1) = temp;
  //       swapped = true;
  //     }
  //   }
  //   if (swapped == false) {
  //     break;
  //   }
  // }
  vector<City *> myVec;
  for (auto i : cities) {
    myVec.push_back(i);
  }
  sort(myVec.begin(), myVec.end());
  return myVec;
}

// list<City *> Map::sortShortestHelp(int length, City * city, list<City *> cities, list<City *> shortest) {
//   int shortestDist = 100;
//   City * shortestCity = nullptr;
//   for (auto i : cities) {
//     if (length + pathDistance(city, i) < shortestDist) {
//       shortestCity = i;
//       shortestDist = length + pathDistance(city, i);
//     }
//   }
//   shortest.push_back(shortestCity);
//   list<City *> newCities;
//   for (auto i : cities) {
//     if (i != shortestCity) {
//       newCities.push_front(i);
//     }
//   }
//   return sortShortestHelp(length, city, newCities, shortest);
// }

vector<City *> Map::shortestPath(City * start, City * dest) {
  // vector<City *> visitedCity;
  // for (auto i : map) {
  //   i->setVisited(false);
  //   visitedCity.push_back(i);
  // }
  // vector<City *> returnVec;
  // returnVec = shortestPathHelp(0, start, dest, cityPath, visitedCity);
  // cityPath = nullptr;
  // return returnVec;
  for (auto i : map) {
    i->setVisited(false);
    i->setDistance(10000000);
  }
  //cerr << start->getName() << endl;
  vector<City *> cityPath;
  vector<City *> returnPath;
  start->setDistance(0);
  start->setVisited(true);
  list<City *> adjStart = start->getAdjacent();
  for (auto i : adjStart) {
    if ((start->getDistance() + pathDistance(i, start) < i->getDistance())) {
      i->setDistance(pathDistance(start, i));
    }
  }
  cityPath.push_back(start);
  start->setVisited(true);
  vector<City *> adjac = sortShortest(adjStart);
  vector < vector<City *> > paths;
  vector < pair < int, vector <City *> > > cityPairs;
  pair <int, vector< City *> > pairs;
  for (auto i : adjac) {
    cerr << i->getName() << " adj list"<< endl;
  }
  for (auto i : adjac) {
  //  cerr << i->getName() << " adjacents" << endl;
    cityPath = shortestPathHelp(start, i, dest, cityPath);
    pair <int, vector< City *> > pairs(i->getDistance(), cityPath);
    cityPairs.push_back(pairs);
  }
  pair<int, vector<City *> > shortest = cityPairs.back();
  //cerr << " " << endl;
  for (auto i : cityPairs) {
  //  cerr << i.first << " lengths" << endl;
    for (auto n : i.second) {
    //  cerr << n->getName() << ", ";
    }
    if (i.first < shortest.first && i.first != 0) {
      shortest = i;
    }
  }
  cityPath = shortest.second;
  for (auto i : cityPath) {
    //cerr << i->getName() << ", ";
  }
  return cityPath;
}

vector<City *> Map::shortestPathHelp(City * orig, City * start, City * dest, vector<City *> cityPath) {
  // if (start == dest) {
  //   return cityPath;
  // }
  // if (start->getVisited() == true) {
  //   return cityPath;
  // }
  // list<City *> adjStart = start->getAdjacent();
  // adjStart = sortShortest(length, start, adjStart);
  // start->setVisited(true);
  // visitedCity.remove(start);
  //
  // for (auto i : adjStart) {
  //   return shortestPathHelp(length + pathDistance(start, i), i, dest, cityPath, visitedCity);
  // }

  // cerr << start->getName() << endl;
  // if (start == dest) {
  //   cerr << 5 << endl;
  //   cityPath.push_back(start);
  //   return cityPath;
  // } else if (dest->getVisited() == true) {
  //   cityPath.pop_back();
  //   cerr << 6 << endl;
  //   return cityPath;
  // }
  // cerr << 3 << endl;
  // list<City *> adjStart = start->getAdjacent();
  // for (auto i : adjStart) {
  //   //cerr << pathDistance(start, i) << endl;
  //   if (i->getDistance() > (i->getDistance() + pathDistance(start, i))) {
  //     i->setDistance(i->getDistance() + pathDistance(start, i));
  //   }
  //   //cerr << i->getDistance() << endl;
  // }
  // cerr << 4 << endl;
  // vector<City *> adjac = sortShortest(adjStart);
  // //cerr << shortest->getName() << "  !" << endl;
  // cityPath.push_back(start);
  // start->setVisited(true);
  // vector<City *> returnVec;
  // for (auto i : adjac) {
  //   cerr << "adjacent: " << i->getName() << endl;
  //   if (i->getVisited() != true) {
  //     cerr << 7 << endl;
  //     cityPath = shortestPathHelp(i, dest, cityPath);
  //   }
  //   cerr << 8 << endl;
  //
  //   cerr << 10 << endl;
  // }
  // cerr << 11 << endl;
  // set<City *> cities;
  // list<City *> temp;
  // for (auto i : cityPath) {
  //   cities.insert(i);
  // }
  // cities.erase(start);
  // cityPath.clear();
  // for (auto i : cities) {
  //   temp.push_back(i);
  // }
  // cityPath = sortShortest(temp);
  // //cityPath.pop_back();
  // return cityPath;
  cerr << start->getName() << endl;
  if (dest->getVisited() == true) {
    return cityPath;
  }
  list<City *> adjStart = start->getAdjacent();
  for (auto i : adjStart) {
    if ((start->getDistance() + pathDistance(i, start) < i->getDistance()) && i != orig) {
      i->setDistance(start->getDistance() + pathDistance(i, start));
    }
    if (i == orig && start->getDistance() > pathDistance(i, start)) {
      start->setDistance(pathDistance(i, start));
    }
  }
  cityPath.push_back(start);
  start->setVisited(true);
  vector<City *> adjac = sortShortest(adjStart);
  vector < vector<City *> > paths;
  vector < pair < int, vector <City *> > > cityPairs;
  pair <int, vector< City *> > pairs;
  for (auto i : adjac) {
  //  cerr << i->getName() << " adjacents" << endl;
    if (i->getVisited() != true) {
      cityPath = shortestPathHelp(orig, i, dest, cityPath);
      pair <int, vector< City *> > pairs(i->getDistance(), cityPath);
      cityPairs.push_back(pairs);
    }
  }
  pair<int, vector<City *> > shortest = cityPairs.back();
  //cerr << " " << endl;
  for (auto i : cityPairs) {
  //  cerr << i.first << " lengths" << endl;
    for (auto n : i.second) {
    //  cerr << n->getName() << ", ";
    }
    if (i.first < shortest.first && i.first != 0) {
      shortest = i;
    }
  }
  return shortest.second;
}

unsigned int Map::pathDistance(City * start, City * dest) {
  int diff = 0;
  if (start->getXCoor() == dest->getXCoor()) {
    diff = start->getYCoor() - dest->getYCoor();
  } else if(start->getYCoor() == dest->getYCoor()) {
    diff = start->getXCoor() - dest->getYCoor();
  } else {
    return -1;
  }
  if (diff < 0) {
    diff *= -1;
  }
  return diff;
}



vector<City *> Map::getMap() {
  return map;
}




City * Map::findByName(string cityName) {
  for (auto i : map) {
    if (i->getName() == cityName) {
      return i;
    }
  }
  return nullptr;

}

void Map::findAdjacents(City * temp) {
  int north = 0;
  int south = 0;
  int west = 0;
  int east = 0;
  for (auto i : map) {
    if (i->getXCoor() == temp->getXCoor() && i->getYCoor() - temp->getYCoor() > 0) {
      if (north == 0) {
        temp->addAdjacent(i, "n");
        north = i->getYCoor() - temp->getYCoor();
      } else {
        if (temp->getYCoor() - i->getYCoor() < north) {
          temp->addAdjacent(i, "n");
          north = i->getYCoor() - temp->getYCoor();
        }
      }
    } else if (i->getXCoor() == temp->getXCoor() && i->getYCoor() - temp->getYCoor() < 0) {
      if (south == 0) {
        temp->addAdjacent(i, "s");
        south = temp->getYCoor() - i->getYCoor();
      } else {
        if (i->getYCoor() - temp->getYCoor() < south) {
          temp->addAdjacent(i, "s");
          south = temp->getYCoor() - i->getYCoor();
        }
      }
    } else if (i->getYCoor() == temp->getYCoor() && i->getXCoor() - temp->getXCoor() > 0) {
      if (east == 0) {
        temp->addAdjacent(i, "e");
        east = i->getXCoor() - temp->getXCoor();
      } else {
        if (temp->getYCoor() - i->getYCoor() < east) {
          temp->addAdjacent(i, "e");
          east = temp->getXCoor() - i->getXCoor();
        }
      }
    } else if (i->getYCoor() == temp->getYCoor() && i->getXCoor() - temp->getXCoor() < 0) {
      if (west == 0) {
        temp->addAdjacent(i, "w");
        west = temp->getXCoor() - i->getXCoor();
      } else {
        if (i->getYCoor() - temp->getYCoor() < west) {
          temp->addAdjacent(i, "w");
          west = temp->getXCoor() - i->getXCoor();
        }
      }
    }
  }
}
