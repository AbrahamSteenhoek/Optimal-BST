/*-------------------------------------------------------------------------------------/
Abraham Steenhoek

**matrix.h**
    -contains definitions for methods in "matrix.h"
CPS 210 - Program 3: Optimal Binary Search Tree
11/11/2017
7 hours
/-------------------------------------------------------------------------------------*/
#include "matrix.h"

struct Comp {
    bool operator() (const pair<string, int> &a, const pair<string, int> &b) {
        return a.first > b.first;
    }

};
//

/*
Constructor: Matrix
    -Constructs a grid of NxN
    -N determined by amount of keys passed in
    -everything initialized to 0 by default, initialized first main diagonal
*/
Matrix::Matrix() {
    string w;
    int f;
    // take in all the input
    while (cin >> w >> f) {
        input[w] = f;
        names.push_back(w);
    }
    sort(names.begin(), names.end());
    // grid is square of size NxN
    N = input.size();
    grid = new int*[N];
    runningSum = new int[N];
    int i = 0;
    for(auto k : input) {
        int freq = k.second;
        if(i == 0) {
            runningSum[0] = freq;
        }
        else
            runningSum[i] = (runningSum[i - 1] + freq);
        
        grid[i] = new int[N]();
        grid[i][i] = freq;
        i++;
    }
    // for (size_t i = 0; i < N; i++) {
    //     int freq = input.begin()->second;
    //     input.erase(input.begin());
    //     //input.erase(input.begin() + 0);//input.pop();
    //     if(i == 0)
    //         runningSum.push_back(freq);
    //     else
    //         runningSum.push_back(runningSum.at(i-1) + freq);
    //     grid[i] = new int[N]();
    //     grid[i][i] = freq;
    // }
    //cout << "size: " << N << endl;
    populate();
}

/*
Method: Populate
    -fills the matrix grid with values that represent an Optimal BST
    -uses initialized array runningSum
Returns:
    -void
*/
void Matrix::populate() {
    for (size_t diag = 1; diag < N; diag++) {
        for(size_t i = 0; i < N - diag; i++) {
            // first value
            int min = grid[i + 1][diag+i];
            
            for(size_t k = 1; k < diag; k++) {
                //cout << "min: " << min;
                //cout << " val: " << grid[i][i + k - 1] + grid[i + k + 1][diag + i];
                min = std::min(min, grid[i][i + k - 1] + grid[i + k + 1][diag + i]);
                //cout << " new min: " << endl;
            }

            // last value
            min = std::min(min, grid[i][diag + i - 1]);

            if(i == 0)
                min += runningSum[diag];
            else
                min += runningSum[diag + i] - runningSum[i - 1];

            grid[i][diag + i] = min;
            // print();
        }
    }
}

/*
Function: findRoot
    -finds the root of the optimal BST
Returns:
    -string that contains the root
*/
string Matrix::findRoot() {
    vector<int> vals;
    int diag = N - 1;
    int min = grid[0][N - 1] - runningSum[N - 1];
    vals.push_back(grid[1][diag]);

    for(size_t k = 1; k < diag; k++) {
        vals.push_back(grid[0][k - 1] + grid[k + 1][diag]);
    }

    vals.push_back(grid[0][diag - 1]);

    for(int i = 0; i < N; i++) {
        if (vals[i] == min) {
            return names[i];
        }
    }
    
    return "";
}

/*
Method: print
    -prints current status of the grid
Returns:
    -void
*/
void Matrix::print() {
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(grid[i][j] > 100) {
                cout << " ";
            }
            else if(grid[i][j] >= 10) {
                cout << "  ";
            }
            else if(grid[i][j] >= 0) {
                cout << "   ";
            }
            cout << grid[i][j] ;
        }
        cout << endl;
    }
    // cout << endl;
    // for(auto i : runningSum) {
    //     cout << i << " ";
    // }
    // cout << endl;
}

/*
Deconstructor: ~Matrix
    -frees all of the dynamically reserved memory used to create the Matrix
*/
Matrix::~Matrix() {
    for(int i = 0; i < N; i++) {
        delete [] grid[i];
    }
    delete [] grid;
    delete [] runningSum;
    
}
