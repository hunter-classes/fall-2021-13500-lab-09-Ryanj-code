/* 
Author: Ryan Jiang 
Course: CSCI-135 
Instructor: Tong Yi and Mike Zamansky 
Assignment: Lab 9 
This program contains the functions that deal with coordinates in 3D. 
*/

#include <iostream>
#include <cmath>
#include "funcs.h"
#include "coord3d.h"

double length(Coord3D *p){
  double x = (*p).x;
  double y = (*p).y;
  double z = (*p).z;
  // Set the x, y, z variables to the x, y, z variables from *p.
  return (sqrt(x * x + y * y + z * z));
} // Return the length.

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2){
  double length_p1 = length(p1);
  double length_p2 = length(p2);
  // Get length of p1 and p2 by using the length function.
  
  if(length_p1 < length_p2){
    return p2;
  } // If the length of p1 is farther then p2 from the origin, return p2.
  else{
    return p1;
  } // Else return p2.
}

void move(Coord3D *ppos, Coord3D *pvel, double dt){
  (*ppos).x += (*pvel).x * dt;
  (*ppos).y += (*pvel).y * dt;
  (*ppos).z += (*pvel).z * dt;
} // Moves the x, y, and z in ppos by adding the current velocity multipled by dt(time).

Coord3D* createCoord3D(double x, double y, double z){
  Coord3D * new_coord = new Coord3D;
  (*new_coord).x = x;
  (*new_coord).y = y;
  (*new_coord).z = z;
  // Create new Coord3D called new_coord, and set the variables based on the parameters.
  
  return new_coord;
} // Returns new_coord.

void deleteCoord3D(Coord3D *p){
  delete p;
} // Delete the pointer.
