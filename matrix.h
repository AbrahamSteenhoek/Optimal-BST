/*-------------------------------------------------------------------------------------/
Abraham Steenhoek

**matrix.h**
    -contains declarations for matrix structure for Optimal BST
    -Maze represents the grid passed in from stdin (cin)
    -Maze elements in the grid are initialized to 0 by default
    -Goal is to find the lowest cost BST possible from a given set of keys and values
CPS 210 - Program 3: Optimal Binary Search Tree
11/11/2017
7 hours
/-------------------------------------------------------------------------------------*/

#include <iostream>
#include <string>
#include <utility>
#include <queue>
#include <exception>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;

class Matrix {
    int **grid;
    vector<int> runningSum;
    vector<string> names;
    map<string, int> input;
    int N;
public:
    Matrix();
    void print();
    void populate();
    int searchCost() { return grid[0][N-1]; }
    string findRoot();
    ~Matrix();


}; // end of class Matrix