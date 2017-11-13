/*-------------------------------------------------------------------------------------/
Abraham Steenhoek

**main.cpp**
    -runs the functions to initialize a matrix from stdin and compute the room and lowest cost
CPS 210 - Program 3: Optimal Binary Search Tree
11/11/2017
7 hours
/-------------------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include "matrix.h"

using namespace std;

// cd /mnt/c/Users/AJ\ Steenhoek/Documents/Fall_2017/Data_Structures/Prog3
// g++ -std=c++14 *.cpp -oprog3
using namespace std;

int main() {
    Matrix grid;
    //grid.print();

    cout << grid.findRoot() << " " << grid.searchCost() << endl;
    return 0;
}