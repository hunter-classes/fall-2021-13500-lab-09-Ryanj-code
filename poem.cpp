/*
Author: Ryan Jiang
Course: CSCI-135
Instructor: Tong Yi and Mike Zamansky
Assignment: Lab 9
This is the cpp file for poem that allocates memory dynamically and deletes all dynamically allocated memory when not needed.
*/

#include <iostream>
using namespace std;

string * createAPoemDynamically() {
    string *p = new string;
    *p = "Roses are red, violets are blue";
    return p;
}

int main() {
    while(true) {
        string *p;
        p = createAPoemDynamically();

        // assume that the poem p is not needed at this point

	delete p;
	// AS we can assume poem p is not needed, we can delete p.
	
    }
}
