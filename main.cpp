/*
Author: Ryan Jiang
Course: CSCI-135
Instructor: Tong Yi and Mike Zamansky
Assignment: Lab 9
This programs contains some tests for the functions in funcs.cpp.
*/

#include <iostream>
#include "coord3d.h"
#include "funcs.h"

int main()
{
  Coord3D pointP = {10, 20, 30};

  std::cout << "Part A:\nLength of P: " << length(&pointP) << "\n\n";

  Coord3D pointQ = {-20, 21, -22};
  
  std::cout << "Part B:\n";
  std::cout << "Address of P: " << &pointP << "\n";
  std::cout << "Address of Q: " << &pointQ << "\n";

  std::cout << "Farther from origin: " << fartherFromOrigin(&pointP, &pointQ) << "\n\n";

  Coord3D pos = {0, 0, 100.0};
  Coord3D vel = {1, -5, 0.2};

  std::cout << "Part C:\n";
  std::cout << "Original: " << pos.x << " " << pos.y << " " << pos.z << "\n";
  move(&pos, &vel, 2.0);
  std::cout << "After move: " << pos.x << " " << pos.y << " " << pos.z << "\n\n";

  std::cout << "Part E:\n";
  
  Coord3D * ppos = createCoord3D(10, 20, 30);
  Coord3D * pvel = createCoord3D(5.5, -1.4, 7.77);

  std::cout << "Position from createCoord3D: " << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << "\n";
  std::cout << "Velocity from createCoord3D: " << (*pvel).x << " " << (*pvel).y << " " << (*pvel).z << "\n";

  move(ppos, pvel, 10.0);

  std::cout << "Coordinates after 10 seconds: " << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << std::endl;

  return 0;
}
