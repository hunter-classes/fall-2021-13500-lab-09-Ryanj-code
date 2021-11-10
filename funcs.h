/*
Author: Ryan Jiang
Course: CSCI-135
Instructor: Tong Yi and Mike Zamansky
Assignment: Lab 9
This is the header file for the functions in funcs.cpp.
*/

#pragma once

#include "coord3d.h"

double length(Coord3D *p);
Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2);
void move(Coord3D *ppos, Coord3D *pvel, double dt);
Coord3D* createCoord3D(double x, double y, double z);
Coord3D* createCoord3D(double x, double y, double z);
void deleteCoord3D(Coord3D *p);
