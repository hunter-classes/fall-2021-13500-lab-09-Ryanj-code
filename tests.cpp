#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("Testing length:"){
  SUBCASE("Testing Zero:"){
    Coord3D pointP = {0, 0, 0};
    CHECK(length(&pointP) == 0);
  }
  
  SUBCASE("Normal Cases:"){
    Coord3D pointP = {10, 20, 30};
    CHECK(length(&pointP) == sqrt(10*10+20*20+30*30));
    pointP = {5, 7, 9};
    CHECK(length(&pointP) == sqrt(5*5+7*7+9*9));
    pointP = {10, 10, 10};
    CHECK(length(&pointP)== sqrt(10*10*3));
  }
}

TEST_CASE("Testing fartherFromOrigin:"){
  SUBCASE("Normal Cases:"){
    Coord3D pointP = {10, 20, 30};
    Coord3D pointQ = {-20, 21, -22};
    CHECK(fartherFromOrigin(&pointP, &pointQ) == &pointP);
    pointP = {50, 10 ,10};
    pointQ = {100, 20, 20};
    CHECK(fartherFromOrigin(&pointP, &pointQ) == &pointQ);
  }
  
  SUBCASE("Equal Cases:"){
    Coord3D pointP = {10, 10, 10};
    Coord3D pointQ = {10, 10, 10};
    CHECK(fartherFromOrigin(&pointP, &pointQ) == &pointP);
    pointP = {30, 15, 20};
    pointQ = {15, 20, 30};
    CHECK(fartherFromOrigin(&pointP, &pointQ) == &pointP);
  }  
}

TEST_CASE("Testing move:"){
  Coord3D pos = {0, 0, 100.0};
  Coord3D vel = {1, -5, 0.2};
  move(&pos, &vel, 2.0);
  CHECK((pos.x == 2 && pos.y == -10 && pos.z == 100.4));

  pos = {0, 5, 10};
  vel = {5, 2, 7};
  move(&pos, &vel, 10.0);
  CHECK((pos.x == 50 && pos.y == 70 && pos.z == 170));

  pos = {3.5, 10.3, 5.1};
  vel = {4.8, -2.9, 14.2};
  move(&pos, &vel, 9.3);
  CHECK((pos.x == (3.5 + 4.8 * 9.3) && pos.y == (10.3 - 2.9 * 9.3) && pos.z == (5.1 + 14.2 * 9.3)));
}

TEST_CASE("Testing createCoord3D"){
  Coord3D * ppos = createCoord3D(10, 15, 10);
  CHECK((ppos-> x == 10 && ppos-> y == 15 && ppos-> z == 10));
  Coord3D * pvel = createCoord3D(-11, 5, .5);
  CHECK((pvel-> x == -11 && pvel-> y == 5 && pvel-> z == 0.5));
  
  deleteCoord3D(ppos);
  deleteCoord3D(pvel);
}
