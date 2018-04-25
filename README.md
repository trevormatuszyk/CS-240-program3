#### CS 240 - Spring 2018
# Program 3 - Driving Directions
## Due Date: 11:59 p.m., May 10th, 2018

*All programs will be tested on the machines in the Q22 lab. If your code does not run on the system in this lab, it is considered non-functioning EVEN IF IT RUNS ON YOUR PERSONAL COMPUTER. Always check that your code runs on the lab machines before submitting.*

### Provided Files and Expected Output
* _Files_
    * Driver
       * program3.cpp
    * Test players files
       * townlist.txt
       * townlist2.txt
* _Expected Command > Output_
    * Test Commands we will run
        * make
        * make run
        * make checkmem
        * make clean
    * Sample Output:
```shell
    TBD
```

### Grading Rubric
__Total: 70 points__
* __Part A__
    * Test 1: 3 points
        * Read file a list of Cities and their locations
    * Test 2: 5 points
        * Test Adjacencies
* __Part B__
    * Test 3-5: 5 points each
        * Simple Shortest Path
        * Less Simple Shortest Path
        * Shortest Path between a single point
    * Test 6-8: 6 points each
        * Shortest Path on Map 2
        * Another Shortest Path on Map 2
        * No Path
    * Test 9: 4 point
        * Distance of no path is -1
    * Test 10-12: 5 points each
        * Distance from a single city (should be 0)
        * Distance between two cities
        * Distance with two equal paths
* __Part C__
    * Test 14: 10 points
        * Heap Performance
* __Part D__
    * If memory error, memory leak, no 'checkmem' target [-5 points]
    * Does not follow requested project structure, makefile, and submission format [-3 points]
    * Submission includes .o files or binary [-1 point]
    * Does not follow [Style guidelines](https://drive.google.com/open?id=1a5I7XhhCDRHoS8LUfILu3y2la4wW8HHh4olO30YvMVk) [-3 points]

### Guidelines

This is a pair programming assignment. You and a partner can divide up the work. Although both of you may not work on all parts of the program you should understand and be able to fully explain every portion of the code. Outside of your team, it is permissible to consult with classmates to ask general questions about the assignment, to help discover and fix specific bugs, and to talk about high level approaches in general terms. It is not permissible to give or receive answers or solution details from fellow students.

You may research online for additional resources; however, you may not use code that was written specifically to solve the problem you have been given, and you may not have anyone else help you or your partner write the code or solve the problem. You may use code snippets found online, providing that they are appropriately and clearly cited, within your submitted code.

If you or your partner are found to have plagiarized any part of the assignment, both will receive a 0 and be reported.

*By submitting this assignment, you agree that you have followed the above guidelines regarding collaboration and research.*

***

For our final program you are going to create a library that reads in a file with a list a cities and the roads between the cities. The driver code will input a starting city and destination city, and you will return the shortest path between the two as a vector of cities along the path. Then we are going to test our path finding algorithm with a heap and without a heap.

Because this is a pair programming assignment, one of your team member will have to create the repo and team name. The other team member will join, and select the team name as their team.

## Part A: Making a Graph

For Part A you will read in a text containing cities and their x and y coordinates along a grid. The file format will be as follows:

```
        mogadishu 6 7
        fairbanks 3 5
        nyc 4 7
        paris 3 2
```

City names will not contain whitespace and will be uniquely named. Input files will be well-formed (no need for error checking). You will need to build an undirected, weighted graph using the x and y coordinates.

The user can only travel in straight lines, so paths are along the x and y grid. In other words, there is an edge between two cities if they have equal x coordinates or equal y coordinates and there is no city between them on the path. A city will have, at most, 4 adjacent cities. The adjacent city in any one direction is only the closest city in that direction. So the algorithm for building the adjacency list will be to find all cities in one direction, but set only the closest one as adjacent.

For example, if you have 3 cities along the same x axis A[5,3], B[5,6], and C[5,4], A is only adjacent to C; however, C is adjacent to B in the northern direction, and A in the southern direction.

You should use an array or vector to store the cities. To hold edges you will need to implement an adjacency list or an adjacency matrix (you may use the STL list or vector class).

### City
* Public Methods
    * `City(string cityName, int xCoor, int yCoor)`
    * `std::string getName()`
         * Returns the city name
    * `int getXCoor()`
         * Returns the x coordinate
    * `int getYCoor()`
         * Returns the y coordinate
    * `list<City*> getAdjacent()`
         * Returns an adjacency list for the city
    * `bool operator<(City &c)`
         * Compares cities by name using the string operator< method

### Map
* Public Methods
    * `Map(string filename)`
    * `City* findByName(string cityName)`

__Show your TA your working Part A code by the end of lab on May 3rd.__

_You may continue to work on the remainder of the lab on your own time or in lab_

## Part B: Finding the Shortest Path

You will need to implement Dijkstra’s shortest path algorithm to determine the shortest path between two cities. If you want to implement a different shortest path algorithm, you must clear it with me first. You must travel in straight lines, and can only change directions at cities. In other words, if cityA has coordinates [5,7] and cityB has coordinates [6,2], there is no path between them. However, if you add cityC with coordinates [5,2], you now have a path between cityA and cityB through cityC.

You should add the following public method to your Map class:
* `vector<City *> shortestPath(City * start, City * dest)`
    * The method should return the shortest path between two cities by returning a list of the cities you will need to travel through in order.


You will also need a second method that gives the distance between two cities on the graph:
* `unsigned int pathDistance(City * start, City * dest)`
    * The method should return the total distance (based on the path you must take) between the two cities.
    * The method should return -1 if there is no path.

## Part C: Optimizing Dijkstra's Algorithm

Part of the complexity of Dijkstra's algorithm comes from finding the next closest, unvisited vertex. Typically, you can increase the speed of Dijkstra's shortest path algorithm by storing the data in a simple priority queue, such as a heap. We will optionally store our cities in a heap to make accessing the closest city a constant time operation (_well, O(logn) if you count the time to re-heapify_). Add an additional Map constructor that takes a boolean as a second parameter in addition to the filename.
* `Map(string filename, bool heap)`

I recommend adding a method, 'getNextCity', that will iterate through the cities to find the next closest city if a heap is not used, otherwise will heapify your list of cities and return the priority value if a heap is used.

:warning: Remember to account for the `visited` flag when heapifying.

## Part D: Code Organization and Submission
* Required code organization:
    * program3.cpp
    * Map.h/.cpp
    * City.h/.cpp
    * makefile
        * You must have ‘checkmem’ and ‘run’ targets
        * Your makefile must include c++11 or c++14 extensions

To submit, you only need to submit to your single group repo.

Below is just a reminder of the commands you should use to submit your code. If you cannot remember the exact process, please review lab 1.

*These commands all presume that your current working directory is within the directory tracked by `git`.*

```git
git add Deck.h
git add Card.cpp
git commit -a -m "first commit"
git push
```
Lastly we are going to make our final commit. You will need to do this when your submission is ready for grading.

```shell
git commit --allow-empty -m "final commit"
git push
```

:warning: Remember, you __MUST__ make a submission with the comment "final commit" before the deadline to be considered on time.
