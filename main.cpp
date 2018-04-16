//CPEG676 Spring II 2018
//Charles Weissman - cweissma@udel.edu
//Assignment 1 - Minesweeper
//Due April 2018

#include <string>
#include <iostream>
#include <iomanip>
//#include <vector>
using namespace std;

//************************************
//********* Declaration **************
//************************************

//--Functions
int GetBoardSize(int x);
int SetupBoard(int BoardSize);
int OutputBoard(int BoardSize);

//--Variables
int BoardSize = 1;
int Board[10][10];

//************************************
//************ Main ******************
//************************************

int main() {
    BoardSize = GetBoardSize(BoardSize);
    SetupBoard(BoardSize);
    OutputBoard(BoardSize);
    cout << "back to main" << endl;
}

//************************************
//************ Functions *************
//************************************

int GetBoardSize(int x) {
    cout << "Please Enter Board Size";
    cin >> x;
    return x;
}

int SetupBoard(int x) {
    int iterator = 1;
    for (int i = 1; i <= x; i++){
        for (int j = 1; j <= x; j++){
            Board[i][j] = iterator;
            cout << "Inner Loop:--:" << i  << " and " << j << " value= " << Board[i][j] << endl ;
            iterator = iterator + 1;
        }
    }
    return 0;
}

int OutputBoard(int y) {
    cout << endl << "OutputBoard:" << endl ;
    int kmax = y,lmax = y;
    for (int k = 1; k <= kmax; k++){
        for (int l = 1; l <= lmax; l++){
            cout << setfill('0') << setw(2) << Board[k][l] << " - ";
        }
        cout << endl << endl;
        
    }
    return 0;
}
